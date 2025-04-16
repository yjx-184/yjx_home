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

#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

/* 定义了一个结构体，用于表示RISC-V CPU 的状态 */
typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)]; //gpr是通用寄存器组，大小由MUXDEF宏决定。
  vaddr_t pc;                             //程序计数器，存储当前指令的地址。
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);//条件编译宏，根据配置选择不同的实现。

// decode
//定义指令解码信息结构体
typedef struct {
  uint32_t inst;  //存储当前指令的二进制编码
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);//根据配置选择

//定义内存管理单元MMU检查函数
//这里直接返回 MMU_DIRECT，表示直接访问物理内存，不经过 MMU 的地址转换
#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif
