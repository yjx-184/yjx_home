#ifndef __COMMON_H__
#define __COMMON_H__

// 引入标准头文件，提供基本的数据类型和字符串处理函数
#include <stdint.h>     // 定义标准整数类型，如 uint32_t、uint64_t
#include <inttypes.h>   // 提供格式化打印宏，如 PRIx64
#include <stdbool.h>    // 定义布尔类型 bool
#include <string.h>     // 提供字符串处理函数，如 memset, memcpy
#include <stdio.h>
#include <errno.h>

// 引入自动生成的配置头文件和宏定义头文件
#include <config/npc_config.h>
#include <macro.h>

// 如果目标是 AM（Abstract Machine），则使用 klib 库，否则使用标准库
// #ifdef CONFIG_TARGET_AM
// #include <klib.h>
// #else
#include <assert.h>     // 断言库，提供 assert() 进行调试
#include <stdlib.h>     // 标准库，提供 malloc, free, exit 等函数
// #endif

// 判断物理内存配置是否超过 4GB（0x100000000ul），如果是则定义 PMEM64
#if CONFIG_MBASE + CONFIG_MSIZE > 0x100000000ul
#define PMEM64 1
#endif
// #define MEM_SIZE 134217728   //内存大小为
// #define MEM_BASE 0x80000000 //初始地址，也可以是基地址

// typedef MUXDEF(CONFIG_ISA64, uint64_t, uint32_t) word_t;
// typedef MUXDEF(CONFIG_ISA64, int64_t, int32_t)  sword_t;
/* 直接固定32位了，主要是没有ISA架构判断了 */
typedef uint32_t word_t;
typedef int32_t sword_t;


// // 定义格式化 word_t 类型的输出格式，确保在不同 ISA 下能正确打印
// #define FMT_WORD MUXDEF(CONFIG_ISA64, "0x%016" PRIx64, "0x%08" PRIx32)
/* 直接固定32位了，主要是没有ISA架构判断了 */
#define FMT_WORD "0x%08" PRIx32

// 定义虚拟地址类型 vaddr_t，其大小与 word_t 相同
typedef word_t vaddr_t;


// // 定义物理地址类型 paddr_t，根据是否是 64 位物理内存（PMEM64）选择数据类型
// typedef MUXDEF(PMEM64, uint64_t, uint32_t) paddr_t;
/* 固定使用32位*/
typedef uint32_t paddr_t;



// // 定义格式化物理地址的输出格式，确保在 32/64 位情况下正确打印
// #define FMT_PADDR MUXDEF(PMEM64, "0x%016" PRIx64, "0x%08" PRIx32)
/* 直接固定32位了，主要是没有ISA架构判断了 */
#define FMT_PADDR "0x%08" PRIx32

// 定义 I/O 地址类型，使用 16 位无符号整数
typedef uint16_t ioaddr_t;

#include <debug.h>

#endif