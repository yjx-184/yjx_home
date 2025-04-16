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

#include <memory/host.h>          //包含主机内存操作相关的头文件
#include <memory/paddr.h>         //包含物理地址操作相关的头文件
#include <device/mmio.h>          //包含设备内存映射IO操作相关的头文件
#include <isa.h>                  //包含ISA指令集架构相关的头文件

//根据配置选择物理内存管理方式：使用malloc 或者静态分配数组
#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};  //使用静态数组方式分配物理内存
#endif

#ifdef CONFIG_MTRACE
// 定义内存追踪的起始和结束地址
static paddr_t mtrace_start = 0;
static paddr_t mtrace_end = 0xFFFFFFFF;

// 初始化内存追踪功能，解析配置中的地址范围
void init_mtrace() {
  char *range = CONFIG_MTRACE_ADDR_RANGE;
  if (range) {
    sscanf(range, "%x,%x", &mtrace_start, &mtrace_end);
  }
}

// 检查地址是否在内存追踪范围内
static inline bool in_mtrace_range(paddr_t addr) {
  return addr >= mtrace_start && addr <= mtrace_end;
}
#endif

//将物理地址转换为主机内存地址，物理地址到主机地址的转换，偏移量由配置的基地址决定
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
//将主机内存地址转换为物理地址，主机地址到物理地址的转换，基于物理内存起始位置的偏移
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

//从物理内存读取数据
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len); //从物理内存对应位置读取数据
  return ret;                                       //返回读取的数据
}

//向物理内存写入数据
static void pmem_write(paddr_t addr, int len, word_t data) {  
  host_write(guest_to_host(addr), len, data);       //向物理内存对应位置写入数据
}

//处理越界访问物理内存情况
static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);         //输出错误信息并触发panic
}

//初始化物理内存，分配内存并设置随机数（如果配置了随机填充）
void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);  //动态分配内存
  assert(pmem);                 //确保内存分配成功
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE)); //配置了随机填充时，将物理内存填充为随机值
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);//打印物理内存的地址范围

#ifdef CONFIG_MTRACE
  init_mtrace();  // 初始化内存追踪功能
#endif
}

//从物理地址读取数据，如果地址在物理内存范围内，则直接读取，否则检查是否为MMIO设备
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) {          // 检查地址是否在物理内存范围内
    word_t ret = pmem_read(addr, len);  // 读取数据
#ifdef CONFIG_MTRACE
    if (in_mtrace_range(addr)) {        // 如果启用了内存追踪且地址在追踪范围内
      printf("[MTRACE] Read  addr=0x%08x len=%d data=0x%08x\n", addr, len, ret);
    }
#endif
    return ret;                         // 返回读取的数据
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));     //配置了设备时，调用设备的内存映射IO读取函数
  out_of_bound(addr); //如果地址超出范围，调用越界处理函数
  return 0;
}

//向物理地址写入数据，如果地址在物理内存范围内，则直接写入，否则检查是否为MMIO设备
void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {          // 检查地址是否在物理内存范围内
#ifdef CONFIG_MTRACE
    if (in_mtrace_range(addr)) {        // 如果启用了内存追踪且地址在追踪范围内
      printf("[MTRACE] Write addr=0x%08x len=%d data=0x%08x\n", addr, len, data);
    }
#endif
    pmem_write(addr, len, data);        // 写入数据
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);         //如果地址超出范围，调用越界处理函数
  out_of_bound(addr);
}
