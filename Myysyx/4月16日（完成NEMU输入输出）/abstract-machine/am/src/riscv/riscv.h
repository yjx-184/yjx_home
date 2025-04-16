#ifndef RISCV_H__
#define RISCV_H__

#include <stdint.h>

// 读取内存地址上的值（输入）：
// inb/inw/inl 分别读取一个字节、两个字节、四个字节，返回结果
static inline uint8_t  inb(uintptr_t addr) { return *(volatile uint8_t  *)addr; }
static inline uint16_t inw(uintptr_t addr) { return *(volatile uint16_t *)addr; }
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

// 写入内存地址上的值（输出）：
// outb/outw/outl 分别写入一个字节、两个字节、四个字节的数据到对应地址
static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
static inline void outw(uintptr_t addr, uint16_t data) { *(volatile uint16_t *)addr = data; }
static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

// RISC-V 页表项标志位（Page Table Entry Flags）
#define PTE_V 0x01  // 有效位（Valid）
#define PTE_R 0x02  // 可读位（Readable）
#define PTE_W 0x04  // 可写位（Writable）
#define PTE_X 0x08  // 可执行位（Executable）
#define PTE_U 0x10  // 用户模式访问（User-accessible）
#define PTE_A 0x40  // 已访问位（Accessed）
#define PTE_D 0x80  // 脏页标志（Dirty）

// RISC-V 的权限模式（Privilege Modes）
// MODE_U 用户模式，MODE_S 管理员/监督模式， MODE_M 机器模式，值为3是RISC-V规定
enum { MODE_U, MODE_S, MODE_M = 3 };

// mstatus 寄存器中的位字段定义
#define MSTATUS_MXR  (1 << 19) // 允许加载不可执行页的权限（MXR：Make eXecutable Readable）
#define MSTATUS_SUM  (1 << 18) // 允许 Supervisor 模式访问 User 页（SUM：Supervisor User Memory access）

// 处理器位宽相关标志
#if __riscv_xlen == 64
#define MSTATUS_SXL  (2ull << 34)
#define MSTATUS_UXL  (2ull << 32)
#else
#define MSTATUS_SXL  0
#define MSTATUS_UXL  0
#endif

#endif
