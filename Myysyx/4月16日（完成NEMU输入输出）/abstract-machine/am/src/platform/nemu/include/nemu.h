#ifndef NEMU_H__
#define NEMU_H__

#include <klib-macros.h>

// the macro `ISA_H` is defined in CFLAGS
// it will be expanded as "x86/x86.h", "mips/mips32.h", ...
#include ISA_H 

#if defined(__ISA_X86__)
# define nemu_trap(code) asm volatile ("int3" : :"a"(code))
#elif defined(__ISA_MIPS32__)
# define nemu_trap(code) asm volatile ("move $v0, %0; sdbbp" : :"r"(code))
#elif defined(__riscv)
# define nemu_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
// RISC-V: 先将 code 存入 a0 寄存器，再执行 ebreak（断点异常）
#elif defined(__ISA_LOONGARCH32R__)
# define nemu_trap(code) asm volatile("move $a0, %0; break 0" : :"r"(code))
#else
# error unsupported ISA __ISA__
#endif

// 设备基地址（DEVICE_BASE）的定义
// 在 x86 NEMU 中，DEVICE_BASE 设为 0x0（表示设备映射在低地址）
// 其他架构默认设为 0xa0000000（高地址映射）
#if defined(__ARCH_X86_NEMU)
# define DEVICE_BASE 0x0
#else
# define DEVICE_BASE 0xa0000000
#endif

// 内存映射 IO（MMIO）基地址
#define MMIO_BASE 0xa0000000

// 定义各类设备的 MMIO 地址
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)   /*串口*/
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)   /*键盘*/
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)   /*实时时钟*/
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)   /*VGA控制器*/
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)   /*音频设备*/
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)   /*磁盘设备*/
#define FB_ADDR         (MMIO_BASE   + 0x1000000)   /*帧缓冲区*/
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)   /*音频缓冲区*/

// 物理内存的起始地址（_pmem_start 由链接脚本提供）
extern char _pmem_start;

// 定义物理内存大小和结束地址
// 物理内存大小 128MB
#define PMEM_SIZE (128 * 1024 * 1024)
// 计算物理内存结束地址
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

// NEMU 支持的物理地址范围（用于地址空间映射）
#define NEMU_PADDR_SPACE \
  RANGE(&_pmem_start, PMEM_END),       /* 物理内存范围 */ \
  RANGE(FB_ADDR, FB_ADDR + 0x200000),  /* 帧缓冲区（2MB）*/\
  RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* MMIO 设备（串口、RTC、屏幕、键盘等）*/

// 定义页表项类型
typedef uintptr_t PTE;

// 定义页大小（4KB）
#define PGSIZE    4096

#endif
