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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>


// 定义一个内存复制函数，参数为内存地址、缓冲区、长度和方向
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction) {
    memcpy(guest_to_host(addr), buf, n);
    } else {
    memcpy(buf, guest_to_host(addr), n);
    }
}

// 定义一个寄存器复制函数，参数为 DUT（设计验证单元）和方向
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_DUT) {
    // 从 cpu 复制到 dut
    for (int i = 0; i < RISCV_GPR_NUM; ++i) {
      ((word_t*)dut)[i] = cpu.gpr[i];
    }
    // 同步 PC
    ((word_t*)dut)[RISCV_GPR_NUM] = cpu.pc;

  } else {
    // 从 dut 复制到 cpu
    word_t *src = (word_t*)dut;
    for (int i = 0; i < RISCV_GPR_NUM; ++i) {
      cpu.gpr[i] = src[i];
    }
    // 同步 PC
    cpu.pc = src[RISCV_GPR_NUM];

  }
  
}

// 定义一个执行函数，参数为执行次数
__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

// 定义一个空的中断处理函数，参数为中断号
__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

// 初始化函数，初始化内存和 ISA（指令集架构）
__EXPORT void difftest_init(int port) {
  void init_mem();  // 声明初始化内存的函数
  init_mem();       // 调用初始化内存函数
  /* Perform ISA dependent initialization. */
  /* 执行 ISA 相关的初始化。 */
  init_isa();       // 调用 ISA 初始化函数
}
