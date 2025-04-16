#ifndef __MEMORY_HOST_H__
#define __MEMORY_HOST_H__

#include <common.h>

static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr; // 读取 1 字节
    case 2: return *(uint16_t *)addr; // 读取 2 字节
    case 4: return *(uint32_t *)addr; // 读取 4 字节
    // IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr);
    default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
  }
}

static inline void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return; // 写入 1 字节
    case 2: *(uint16_t *)addr = data; return; // 写入 2 字节
    case 4: *(uint32_t *)addr = data; return;// 写入 4 字节
    // IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return);
    // IFDEF(CONFIG_RT_CHECK, default: assert(0));
    #if CONFIG_RT_CHECK
        default: assert(0);
    #endif
  }
}

#endif