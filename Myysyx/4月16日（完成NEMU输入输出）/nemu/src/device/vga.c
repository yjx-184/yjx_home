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

// 定义屏幕宽度和高度
#define SCREEN_W (MUXDEF(CONFIG_VGA_SIZE_800x600, 800, 400))
#define SCREEN_H (MUXDEF(CONFIG_VGA_SIZE_800x600, 600, 300))

// 获取当前屏幕宽度。如果是 AM 平台，就读取设备信息，否则使用默认值）
static uint32_t screen_width() {
  return MUXDEF(CONFIG_TARGET_AM, io_read(AM_GPU_CONFIG).width, SCREEN_W);
}

// 获取当前屏幕高度。
static uint32_t screen_height() {
  return MUXDEF(CONFIG_TARGET_AM, io_read(AM_GPU_CONFIG).height, SCREEN_H);
}

// 获取整个屏幕显存大小
static uint32_t screen_size() {
  return screen_width() * screen_height() * sizeof(uint32_t);
}

// vmem 是显存虚拟地址，vgactl_port_base 是 VGA 控制端口基地址
static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;

#ifdef CONFIG_VGA_SHOW_SCREEN
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h> // 如果不是 AM 平台，使用 SDL 库实现图形显示

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

// 初始化 SDL 屏幕窗口
static void init_screen() {
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "%s-NEMU", str(__GUEST_ISA__));  // 设置窗口标题
  SDL_Init(SDL_INIT_VIDEO);                       // 初始化 SDL 视频子系统
  SDL_CreateWindowAndRenderer(
      SCREEN_W * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)), // 缩放
      SCREEN_H * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)),
      0, &window, &renderer);                     // 创建窗口和渲染器
  SDL_SetWindowTitle(window, title);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);      // 创建纹理
  SDL_RenderPresent(renderer);  // 显示
}

// 更新 SDL 屏幕内容
static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);  // 清除屏幕
  SDL_RenderCopy(renderer, texture, NULL, NULL);  // 渲染纹理
  SDL_RenderPresent(renderer);  // 显示渲染结果
}
#else   // 如果是 AM 平台，就直接调用 io_write 画图
static void init_screen() {}

static inline void update_screen() {
  io_write(AM_GPU_FBDRAW, 0, 0, vmem, screen_width(), screen_height(), true);
}
#endif
#endif

void vga_update_screen() {
  // TODO: call `update_screen()` when the sync register is non-zero,
  // then zero out the sync register
  // TODO: 如果同步寄存器非零，就调用 update_screen()
  // 然后将同步寄存器清零
  
  if (vgactl_port_base[1] != 0) {
    // 调用update_screen更新屏幕
    IFDEF(CONFIG_VGA_SHOW_SCREEN, update_screen());
    // 将同步寄存器清零
    vgactl_port_base[1] = 0;
  }

}

// 初始化 VGA 模块
void init_vga() {
  // 申请空间保存控制寄存器内容（8字节），高 16 位存宽度，低 16 位存高度
  vgactl_port_base = (uint32_t *)new_space(8);
  vgactl_port_base[0] = (screen_width() << 16) | screen_height();

#ifdef CONFIG_HAS_PORT_IO
  // 如果有端口 I/O，则映射到 PIO
  add_pio_map("vgactl", CONFIG_VGA_CTL_PORT, vgactl_port_base, 8, NULL);
#else
  // 否则映射到 MMIO
  add_mmio_map("vgactl", CONFIG_VGA_CTL_MMIO, vgactl_port_base, 8, NULL);
#endif

  // 分配显存空间
  vmem = new_space(screen_size());

  // 将显存映射为内存映射 I/O 设备
  add_mmio_map("vmem", CONFIG_FB_ADDR, vmem, screen_size(), NULL);

  // 如果启用了显示功能，就初始化屏幕，并将显存清零
  IFDEF(CONFIG_VGA_SHOW_SCREEN, init_screen());
  IFDEF(CONFIG_VGA_SHOW_SCREEN, memset(vmem, 0, screen_size()));
}
