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

#ifndef __DEVICE_MAP_H__
#define __DEVICE_MAP_H__

#include <cpu/difftest.h>

// 定义一个函数指针类型：设备的IO回调函数
typedef void(*io_callback_t)(uint32_t, int, bool);  // 地址（uint32_t）、访问长度（int）、是否是写操作（bool）
uint8_t* new_space(int size);                       // 分配一块新的设备空间，返回指向这块内存的指针

typedef struct {
  const char *name;       // 映射名称，便于调试识别
  // we treat ioaddr_t as paddr_t here
  // 我们在这里将 ioaddr_t 视为 paddr_t
  paddr_t low;            // 映射的起始物理地址
  paddr_t high;           // 映射的结束物理地址
  void *space;            // 指向分配的内存空间（new_space得到的）
  io_callback_t callback; // 该映射的回调函数（用于读写时触发）
} IOMap;

// 判断一个地址是否落在某个IOMap映射范围中
static inline bool map_inside(IOMap *map, paddr_t addr) {
  return (addr >= map->low && addr <= map->high);
}

// 在maps数组中查找包含指定地址的映射，返回其下标
static inline int find_mapid_by_addr(IOMap *maps, int size, paddr_t addr) {
  int i;
  for (i = 0; i < size; i ++) {
    if (map_inside(maps + i, addr)) {
      difftest_skip_ref();  // 通知difftest跳过当前参考指令（通常用于外设IO）
      return i;             // 返回映射下标
    }
  }
  return -1;
}

// 注册一个PIO映射（Programmed IO，通常是端口映射）
void add_pio_map(const char *name, ioaddr_t addr,           // name: 名称，addr: 起始地址，space: 映射的内存区域，
        void *space, uint32_t len, io_callback_t callback); // len: 映射长度，callback: 访问时回调
// 注册一个MMIO映射（Memory-Mapped IO）
void add_mmio_map(const char *name, paddr_t addr,
        void *space, uint32_t len, io_callback_t callback);

// 从映射设备中读取数据（由map提供空间和回调）
word_t map_read(paddr_t addr, int len, IOMap *map);         // addr: 读取地址，len: 读取长度，map: 对应的IOMap
// 向映射设备写入数据
void map_write(paddr_t addr, int len, word_t data, IOMap *map);// addr: 写入地址，len: 写入长度，data: 要写入的数据，map: 对应的IOMap

#endif
