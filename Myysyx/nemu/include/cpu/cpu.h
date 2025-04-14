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

#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>

//执行CPU指令的函数声明
void cpu_exec(uint64_t n);          //参数n代表执行的指令数量

//设置NEMU状态的函数声明
void set_nemu_state(int state, vaddr_t pc, int halt_ret);   //state表示NEMU的状态，pc是当前程序计数器，halt_ret表示停止时的返回值。

//处理无效指令的函数声明
void invalid_inst(vaddr_t thispc);  //参数thispc表示当前无效指令的地址

//定义NEMU陷阱宏，用于触发NEMU的结束状态，并设置停止时的返回值和当前PC
#define NEMUTRAP(thispc, code) set_nemu_state(NEMU_END, thispc, code)

//定义无效指令宏，用于触发无效指令处理函数
#define INV(thispc) invalid_inst(thispc)

#endif
