// NPC项目手动配置文件
#pragma once

// ============================== 跟踪功能配置 ==============================
#define CONFIG_TRACE      1      // 是否启用通用跟踪功能 (1 启用, 0 禁用)
#define CONFIG_ITRACE     1      // 是否启用指令跟踪 (1 启用, 0 禁用)
#define CONFIG_WATCHPOINT 1      // 是否启用监视点功能 (1 启用, 0 禁用)
#define CONFIG_FTRACE     0      // 是否启用函数调用跟踪 (1 启用, 0 禁用)
#define CONFIG_DIFFTEST   1      // 是否启用 DiffTest 比对功能 (1 启用, 0 禁用)
#define CONFIG_RT_CHECK   1      // 是否启用运行时检查 (1 启用, 0 禁用)
#define CONFIG_MTRACE     0      // 是否开启内存访问的踪迹(1 启用, 0 禁用)
#define CONFIG_MTRACE_ADDR_RANGE 0x0,0xFFFFFFFF // MTRACE 地址范围配置项

// ============================== 跟踪范围配置 ==============================
#define CONFIG_TRACE_START 0      // 指令跟踪的起始条目 (从第多少条指令开始跟踪)
#define CONFIG_TRACE_END   10000  // 指令跟踪的结束条目 (到第多少条指令结束)

// ============================== 内存配置 ==============================
#define CONFIG_MBASE       0x80000000 // 内存基地址
#define CONFIG_MSIZE       0x8000000  // 物理内存大小 (128MB)
#define CONFIG_MEM_RANDOM  1          // 是否使用随机初始化内存 (1 启用, 0 禁用)

// ============================== 运行时配置 ==============================
#define CONFIG_RT_CHECK        1        // 是否启用运行时检查 (1 启用, 0 禁用)
#define CONFIG_PC_RESET_OFFSET 0x0      // PC 重置偏移量
#define CONFIG_RVE             0        // 0表示启用 RVE（RISC-V Embedded）模式

// ============================== 设备配置 ==============================
#define CONFIG_DEVICE          0        // 是否启用设备支持 (1 启用, 0 禁用)


// ============================== 语言配置 ==============================
#define CONFIG_CN              1        // 是否启用中文语言支持 (1 启用, 0 禁用)