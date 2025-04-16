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
#include <memory/paddr.h>

// 这个数组与 uint8_t 类型不一致，
// 但由于我们不会直接访问这个数组，所以没问题
static const uint32_t img [] = {
  0x00000297,  // auipc t0,0                  -- 将当前PC值加上偏移量0，并存储到t0寄存器
  0x00028823,  // sb  zero,16(t0)             -- 将零寄存器的值（0）存入t0+16地址的内存
  0x0102c503,  // lbu a0,16(t0)               -- 从t0+16地址读取一个字节并存入a0寄存器
  0x00100073,  // ebreak (used as nemu_trap)  -- 触发异常，通常用于调试或设置断点
  0xdeadbeef,  // some data                   -- 一些数据
};

static void restart() {
  /* 设置初始的程序计数器（PC）。 */
  cpu.pc = RESET_VECTOR;

  /* 零寄存器（x0）的值始终是0。 */
  cpu.gpr[0] = 0;
}

void init_isa() {
  /* 加载内置程序映像。 */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* 初始化虚拟计算机系统。 */
  restart();
}
