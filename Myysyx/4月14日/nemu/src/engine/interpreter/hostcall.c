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

#include <utils.h>
#include <cpu/ifetch.h>
#include <isa.h>
#include <cpu/difftest.h>

// 设置 NEMU 模拟器的状态
// 参数:
//   state: 模拟器的新状态
//   pc: 当前的程序计数器（PC）值
//   halt_ret: 终止时的返回值
void set_nemu_state(int state, vaddr_t pc, int halt_ret) {
  difftest_skip_ref();            // 跳过差异测试（用于调试）
  nemu_state.state = state;       // 设置模拟器的状态
  nemu_state.halt_pc = pc;        // 设置模拟器的 halt_pc
  nemu_state.halt_ret = halt_ret; // 设置模拟器的 halt_ret
}

// 处理无效指令的异常!!!!!
// 参数:
//   thispc: 当前指令的程序计数器（PC）值
__attribute__((noinline))             // 禁止编译器内联该函数
void invalid_inst(vaddr_t thispc) {
  uint32_t temp[2];                   // 用于存储从内存中读取的两条指令
  vaddr_t pc = thispc;                // 将传入的 PC 地址赋给局部变量 pc
  temp[0] = inst_fetch(&pc, 4);       // 从 PC 位置读取 4 字节的指令
  temp[1] = inst_fetch(&pc, 4);       // 再次从 PC 位置读取 4 字节的指令（可能是错误的）

  uint8_t *p = (uint8_t *)temp;       // 将指令转换为字节数组，以便打印
  printf("invalid opcode(PC = " FMT_WORD "):\n"
      "\t%02x %02x %02x %02x %02x %02x %02x %02x ...\n"
      "\t%08x %08x...\n",
      thispc, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], temp[0], temp[1]);

  // 打印无效指令的可能原因
  // “有两种情况会触发这个意外异常：”
  // “1. PC = " FMT_WORD " 处的指令未实现。”
  // "2. 某些实现存在错误。"
  printf("There are two cases which will trigger this unexpected exception:\n"
      "1. The instruction at PC = " FMT_WORD " is not implemented.\n"
      "2. Something is implemented incorrectly.\n", thispc);
  // "在反汇编结果中找到这个 PC(" FMT_WORD ")，以区分是哪种情况。"
  printf("Find this PC(" FMT_WORD ") in the disassembling result to distinguish which case it is.\n\n", thispc);
  
   // 打印调试建议，帮助开发者定位问题
   // "如果是第一种情况，请参阅\n%s\n获取更多细节。\n\n"
   // "如果是第二种情况，请记住："
   // "机器永远是对的！"
   // "每一行未经测试的代码总是错误的！"
  printf(ANSI_FMT("If it is the first case, see\n%s\nfor more details.\n\n"
        "If it is the second case, remember:\n"
        "* The machine is always right!\n"
        "* Every line of untested code is always wrong!\n\n", ANSI_FG_RED), isa_logo);
  
  // 设置模拟器状态为终止状态（NEMU_ABORT），并传递当前的 PC 地址和错误代码 -1
  set_nemu_state(NEMU_ABORT, thispc, -1);
}
