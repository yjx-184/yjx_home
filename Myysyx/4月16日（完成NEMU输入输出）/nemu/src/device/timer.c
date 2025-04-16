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

#include <device/map.h>
#include <device/alarm.h>
#include <utils.h>

// RTC（实时时钟）寄存器基地址（通过 new_space 分配的空间）
static uint32_t *rtc_port_base = NULL;

// RTC 的 IO 访问处理函数
static void rtc_io_handler(uint32_t offset, int len, bool is_write) {
  assert(offset == 0 || offset == 4); // 只能访问偏移地址为 0 或 4 的寄存器
  if (!is_write && offset == 4) {     // 如果是读取操作，且偏移是4（高32位）
    uint64_t us = get_time();         // 获取当前时间（单位：微秒）
    rtc_port_base[0] = (uint32_t)us;  // 低32位写入偏移0处
    rtc_port_base[1] = us >> 32;      // 高32位写入偏移4处
  }
}

#ifndef CONFIG_TARGET_AM
// 如果不是 AM 平台，定义定时中断处理函数
static void timer_intr() {
  // 只有当 NEMU 正在运行时才触发中断
  if (nemu_state.state == NEMU_RUNNING) {
    extern void dev_raise_intr();     // 外部中断触发函数
    dev_raise_intr();                 // 触发中断，通知 CPU 有外设事件
  }
}
#endif

// 初始化 RTC 定时器设备
void init_timer() {
  rtc_port_base = (uint32_t *)new_space(8);// 分配 8 字节空间作为 RTC 寄存器映射（低32位 + 高32位）
#ifdef CONFIG_HAS_PORT_IO
  // 如果支持端口IO，则以 PIO（端口映射）方式注册设备
  add_pio_map ("rtc", CONFIG_RTC_PORT, rtc_port_base, 8, rtc_io_handler);
#else
  // 否则以 MMIO（内存映射）方式注册设备
  add_mmio_map("rtc", CONFIG_RTC_MMIO, rtc_port_base, 8, rtc_io_handler);
#endif
  // 如果不是 AM 平台，为定时器添加 alarm 回调处理函数（定期触发 timer_intr）
  IFNDEF(CONFIG_TARGET_AM, add_alarm_handle(timer_intr));
}
