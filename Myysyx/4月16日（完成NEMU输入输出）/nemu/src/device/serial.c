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
#include <device/map.h>

/* http://en.wikibooks.org/wiki/Serial_Programming/8250_UART_Programming */
// NOTE: this is compatible to 16550
/* 
 * 串口设备参考：http://en.wikibooks.org/wiki/Serial_Programming/8250_UART_Programming
 * 本代码兼容 16550 UART（常见的串口控制器型号）
 */

// 串口寄存器偏移地址定义
#define CH_OFFSET 0  // 数据寄存器偏移（只用了一个寄存器）

// 指向串口寄存器的基地址指针
static uint8_t *serial_base = NULL;

/**
 * 向宿主机输出一个字符
 * 
 * - 如果在 AM 环境下（如 NEMU 中运行 AM 应用），调用 putch 输出字符到 stderr；
 * - 否则（如在普通主机程序中）使用 C 标准库的 putc 函数。
 */
static void serial_putc(char ch) {
  MUXDEF(CONFIG_TARGET_AM, putch(ch), putc(ch, stderr));
}

/**
 * 串口的 I/O 处理函数，用于 MMIO 或 PIO 映射
 * 
 * offset 寄存器偏移地址（只支持写入 CH_OFFSET = 0）
 * len    读写长度，必须为 1 字节
 * is_write 是否为写操作（true 表示写操作，false 表示读操作）
 */
static void serial_io_handler(uint32_t offset, int len, bool is_write) {
  assert(len == 1);                                         // 串口只支持按字节访问
  switch (offset) {
    /* We bind the serial port with the host stderr in NEMU. */
    /* 我们在 NEMU 中将串口与主机 stderr 绑定。 */
    case CH_OFFSET:                                         // 只处理写操作
      if (is_write) serial_putc(serial_base[0]);            // 输出写入的字符
      else panic("do not support read");                    // 串口不支持读操作
      break;
    default: panic("do not support offset = %d", offset);   // 不支持的寄存器偏移
  }
}

/**
 * 初始化串口设备
 * 
 * - 在内存中申请串口寄存器空间（8字节）
 * - 根据是否支持端口IO或MMIO，添加 I/O 映射
 */
void init_serial() {
  serial_base = new_space(8); // 申请一段内存，模拟串口寄存器
#ifdef CONFIG_HAS_PORT_IO
  // 如果目标平台支持 PIO（端口映射IO），注册为 PIO 设备
  add_pio_map ("serial", CONFIG_SERIAL_PORT, serial_base, 8, serial_io_handler);
#else
  // 否则注册为 MMIO（内存映射IO）设备
  add_mmio_map("serial", CONFIG_SERIAL_MMIO, serial_base, 8, serial_io_handler);
#endif

}
