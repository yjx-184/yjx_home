#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

// 物理内存起始地址
extern char _pmem_start;
// 定义物理内存大小为 128MB
#define PMEM_SIZE (128 * 1024 * 1024)
// 计算物理内存的结束地址
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

// 定义 heap 结构体，管理从 `_heap_start` 到 `PMEM_END` 之间的内存区域
Area heap = RANGE(&_heap_start, PMEM_END);
// 预定义的 main 函数参数，长度由 CFLAGS 设定
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

// putch: 用于输出单个字符
void putch(char ch) {
}

// halt: 终止程序的函数
void halt(int code) {
  asm volatile("ebreak");
  while (1);
}

// _trm_init: 终端初始化函数，调用 main 并最终 halt
void _trm_init() {
  int ret = main(mainargs); // 运行 main 函数，并获取返回值
  halt(ret);                // 终止程序，使用 main 的返回值作为退出码
}
