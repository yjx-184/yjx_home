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

#define PORT_IO_SPACE_MAX 65535

#define NR_MAP 16
static IOMap maps[NR_MAP] = {};
static int nr_map = 0;

/* device interface */
// 用于为设备的初始化注册一个端口映射I/O的映射关系，映射名称，起始端口地址，关联的内存空间指针，映射长度（字节数），操作回调函数
void add_pio_map(const char *name, ioaddr_t addr, void *space, uint32_t len, io_callback_t callback) {
  assert(nr_map < NR_MAP);                  // 确保映射数量未超限
  assert(addr + len <= PORT_IO_SPACE_MAX);  // 确保地址范围有效
  // 初始化映射项：记录名称、地址范围、空间指针和回调函数
  maps[nr_map] = (IOMap){ .name = name, .low = addr, .high = addr + len - 1,
    .space = space, .callback = callback };
  // 打印调试信息，"添加端口I/O映射 '%s' 地址范围
  Log("Add port-io map '%s' at [" FMT_PADDR ", " FMT_PADDR "]",
      maps[nr_map].name, maps[nr_map].low, maps[nr_map].high);

  nr_map ++;                                // 更新已注册映射计数
}

/* CPU interface */
// CPU端口读取接口，端口地址，读取长度（1/2/4字节）
uint32_t pio_read(ioaddr_t addr, int len) {
  assert(addr + len - 1 < PORT_IO_SPACE_MAX);         // 验证地址范围有效性（注意len-1处理
  int mapid = find_mapid_by_addr(maps, nr_map, addr); // 查找地址对应的映射ID
  assert(mapid != -1);                                // 确保找到有效映射
  return map_read(addr, len, &maps[mapid]);           // 调用底层map_read执行实际读取
}

// CPU端口写入接口，端口地址，写入长度（1/2/4字节）
void pio_write(ioaddr_t addr, int len, uint32_t data) {
  assert(addr + len - 1 < PORT_IO_SPACE_MAX);         // 验证地址范围有效性
  int mapid = find_mapid_by_addr(maps, nr_map, addr); // 查找地址对应的映射ID
  assert(mapid != -1);                                // 确保找到有效映射
  map_write(addr, len, data, &maps[mapid]);           // 调用底层map_write执行实际写入
}
