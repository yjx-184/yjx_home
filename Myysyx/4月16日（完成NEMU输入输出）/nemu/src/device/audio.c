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

#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>

enum {
  reg_freq,        // 采样频率（Hz）
  reg_channels,    // 声道数（1 单声道，2 立体声）
  reg_samples,     // 每次发送的数据长度（以采样点为单位）
  reg_sbuf_size,   // 声音缓冲区大小（单位：字节）
  reg_init,        // 初始化标志位（1 表示开始播放）
  reg_count,       // 当前已播放的字节数（用于主控轮询播放进度）
  nr_reg           // 寄存器总数（用于计算空间大小）
};

static uint8_t *sbuf = NULL;            // 声音缓冲区指针（软件模拟的显存，用于存储音频数据）
static uint32_t *audio_base = NULL;     // 音频控制寄存器基地址（用于模拟寄存器数组）

// 音频 IO 处理函数
// offset: 寄存器偏移, len: 访问的字节长度, is_write: 是否是写操作（true 写，false 读）
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
}

// 初始化音频设备模拟
void init_audio() {
  // 分配音频控制寄存器空间（每个寄存器占 4 字节）
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size); // 在模拟器中申请连续内存空间
// 根据是否启用 PIO（端口映射）决定添加 PIO 或 MMIO（内存映射）设备
#ifdef CONFIG_HAS_PORT_IO
  // 使用端口映射方式添加音频控制器
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  // 使用内存映射方式添加音频控制器
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif
  // 分配并映射声音缓冲区（用于存储将要播放的音频数据）
  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
