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

#ifndef __RISCV_REG_H__
#define __RISCV_REG_H__

#include <common.h>

//检查寄存器索引是否有效的内链函数
static inline int check_reg_idx(int idx) {
  //如果定义了 CONFIG_RT_CHECK，则使用 assert 检查索引是否在有效范围内
  //有效范围由 MUXDEF 宏决定：如果定义了 CONFIG_RVE，则范围为 0-15，否则为 0-31
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
  return idx; //返回检查后的索引
}

//获取通用寄存器值的宏
#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])  //使用check_reg_idx 检查索引有效值，然后返回cpu.gpr数组中对应的索引值

//获取寄存器名称的内链函数
static inline const char* reg_name(int idx) {
  extern const char* regs[];        //声明外部寄存器名称数组
  return regs[check_reg_idx(idx)];  //返回对应索引的寄存器名称
}

#endif
