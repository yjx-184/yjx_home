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
#include <utils.h>
#include <device/alarm.h>
#ifndef CONFIG_TARGET_AM      
#include <SDL2/SDL.h>     // 如果不是AM平台，引入SDL库用于图形和输入处理
#endif

// 设备初始化函数声明
void init_map();            // 初始化内存映射
void init_serial();         // 初始化串口设备
void init_timer();          // 初始化定时器设备
void init_vga();            // 初始化VGA显示设备
void init_i8042();          // 初始化键盘控制器(i8042)
void init_audio();          // 初始化音频设备
void init_disk();           // 初始化磁盘设备
void init_sdcard();         // 初始化SD卡设备
void init_alarm();          // 初始化闹钟设备

// 设备功能函数声明
void send_key(uint8_t, bool);  // 发送键盘事件
void vga_update_screen();      // 更新VGA屏幕显示

/* 设备状态更新函数 */
void device_update() {
  static uint64_t last = 0;    // 记录上次更新时间
  uint64_t now = get_time();   // 获取当前时间(微秒)

  // 控制更新频率不超过TIMER_HZ
  if (now - last < 1000000 / TIMER_HZ) {
    return;
  }
  last = now;                 // 更新最后处理时间

  IFDEF(CONFIG_HAS_VGA, vga_update_screen()); // 如果有VGA设备配置，更新屏幕

// 非AM平台处理SDL事件
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  // 处理所有pending的SDL事件
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:                  // 窗口关闭事件
        nemu_state.state = NEMU_QUIT; // 设置模拟器状态为退出
        break;
// 如果配置了键盘支持
#ifdef CONFIG_HAS_KEYBOARD
      // If a key was pressed
      // 键盘按下/释放事件
      case SDL_KEYDOWN:
      case SDL_KEYUP: {
        uint8_t k = event.key.keysym.scancode;              // 获取扫描码
        bool is_keydown = (event.key.type == SDL_KEYDOWN);  // 判断是按下还是释放
        send_key(k, is_keydown);                            // 发送键盘事件到模拟器
        break;
      }
#endif
      default: break;                                       // 忽略其他事件
    }
  }
#endif
}

/* 清空SDL事件队列 */
void sdl_clear_event_queue() {
// 非AM平台才需要处理
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event));                            // 循环取出所有事件但不处理
#endif
}

/* 初始化所有设备 */
void init_device() {
  IFDEF(CONFIG_TARGET_AM, ioe_init());                      // AM平台特殊初始化
  init_map();                                               // 调用init_map()进行初始化.

  // 条件初始化各种设备
  IFDEF(CONFIG_HAS_SERIAL, init_serial());                  // 串口
  IFDEF(CONFIG_HAS_TIMER, init_timer());                    // 定时器
  IFDEF(CONFIG_HAS_VGA, init_vga());                        // VGA显示
  IFDEF(CONFIG_HAS_KEYBOARD, init_i8042());                 // 键盘控制器
  IFDEF(CONFIG_HAS_AUDIO, init_audio());                    // 音频设备
  IFDEF(CONFIG_HAS_DISK, init_disk());                      // 磁盘设备
  IFDEF(CONFIG_HAS_SDCARD, init_sdcard());                  // SD卡设备

  // 非AM平台初始化闹钟
  IFNDEF(CONFIG_TARGET_AM, init_alarm());
}
