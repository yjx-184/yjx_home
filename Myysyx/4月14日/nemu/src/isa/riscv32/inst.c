/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

// 定义宏，简化代码
#define R(i) gpr(i)       // 获取通用寄存器的值
#define Mr vaddr_read     // 读取虚拟地址的值
#define Mw vaddr_write    // 写入虚拟地址的值

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
// 解码操作数函数
static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;   // 获取指令
  int rs1 = BITS(i, 19, 15);  // 解码rs1
  int rs2 = BITS(i, 24, 20);  // 解码rs2
  *rd     = BITS(i, 11, 7);   // 解码rd
  switch (type) {
    case TYPE_R: src1R(); src2R();         break; // R类型指令
    case TYPE_I: src1R();          immI(); break; // I类型指令
    case TYPE_U:                   immU(); break; // U类型指令
    case TYPE_S: src1R(); src2R(); immS(); break; // S类型指令
    case TYPE_B: src1R(); src2R(); immB(); break; // B类型指令
    case TYPE_J:                   immJ(); break; // J类型指令
    case TYPE_N: break;                           // 无类型指令
    default: panic("unsupported type = %d", type);// 不支持的类型
  }
}

// （译码阶段）解码并执行指令函数
static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;  // 设置下一条指令的PC

// 定义指令匹配宏
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}
  // 开始指令匹配
  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd) = s->pc + 4; s->dnpc = (src1 + imm) & (~1));
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = (int32_t)(int8_t)Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = (int32_t)(int16_t)Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = (uint32_t)Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = ((int32_t)src1 < (int32_t)imm) ? 1 : 0);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = ((uint32_t)src1 < (uint32_t)imm) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << (imm & 0x1F));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = (uint32_t)src1 >> (imm & 0x1F));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (int32_t)src1 >> (imm & 0x1F));
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);

  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));

  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm);
  
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) 是 $a0
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = (src1 < src2) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << (src2 & 0x1F));
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = ((int32_t)src1 < (int32_t)src2) ? 1 : 0);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = (int64_t)(int32_t)src1 * (int32_t)src2 >> 32);
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (src2 == 0) ? 0xFFFFFFFF : ((int32_t)src1 == INT32_MIN && (int32_t)src2 == -1) ? 0x80000000 : (int32_t)src1 / (int32_t)src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = (src2 == 0) ? 0xFFFFFFFF : (uint32_t)src1 / (uint32_t)src2);
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, R(rd) = (int64_t)(int32_t)src1 * (uint64_t)(uint32_t)src2 >> 32);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = (uint64_t)(uint32_t)src1 * (uint64_t)(uint32_t)src2 >> 32);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (src2 == 0) ? src1 : ((int32_t)src1 == INT32_MIN && (int32_t)src2 == -1) ? 0 : (int32_t)src1 % (int32_t)src2);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = (src2 == 0) ? src1 : (uint32_t)src1 % (uint32_t)src2);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (int32_t)src1 >> (src2 & 0x1F));
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = (uint32_t)src1 >> (src2 & 0x1F));

  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if (src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if (src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if ((int32_t)src1 < (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if ((int32_t)src1 >= (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if ((uint32_t)src1 >= (uint32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if ((uint32_t)src1 < (uint32_t)src2) s->dnpc = s->pc + imm);

  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // 重置$zero寄存器为0

  return 0;
}

// 执行一条指令的函数，调用inst_fetch()的时候传入了s->snpc的地址，
// 因此inst_fetch()最后还会根据len来更新s->snpc, 从而让s->snpc指向下一条指令.
int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);  // 获取下一条指令
  return decode_exec(s);                  // 解码并执行指令
}

/************************ ftrace的实现部分 ************************************ */
/* 从ELF符号表中查找地址对应的函数名 */
const char *find_func_name(uint32_t addr) {
  for (ElfSymbolNode *node = elf_symtab.head; node != NULL; node = node->next) {
    if (node->addr == addr) {
      return node->name;
    }
  }
  return "UNKNOWN(find_func_name())";
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
void ftrace_check(Decode *s) {
#if CONFIG_FTRACE
  uint32_t inst = s->isa.inst;        // 提取当前指令的二进制编码
  uint32_t opcode = inst & 0b01111111;// 提取操作码

  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;

  switch (opcode) {
    case 0b1101111 :                  // jal
        {
          decode_operand(s, &rd, &src1, &src2, &imm, TYPE_J);
          handle_call(s->pc, s->dnpc);// s->dnpc 已经是跳转目标
          break;
        }
    case 0b1100111 :                  // jalr
        {
          decode_operand(s, &rd, &src1, &src2, &imm, TYPE_I);
          if (rd == 1) {            // jalr x1, xxx 说明是 call
            handle_call(s->pc, s->dnpc);
          } else if (rd == 0 && BITS(inst, 19, 15) == 1) { // jalr x0, 0(x1) 说明是 ret
            handle_ret(s->pc);
          } else if (rd == 0 && BITS(inst, 19, 15) == 6) { // jalr x0, offset(x6)
            handle_call(s->pc, s->dnpc);
          }
          break;
        }
  }
#endif
}
