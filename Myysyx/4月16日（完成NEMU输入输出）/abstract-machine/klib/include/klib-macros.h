#ifndef KLIB_MACROS_H__
#define KLIB_MACROS_H__

// ======================== 内存对齐宏 ===============================================
// 向上对齐到sz的倍数
#define ROUNDUP(a, sz)      ((((uintptr_t)a) + (sz) - 1) & ~((sz) - 1))

// 向下对齐到sz的倍数
#define ROUNDDOWN(a, sz)    ((((uintptr_t)a)) & ~((sz) - 1))

// 计算数组长度
#define LENGTH(arr)         (sizeof(arr) / sizeof((arr)[0]))

// 创建一个Area结构体，表示从st到ed的内存区域
#define RANGE(st, ed)       (Area) { .start = (void *)(st), .end = (void *)(ed) }

// 检查指针ptr是否在area内存区域内
#define IN_RANGE(ptr, area) ((area).start <= (ptr) && (ptr) < (area).end)

// ======================== 字符串处理宏 =============================================
// 将标识符转换为字符串字面量
#define STRINGIFY(s)        #s

// 将标识符转换为字符串字面量（二级展开）
#define TOSTRING(s)         STRINGIFY(s)

// 连接两个标识符（内部使用）
#define _CONCAT(x, y)       x ## y

// 连接两个标识符
#define CONCAT(x, y)        _CONCAT(x, y)

// 输出字符串到控制台
#define putstr(s) \
  ({ for (const char *p = s; *p; p++) putch(*p); })

// =============================== IO操作宏 ==========================================
// 读取IO寄存器
#define io_read(reg) \
  ({ reg##_T __io_param; \
    ioe_read(reg, &__io_param); \
    __io_param; })

// 写入IO寄存器
#define io_write(reg, ...) \
  ({ reg##_T __io_param = (reg##_T) { __VA_ARGS__ }; \
    ioe_write(reg, &__io_param); })

// 编译时断言
#define static_assert(const_cond) \
  static char CONCAT(_static_assert_, __LINE__) [(const_cond) ? 1 : -1] __attribute__((unused))

// =============================== 错误处理宏 =========================================
// 条件触发panic
#define panic_on(cond, s) \
  ({ if (cond) { \
      putstr("AM Panic: "); putstr(s); \
      putstr(" @ " __FILE__ ":" TOSTRING(__LINE__) "  \n"); \
      halt(1); \
    } })
// 无条件触发panic
#define panic(s) panic_on(1, s)

#endif
