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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

//实现监视点时添加
#include "../monitor/sdb/sdb.h"


/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */

/* 当执行的指令数量小于该值时，才会在屏幕上输出指令的汇编代码。
 * 这对于使用 `si`（单步执行）命令时很有用。
 * 可以根据需要修改该值。
 */
#define MAX_INST_TO_PRINT 10

#define IRINGBUF_SIZE 16          // 环形缓冲区容量，可根据需要调整

// 环形缓冲区结构
typedef struct {
  vaddr_t pc;
  char disasm[128];               // 反汇编后的字符串
  bool valid;
} ItraceEntry;

// // ftrace的栈(已经移入inst.c)
// typedef struct CallStack {
//   uint32_t addr;                  // 返回地址
//   char *func_name;                // 函数名称
//   struct CallStack *next;
// } CallStack;

// static CallStack *call_stack = NULL;  // 栈顶
// static int call_depth = 0;            // 记录嵌套深度


// 定义环形缓冲区
static ItraceEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_index = 0;    // 记录当前写入位置
static vaddr_t error_pc = 0;      // 全局变量，记录出错指令的pc

CPU_state cpu = {};               //定义CPU结构体，存储CPU的状态
uint64_t g_nr_guest_inst = 0;     //记录执行的访客指令数量
static uint64_t g_timer = 0;      //记录CPU执行的时间，单位为微秒us
static bool g_print_step = false; //是否在单步模式下打印命令

void device_update();             //设备更新函数，可能用于I/O设备仿真

/* 进行指令追踪和DiffTest (指令级对比测试) */
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }  //启用指令跟踪，则记录日志
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }  //若需要打印指令，则输出  
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc)); //执行DiffTest比对

  //检查监视点是否触发
  IFDEF(CONFIG_WATCHPOINT, check_wp());
}

/* 向环形缓冲区写入一条指令的执行信息 */
void iringbuf_write(vaddr_t pc, const char *disasm) {
  // 将指令信息写入当前索引位置
  iringbuf[iringbuf_index].pc = pc;
  snprintf(iringbuf[iringbuf_index].disasm, sizeof(iringbuf[iringbuf_index].disasm), "%s", disasm);
  
  // 更新索引，环形缓冲区满了就覆盖最旧的数据
  iringbuf[iringbuf_index].valid = true;
  iringbuf_index = (iringbuf_index + 1) % IRINGBUF_SIZE;

}

/* 读取并打印环形缓冲区中的指令信息 */
void iringbuf_read() {
  printf("指令执行记录（最近 %d 条）:\n", IRINGBUF_SIZE);
  for (int i = IRINGBUF_SIZE - 1; i >= 0; i--) {
    int idx = (iringbuf_index - 1 - i + IRINGBUF_SIZE) % IRINGBUF_SIZE;
    if (iringbuf[idx].valid) {
      // 检查是否是出错指令
      if (iringbuf[idx].pc == error_pc) {
        printf("--> ");
      } else {
        printf("    ");
      }
      printf("%s\n", iringbuf[idx].disasm);
    }
  }
}

/* 执行单条指令 | CPU执行当前PC指向的一条指令, 然后更新PC*/
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;         //设置当前指令的PC
  s->snpc = pc;       //设置下一条指令的PC
  isa_exec_once(s);   //解析并执行该指令
  cpu.pc = s->dnpc;   //更新CPU的PC（下一条指令地址）
#if CONFIG_ITRACE  //如果启用了指令追踪，则指令的二进制码和反汇编结果记录到日至缓冲区
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc); //记录PC值
  int ilen = s->snpc - s->pc;                               //计算指令长度
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;                  //获取指令的二进制码
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {             //对于x86架构，按顺序打印指令的二进制码
#else
  for (i = ilen - 1; i >= 0; i --) {        //对于其他架构，按逆序打印指令的二进制码
#endif
    p += snprintf(p, 4, " %02x", inst[i]);  //将每个字节以十六进制形式写入日志
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);//根据架构确定最大指令长度
  int space_len = ilen_max - ilen;            //计算需要填充的空格长度
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;              //计算总空格长度（每个字节占3个字符）
  memset(p, ' ', space_len);                  //填充空格
  p += space_len;

  //调用反汇编函数，将指令的反汇编结果写入日志缓冲区
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);

  iringbuf_write(s->pc,s->logbuf); // 将信息写入环形缓冲区
#endif
}

/* 执行n条指令 | 模拟CPU的工作方式：不断执行指令 */
static void execute(uint64_t n) {
  Decode s;                                       //定义解码结构体，用于存储指令信息
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);                        //执行单条指令
    g_nr_guest_inst ++;                           //增加已执行指令的计数
#if CONFIG_FTRACE
    ftrace_check(&s);                             //添加 ftrace 检查
#endif
    // printf("执行后:s.pc = 0x%08x, s.isa.inst = 0x%08x, s.snpc = 0x%08x, s.dnpc = 0x%08x, cpu.pc = 0x%08x \n",
    //    s.pc, s.isa.inst, s.snpc, s.dnpc, cpu.pc);
    trace_and_difftest(&s, cpu.pc);               //进行指令追踪和DiffTest
    if (nemu_state.state != NEMU_RUNNING) break;  //如果CPU状态不是运行中，则退出循环
    IFDEF(CONFIG_DEVICE, device_update());        //如果启用了设备仿真，则更新设备状态
  }
}

/* 统计并输出仿真结果 */
static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));  //设置本地化数字格式
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);//输出仿真消耗时间
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst); //输出执行的指令总数
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);  //计算并输出仿真频率
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");  //如果时间过短，无法计算仿真频率

  // 如果发生错误，打印最近的指令
  if (error_pc != 0) {
    iringbuf_read();  // 只在出现错误时打印环形缓冲区中的指令
  }
}

/* 断言失败时显示信息 */
void assert_fail_msg() {
  isa_reg_display();//显示CPU寄存器的状态
  statistic();      //输出仿真统计信息
}

/* 控制CPU执行指定数量的指令 */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT); //如果执行的指令数量小于阈值，则启用单步打印模式
  error_pc = 0;                               // 重置出错pc
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      //如果CPU状态为结束、中止或退出，则提示用户程序已结束
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING; //否则将CPU状态设置为运行中
  }

  uint64_t timer_start = get_time();          //记录仿真开始时间

  execute(n);                                 //执行n条指令

  uint64_t timer_end = get_time();            //记录仿真结束时间
  g_timer += timer_end - timer_start;         //累加仿真时间

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break; //如果CPU仍在运行，则将其状态设置为停止

    case NEMU_END: case NEMU_ABORT:                         //如果CPU状态结束或中止，则输出相关信息
      // 仅在 ABORT 或 BAD TRAP 时记录 error_pc
      if (nemu_state.state == NEMU_ABORT || nemu_state.halt_ret != 0) {
        error_pc = nemu_state.halt_pc;
      }

      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();                            //如果CPU状态为退出，则输出仿真统计信息
                    free_elf_symbols(&elf_symtab);
                    break;
  }
}
