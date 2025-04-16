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
#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

#define IO_SPACE_MAX (32 * 1024 * 1024)           // I/O 地址空间最大32MB

static uint8_t *io_space = NULL;                  // I/O 地址空间的起始指针
static uint8_t *p_space = NULL;                   // 当前可分配空间的起始指针

/* 分配指定大小的I/O空间（按页对齐） */
uint8_t* new_space(int size) {
  uint8_t *p = p_space;                           // 记录当前分配位置
  // page aligned;页对齐处理：将大小向上对齐到PAGE_SIZE的倍数
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;                                // 移动可用空间指针
  assert(p_space - io_space < IO_SPACE_MAX);      // 断言确保不超过最大限制
  return p;                                       // 返回分配的空间起始地址
}

/* 检查地址是否在映射范围内 */
static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {                              // 没有对应映射的情况
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {                                        // 有映射但地址超出范围的情况
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, cpu.pc);
  }
}

/* 调用I/O回调函数 */
static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }    // 调用回调函数：参数包括偏移量、长度、是否是写操作
}

/* 初始化内存映射空间 */
void init_map() {
  io_space = malloc(IO_SPACE_MAX);                // 分配32MB的I/O空间
  assert(io_space);                               // 确保分配成功
  p_space = io_space;                             // 初始化分配指针
}

/* 从映射空间读取数据 */
word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);                   // 确保合法访问长度（1-8字节）
  check_bound(map, addr);                         // 检查地址合法性
  paddr_t offset = addr - map->low;               // 计算映射空间内的偏移量
  invoke_callback(map->callback, offset, len, false); // 在读取前调用回调函数（例如更新设备状态）
  word_t ret = host_read(map->space + offset, len);   // 从映射空间执行实际读取操作
  
  // dtrace
  #ifdef CONFIG_DTRACE
    printf("[dtrace] read  %s @ 0x%08x, len = %d, data = 0x%0*x\n",
              map->name, addr, len, len * 2, ret);
  #endif

  return ret;
}

/* 向映射空间写入数据 */
void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);                   // 确保合法访问长度
  check_bound(map, addr);                         // 检查地址合法性
  paddr_t offset = addr - map->low;               // 计算映射空间内的偏移量
  host_write(map->space + offset, len, data);     // 先执行实际写入操作
  invoke_callback(map->callback, offset, len, true);  // 在写入后调用回调函数（例如触发设备操作）

  // dtrace
  #ifdef CONFIG_DTRACE
    printf("[dtrace] write  %s @ 0x%08x, len = %d, data = 0x%0*x\n",
              map->name, addr, len, len * 2, data);
  #endif
}
