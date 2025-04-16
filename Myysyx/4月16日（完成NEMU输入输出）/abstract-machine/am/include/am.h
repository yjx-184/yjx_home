#ifndef AM_H__
#define AM_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include ARCH_H // this macro is defined in $CFLAGS
                // examples: "arch/x86-qemu.h", "arch/native.h", ...

// Memory protection flags
// -------------------- 内存保护标志位 --------------------
#define MMAP_NONE  0x00000000 // no access 不可访问
#define MMAP_READ  0x00000001 // can read  可读
#define MMAP_WRITE 0x00000002 // can write 可写

// Memory area for [@start, @end)
// -------------------- 表示一段内存区域 [start, end) --------------------
typedef struct {
  void *start, *end;          // 内存起始地址和结束地址
} Area;

// Arch-dependent processor context
// -------------------- 架构相关的上下文结构体 --------------------
typedef struct Context Context;// 上下文结构体声明，具体内容架构相关

// An event of type @event, caused by @cause of pointer @ref
// -------------------- 表示一个事件 --------------------
typedef struct {
  enum {
    EVENT_NULL = 0,        // 无事件
    EVENT_YIELD,           // 主动放弃 CPU
    EVENT_SYSCALL,         // 系统调用
    EVENT_PAGEFAULT,       // 页面错误
    EVENT_ERROR,           // 错误事件
    EVENT_IRQ_TIMER,       // 定时器中断
    EVENT_IRQ_IODEV,       // IO 设备中断
  } event;
  uintptr_t cause;         // 事件原因（数值）
  uintptr_t ref;           // 事件相关指针引用（例如出错地址等）
  const char *msg;         // 可选的调试信息字符串
} Event;

// A protected address space with user memory @area
// and arch-dependent @ptr
// -------------------- 表示一个地址空间（用于进程地址隔离） ----------------
typedef struct {
  int pgsize;              // 页大小
  Area area;               // 用户空间内存区域
  void *ptr;               // 架构相关的数据指针（页表或相关信息）
} AddrSpace;

#ifdef __cplusplus
extern "C" {
#endif

// -------------------- TRM: Turing Machine（最小系统接口） --------------------
extern   Area        heap;                             // 堆的地址区域
void     putch       (char ch);                        // 输出一个字符到终端
void     halt        (int code) __attribute__((__noreturn__)); // 停止程序运行，永不返回

// -------------------- IOE: 输入输出设备 --------------------
bool     ioe_init    (void);                           // 初始化 IOE 子系统
void     ioe_read    (int reg, void *buf);             // 从设备寄存器读取数据
void     ioe_write   (int reg, void *buf);             // 向设备寄存器写入数据
#include "amdev.h"                                     // 包含设备相关结构体定义

// -------------------- CTE: 中断处理与上下文切换 --------------------
bool     cte_init    (Context *(*handler)(Event ev, Context *ctx)); // 初始化中断系统，注册事件处理函数
void     yield       (void);                           // 主动触发 EVENT_YIELD 中断
bool     ienabled    (void);                           // 查询当前中断是否启用
void     iset        (bool enable);                    // 设置中断启用或关闭
Context *kcontext    (Area kstack, void (*entry)(void *), void *arg); // 创建一个内核上下文，绑定入口函数和参数

// -------------------- VME: 虚拟内存支持 --------------------
bool     vme_init    (void *(*pgalloc)(int), void (*pgfree)(void *)); // 初始化虚拟内存，传入页分配和释放函数
void     protect     (AddrSpace *as);                  // 启用地址空间保护机制
void     unprotect   (AddrSpace *as);                  // 禁用地址空间保护
void     map         (AddrSpace *as, void *vaddr, void *paddr, int prot); // 建立虚拟地址到物理地址的映射
Context *ucontext    (AddrSpace *as, Area kstack, void *entry); // 创建用户上下文，绑定用户空间和入口函数

// -------------------- MPE: 多处理器支持 --------------------
bool     mpe_init    (void (*entry)());                // 初始化多核支持，并设定每个核的入口函数
int      cpu_count   (void);                           // 获取总 CPU 核心数
int      cpu_current (void);                           // 获取当前运行的 CPU 核 ID
int      atomic_xchg (int *addr, int newval);          // 原子交换操作：交换内存中的值并返回旧值

#ifdef __cplusplus
}
#endif

#endif
