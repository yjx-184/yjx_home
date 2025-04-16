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

#include <isa.h>
#include "local-include/reg.h"


/*寄存器名称数组，映射RISC-V架构的寄存器编号到寄存器名称
 *数组中的每个元素代表一个寄存器的名称，$0为零寄存器，ra是返回地址寄存器，
 *sp是栈指针，gp是全局指针，tp是线程指针，t0-t6是临时寄存器，s0-s11是保存寄存器，
 *a0-a7是参数寄存器，t3-t6是额外的临时寄存器。
 */
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

//-------为了方便调试查看，在这里给一个初始值（后续要记得删除！！！！）-------
// word_t initial_values[32] = {
//   0x0, 0x1000, 0x2000, 0x3000, 0x4000, 0x5000, 0x6000, 0x7000,
//   0x8000, 0x9000, 0xa000, 0xb000, 0xc000, 0xd000, 0xe000, 0xf000,
//   0x10000, 0x11000, 0x12000, 0x13000, 0x14000, 0x15000, 0x16000, 0x17000,
//   0x18000, 0x19000, 0x1a000, 0x1b000, 0x1c000, 0x1d000, 0x1e000, 0x1f000
// };
// void init_registers() {
//   for (int i = 0; i < 32; i++) {
//     cpu.gpr[i] = initial_values[i];  // 将每个寄存器的值初始化为对应的初始值
//   }
// }
//-----------------------------------------------------------------

//isa_reg_display函数用于显示所有寄存器的值
void isa_reg_display() {
  //init_registers(); //给一个初始值，后续可能需要删除，于pa1_3_1建立
  for(int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {     //遍历并打印每个寄存器的值
    printf("%-3s = 0x%08x\n", regs[i], cpu.gpr[i]);
  }
  printf("%-3s = 0x%08x\n", "pc",cpu.pc);  //打印pc的值
}

//is_reg_str2val函数将寄存器的名称则输出该寄存器的值
word_t isa_reg_str2val(const char *s, bool *success) {
  //init_registers(); //给一个初始值，后续可能需要删除，于pa1_3_1建立

  // 处理pc
  if (strcmp(s, "$pc") == 0) {
        *success = true;
        return cpu.pc;  // 读取 PC 的值
    }

  //处理0寄存器
  if (strcmp(s, "$0") == 0) {
    *success = true;
    return cpu.gpr[0];
  } else {
    s++;
    for(int i = 1; i < (MUXDEF(CONFIG_RVE, 16, 32)); i++) {     //遍历每个寄存器,跳过0寄存器
    if (strcmp(s, regs[i]) == 0) {  //找到对应寄存器的名称，返回寄存器的值
      *success = true;
      return cpu.gpr[i];
    }
  }
  }
  
  //没有找到匹配的寄存器名称，返回失败
  *success = false;
  return 0;
}
