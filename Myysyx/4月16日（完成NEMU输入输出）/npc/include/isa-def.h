#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

/* 定义了一个结构体，用于表示RISC-V CPU 的状态 */
typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)]; //gpr是通用寄存器组，大小由MUXDEF宏决定。
  paddr_t pc;  
} CPU_state;

// decode
//定义指令解码信息结构体
typedef struct {
  uint32_t inst;  //存储当前指令的二进制编码
} ISADecodeInfo;//根据配置选择

//定义内存管理单元MMU检查函数
//这里直接返回 MMU_DIRECT，表示直接访问物理内存，不经过 MMU 的地址转换
#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif
