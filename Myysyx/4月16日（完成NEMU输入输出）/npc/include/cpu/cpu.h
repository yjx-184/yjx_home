#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>

// typedef struct{
//     uint32_t pc;       // 当前指令地址
//     uint32_t snpc;     // 静态下一条指令地址 (pc + 4)
//     uint32_t dnpc;     // 动态下一条指令地址 
//     uint32_t inst;     // 当前指令
//     uint32_t gpr[32];  // gpr是通用寄存器组
// #if CONFIG_ITRACE
//     char logbuf[128];
// #endif
// } CPUState;

// extern CPUState cpu_state;

//执行CPU指令的函数声明
void cpu_exec(uint64_t n);          //参数n代表执行的指令数量

//设置NPC状态的函数声明
void set_npc_state(int state, uint32_t pc, int halt_ret);   //state表示NPC的状态，pc是当前程序计数器，halt_ret表示停止时的返回值。

// //处理无效指令的函数声明
// void invalid_inst(vaddr_t thispc);  //参数thispc表示当前无效指令的地址

// //定义NPC陷阱宏，用于触发NEMU的结束状态，并设置停止时的返回值和当前PC
// #define NEMUTRAP(thispc, code) set_npc_state(NPC_END, thispc, code)


#endif