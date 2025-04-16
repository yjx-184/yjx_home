#include "isa.h"
#include <cpu/cpu.h>
#include "local-include/reg.h"
#include <cpu/decode.h>

// 定义宏，简化代码
#define R(i) gpr(i)       // 获取通用寄存器的值

// ftrace的栈
#if CONFIG_FTRACE
typedef struct CallStack {
  uint32_t addr;                  // 返回地址
  char *func_name;                // 函数名称
  struct CallStack *next;
} CallStack;

static CallStack *call_stack = NULL;  // 栈顶
static int call_depth = 0;            // 记录嵌套深度
#endif

// 定义指令类型的枚举
enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // 无类型
};
// 定义宏，用于解码操作数
#define src1R() do { *src1 = R(rs1); } while (0)  // 获取源寄存器1的值
#define src2R() do { *src2 = R(rs2); } while (0)  // 获取源寄存器2的值
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)  // 解码I类型立即数
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)  // 解码U类型立即数
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0) // 解码S类型立即数
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | \
                                (BITS(i, 30, 21) << 1) | \
                                (BITS(i, 20, 20) << 11) | \
                                (BITS(i, 19, 12) << 12); } while(0)  // 解码J类型立即数
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | \
                                (BITS(i, 30, 25) << 5) | \
                                (BITS(i, 11, 8) << 1) | \
                                (BITS(i, 7, 7) << 11); } while(0)


static void decode_operand(Decode *s,  int *rd, uint32_t *src1, uint32_t *src2, uint32_t *imm, int type) {
  uint32_t i = s->isa.inst;   // 获取指令
  int rs1 = BITS(i, 19, 16);  // 解码rs1
  int rs2 = BITS(i, 24, 21);  // 解码rs2
  *rd     = BITS(i, 11, 8);   // 解码rd
  switch (type) {
    case TYPE_R: src1R(); src2R();         break; // R类型指令
    case TYPE_I: src1R();          immI(); break; // I类型指令
    case TYPE_U:                   immU(); break; // U类型指令
    case TYPE_S: src1R(); src2R(); immS(); break; // S类型指令
    case TYPE_B: src1R(); src2R(); immB(); break; // B类型指令
    case TYPE_J:                   immJ(); break; // J类型指令
    case TYPE_N: break;                           // 无类型指令
    default:
    #if CONFIG_CN
      printf("遇到未支持的指令类型(type = %d)\n", type);
    #else
      printf("unsupported type = %d\n", type);
    #endif
    break;
  }
}



/************************ ftrace的实现部分 ************************************ */
/* 从ELF符号表中查找地址对应的函数名 */
const char *find_func_name(uint32_t addr) {
  for (ElfSymbolNode *node = elf_symtab.head; node != NULL; node = node->next) {
    if (node->addr == addr) {
      return node->name;
    }
  }
  #if CONFIG_CN
    return "未知函数：地址未匹配 (find_func_name())";
  #else
    return "UNKNOWN(find_func_name())";
  #endif
}

/* 处理call */
void handle_call(uint32_t pc, uint32_t target) {
#if CONFIG_FTRACE
  const char *func_name = find_func_name(target); // 寻找目标函数
  printf("0x%08x: %*s call [%s@0x%08x]\n", pc, call_depth, "", func_name, target);

  // 入栈
  CallStack *new_call = (CallStack *)malloc(sizeof(CallStack));
  new_call->addr = pc + 4;
  new_call->func_name = strdup(func_name);
  new_call->next = call_stack;
  call_stack = new_call;

  // 增加缩进深度
  call_depth++;
#endif
}

/* 处理ret */
void handle_ret(uint32_t pc) {
#if CONFIG_FTRACE
  if (call_stack == NULL) return;

  // 弹出栈顶
  CallStack *top = call_stack;
  call_stack = call_stack->next;
  call_depth--;

  printf("0x%08x: %*s ret  [%s]\n", pc, call_depth, "", top->func_name);
  free(top->func_name);
  free(top);
#endif
}
void ftrace_check() {
#if CONFIG_FTRACE
  uint32_t inst = s->isa.inst;           // 提取当前指令的二进制编码
  uint32_t opcode = inst & 0b01111111;   // 提取操作码

  int rd = 0;
  uint32_t src1 = 0, src2 = 0, imm = 0;

  switch (opcode) {
    case 0b1101111 :                  // jal
        {
          decode_operand(&rd, &src1, &src2, &imm, TYPE_J);
          handle_call(s->pc, s->dnpc);// cpu_state.npc 已经是跳转目标
          break;
        }
    case 0b1100111 :                  // jalr
        {
          decode_operand(&rd, &src1, &src2, &imm, TYPE_I);
          if (rd == 1) {            // jalr x1, xxx 说明是 call
            handle_call(s->pc, s->dnpc);
          } else if (rd == 0 && BITS(inst, 19, 16) == 1) { // jalr x0, 0(x1) 说明是 ret
            handle_ret(s->pc);
          } else if (rd == 0 && BITS(inst, 19, 16) == 6) { // jalr x0, offset(x6)
            handle_call(s->pc, s->dnpc);
          }
          break;
        }
  }
#endif
}