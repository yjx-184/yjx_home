#include <cpu/cpu.h>
// #include <cpu/difftest.h>
#include <locale.h>
#include "isa.h"
#include <cpu/decode.h>
#include "../monitor/sdb/sdb.h"
#include <cpu/difftest.h>
#include "memory/paddr.h"
#include <svdpi.h>
#include <vpi_user.h>


/* 当执行的指令数量小于该值时，才会在屏幕上输出指令的汇编代码。
 * 这对于使用 `si`（单步执行）命令时很有用。
 * 可以根据需要修改该值。
 */
#define MAX_INST_TO_PRINT 10
CPU_state cpu = {};               //定义CPU结构体，存储CPU的状态
uint32_t curr_pc = 0x80000000;    //存储CPU的上一个PC
uint64_t g_nr_guest_inst = 0;     //记录执行的访客指令数量
static uint64_t g_timer = 0;      //记录CPU执行的时间，单位为微秒us
static bool g_print_step = false; //是否在单步模式下打印命令

#define IRINGBUF_SIZE 16          // 环形缓冲区容量，可根据需要调整

// 环形缓冲区结构
typedef struct {
  uint32_t pc;
  char disasm[128];               // 反汇编后的字符串
  bool valid;
} ItraceEntry;

// 定义环形缓冲区
static ItraceEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_index = 0;    // 记录当前写入位置
static uint32_t error_pc = 0;      // 全局变量，记录出错指令的pc

/* 进行指令追踪和DiffTest (指令级对比测试) */
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
// #if CONFIG_ITRACE
//     // if (g_print_step) { 
//         puts(_this->logbuf);  // 若需要打印指令，则输出  
//     // }
// #endif

#if CONFIG_DIFFTEST
    difftest_step(_this->pc, dnpc);  // 执行 DiffTest 比对
#endif

#if CONFIG_WATCHPOINT
    check_wp();  // 执行 Watchpoint 检查
#endif
}

/* 向环形缓冲区写入一条指令的执行信息 */
void iringbuf_write(uint32_t pc, const char *disasm) {
    // 将指令信息写入当前索引位置
    iringbuf[iringbuf_index].pc = pc;
    snprintf(iringbuf[iringbuf_index].disasm, sizeof(iringbuf[iringbuf_index].disasm), "%s", disasm);

    // 更新索引，环形缓冲区满了就覆盖最旧的数据
    iringbuf[iringbuf_index].valid = true;
    iringbuf_index = (iringbuf_index + 1) % IRINGBUF_SIZE;
}

/* 读取并打印环形缓冲区中的指令信息 */
void iringbuf_read() {
  #if CONFIG_CN
  printf("指令执行记录（最近 %d 条）:\n", IRINGBUF_SIZE);
  #else
  printf("Instruction execution trace (last %d entries):\n", IRINGBUF_SIZE);
  #endif

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

static inline void tran_regs(int regs_0, int regs_1, int regs_2, int regs_3, 
                             int regs_4, int regs_5, int regs_6, int regs_7, 
                             int regs_8, int regs_9, int regs_10, int regs_11, 
                             int regs_12, int regs_13, int regs_14, int regs_15)  
{
    cpu.gpr[0] = regs_0;
    cpu.gpr[1] = regs_1;
    cpu.gpr[2] = regs_2;
    cpu.gpr[3] = regs_3;
    cpu.gpr[4] = regs_4;
    cpu.gpr[5] = regs_5;
    cpu.gpr[6] = regs_6;
    cpu.gpr[7] = regs_7;
    cpu.gpr[8] = regs_8;
    cpu.gpr[9] = regs_9;
    cpu.gpr[10] = regs_10;
    cpu.gpr[11] = regs_11;
    cpu.gpr[12] = regs_12;
    cpu.gpr[13] = regs_13;
    cpu.gpr[14] = regs_14;
    cpu.gpr[15] = regs_15;
    return;
}


extern "C" void get_regs(int regs_0, int regs_1, int regs_2, int regs_3, 
                         int regs_4, int regs_5, int regs_6, int regs_7, 
                         int regs_8, int regs_9, int regs_10, int regs_11, 
                         int regs_12, int regs_13, int regs_14, int regs_15) 
    {
        tran_regs(regs_0, regs_1, regs_2, regs_3, 
                  regs_4, regs_5, regs_6, regs_7, 
                  regs_8, regs_9, regs_10, regs_11, 
                  regs_12, regs_13, regs_14, regs_15);
        return;
    }

// 单步执行函数
static int exec_once(Decode *s, paddr_t pc) {
    
    s->pc = pc;         //设置当前指令的PC
    s->snpc = pc;       //设置下一条指令的PC
    
    if (!simulation_initialized || hit_good_trap || Verilated::gotFinish()) {
        return 1;
    }
    

    // 时钟上升沿
    clk = true;
    top->clock = clk;
    top->eval();

    s->isa.inst = paddr_read(s->pc, 4);
    s->snpc = s->pc + 4;
    s->dnpc = top->io_nextPC;

    // // 提取寄存器组的值
    // cpu.gpr[0] = top->io_regs_0;
    // cpu.gpr[1] = top->io_regs_1;
    // cpu.gpr[2] = top->io_regs_2;
    // cpu.gpr[3] = top->io_regs_3;
    // cpu.gpr[4] = top->io_regs_4;
    // cpu.gpr[5] = top->io_regs_5;
    // cpu.gpr[6] = top->io_regs_6;
    // cpu.gpr[7] = top->io_regs_7;
    // cpu.gpr[8] = top->io_regs_8;
    // cpu.gpr[9] = top->io_regs_9;
    // cpu.gpr[10] = top->io_regs_10;
    // cpu.gpr[11] = top->io_regs_11;
    // cpu.gpr[12] = top->io_regs_12;
    // cpu.gpr[13] = top->io_regs_13;
    // cpu.gpr[14] = top->io_regs_14;
    // cpu.gpr[15] = top->io_regs_15;
    tfp->dump(sim_time++);

    // 时钟下降沿
    clk = false;
    top->clock = clk;
    top->eval();
    tfp->dump(sim_time++);

#if CONFIG_ITRACE
    char *p = s->logbuf;
    p += snprintf(p, sizeof(s->logbuf), "0x%08x" ":", s->pc); //记录PC值
    int ilen = s->snpc - s->pc;
    int i;
    uint8_t *inst = (uint8_t *)&s->isa.inst;
    for (i = ilen - 1; i >= 0; i --) {
        p += snprintf(p, 4, " %02x", inst[i]);  //将每个字节以十六进制形式写入日志
    }
    int ilen_max = 4;
    int space_len = ilen_max -ilen;
    if (space_len < 0) space_len = 0;
    space_len = space_len * 3 + 1;
    memset(p, ' ', space_len);                  //填充空格
    p += space_len;

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
                cpu.pc, (uint8_t *)&s->isa.inst, ilen);
    #if CONFIG_ITRACE
    // if (g_print_step) { 
        puts(s->logbuf);  // 若需要打印指令，则输出  
    // }
#endif
    iringbuf_write(s->pc,s->logbuf); // 将信息写入环形缓冲区
#endif
    // 检查终止条件
    if (s->isa.inst == 0x00100073) { // ebreak
        hit_good_trap = true;
        // printf(ANSI_FMT("HIT GOOD TRAP (EBREAK)", ANSI_FG_GREEN) " at PC 0x%08x\n", cpu_state.pc);
        dpi_end_simulation();
        npc_state.state = NPC_END;  // 设置状态
        npc_state.halt_pc = s->snpc;
        npc_state.halt_ret = 0;
    }

    return 0;
}

/* 执行n条指令 | 模拟CPU的工作方式：不断执行指令 */
static void execute(uint64_t n) {
    Decode s;
    int count = 0;
    for (; n > 0; n--) {
        curr_pc = cpu.pc;      //保存当前PC
        // exec_once(&s, cpu.pc);

        exec_once(&s, curr_pc);
        
        g_nr_guest_inst ++;                           //增加已执行指令的计数
#if CONFIG_FTRACE
        ftrace_check(&s);                             //添加 ftrace 检查
#endif
        // trace_and_difftest(&s, cpu.pc);
        if (count > 0) {
            trace_and_difftest(&s, curr_pc);  // 从第二条指令开始才执行
        }
        cpu.pc = s.dnpc;                              //更新PC为执行后的新值
        if (npc_state.state != NPC_RUNNING) break;
        count++;
    }
}

/* 统计并输出仿真结果 */
static void statistic() {
    #if CONFIG_CN
    Log("主机耗时 = %ld 微秒", g_timer);
    Log("客户机(guest)执行的总指令数 = %ld", g_nr_guest_inst);
    if (g_timer > 0) 
    Log("仿真频率 = %ld 指令/秒\n", g_nr_guest_inst * 1000000 / g_timer);  // 计算并输出仿真频率
    else Log("仿真运行时间不足 1 微秒，无法计算仿真频率\n");  // 如果时间过短，无法计算仿真频率
    #else
    Log("host time spent = %ld us ", g_timer);
    Log("total guest instructions = %ld ", g_nr_guest_inst);
    if (g_timer > 0) Log("simulation frequency =  %ld  inst/s \n", g_nr_guest_inst * 1000000 / g_timer);  //计算并输出仿真频率
    else Log("Finish running in less than 1 us and can not calculate the simulation frequency \n");  //如果时间过短，无法计算仿真频率
    #endif

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
    switch (npc_state.state) {
        case NPC_END: case NPC_ABORT: case NPC_QUIT:
            //如果CPU状态为结束、中止或退出，则提示用户程序已结束
            printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
            return;
        default: npc_state.state = NPC_RUNNING;
    }
    uint64_t timer_start = get_time();          //记录仿真开始时间

    execute(n);                                 //执行n条指令

    uint64_t timer_end = get_time();            //记录仿真结束时间
    g_timer += timer_end - timer_start;         //累加仿真时间

    switch (npc_state.state) {
        case NPC_RUNNING: npc_state.state = NPC_STOP; break;

        case NPC_END: case NPC_ABORT:
            // 仅在 ABORT 或 BAD TRAP 时记录 error_pc
            if (npc_state.state == NPC_ABORT || npc_state.halt_ret != 0) {
                error_pc = npc_state.halt_pc;
            }
        Log("npc: %s at pc = 0x%08x \n", 
                (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
                (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
                npc_state.halt_pc);
        case NPC_QUIT: statistic();
    }
}
