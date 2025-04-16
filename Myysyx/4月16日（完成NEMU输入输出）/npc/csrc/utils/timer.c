#include "common.h"
#include <time.h>
#include <sys/time.h>

// 如果启用了 CONFIG_TIMER_CLOCK_GETTIME 选项，则进行静态断言
// 确保 CLOCKS_PER_SEC 的值为 1000000
// IFDEF(CONFIG_TIMER_CLOCK_GETTIME,
//     static_assert(CLOCKS_PER_SEC == 1000000, "CLOCKS_PER_SEC != 1000000"));
// // 确保 clock_t 类型的大小为 8 字节
// IFDEF(CONFIG_TIMER_CLOCK_GETTIME,
//     static_assert(sizeof(clock_t) == 8, "sizeof(clock_t) != 8"));

// 记录系统启动时间
static uint64_t boot_time = 0;

// 获取当前时间（内部函数）
static uint64_t get_time_internal() {
// #if defined(CONFIG_TARGET_AM)
//   // 在 AM (Abstract Machine) 目标平台上，使用 io_read 读取当前时间
//   uint64_t us = io_read(AM_TIMER_UPTIME).us;
// #elif defined(CONFIG_TIMER_GETTIMEOFDAY)
  // 使用 gettimeofday 获取当前时间（微秒级精度）
  struct timeval now;
  gettimeofday(&now, NULL);
  uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
// #else
//   // 使用 clock_gettime 获取当前时间（更高精度）
//   struct timespec now;
//   clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
//   uint64_t us = now.tv_sec * 1000000 + now.tv_nsec / 1000;
// #endif
  return us;
}

// 获取系统启动以来经过的时间（微秒）
uint64_t get_time() {
  if (boot_time == 0) boot_time = get_time_internal(); // 记录启动时间
  uint64_t now = get_time_internal();
  return now - boot_time; // 返回相对启动时间的时间差
}

// 初始化随机数生成器
void init_rand() {
  srand(get_time_internal()); // 使用当前时间作为种子
}

