#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)                    // 定义物理内存的起始地址，CONFIG_MBASE 是基地址
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)     // 定义物理内存的结束地址，CONFIG_MSIZE 是内存大小
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET) // 定义复位向量的地址，复位向量是程序启动时执行的地址

/* convert the guest physical address in the guest program to host virtual address in NEMU */
/* 将客户程序中的客户物理地址转换为 NEMU 中的主机虚拟地址 */
uint8_t* guest_to_host(paddr_t paddr);

/* convert the host virtual address in NEMU to guest physical address in the guest program */
/* 将 NEMU 中的主机虚拟地址转换为客户程序中的客户物理地址 */
paddr_t host_to_guest(uint32_t *haddr);

// 判断给定的地址是否在物理内存范围内
static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}
// 从物理地址读取数据，len 是读取的长度
extern "C" word_t paddr_read(paddr_t addr, int len);
// 向物理地址写入数据，len 是写入的长度，data 是要写入的数据
void paddr_write(int waddr, int len, int wdata);



#endif