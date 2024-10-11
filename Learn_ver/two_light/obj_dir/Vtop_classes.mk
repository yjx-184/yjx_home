# Verilated -*- Makefile -*-
# 描述: Verilator 输出: 生成的包含类列表的 Makefile
#
# 这个文件列出了生成的 Verilated 文件，用于在更高层的 Makefile 中包含。
# 参见 Vtop.mk 以获取调用者。

### 开关...
# 是否需要 C11 结构？ 0/1（现在总是开启）
VM_C11 = 1
# 是否启用定时？ 0/1
VM_TIMING = 0
# 覆盖输出模式？ 0/1（来自 --coverage）
VM_COVERAGE = 0
# 是否进行并行构建？ 0/1（来自 --output-split）
VM_PARALLEL_BUILDS = 0
# 是否启用跟踪输出模式？ 0/1（来自 --trace/--trace-fst）
VM_TRACE = 0
# 是否启用 VCD 格式的跟踪输出模式？ 0/1（来自 --trace）
VM_TRACE_VCD = 0
# 是否启用 FST 格式的跟踪输出模式？ 0/1（来自 --trace-fst）
VM_TRACE_FST = 0

### 对象文件列表...
# 生成的模块类，快速路径，使用最高优化编译
VM_CLASSES_FAST += \
	Vtop \
	Vtop___024root__DepSet_h84412442__0 \
	Vtop___024root__DepSet_heccd7ead__0 \

# 生成的模块类，非快速路径，使用低/中等优化编译
VM_CLASSES_SLOW += \
	Vtop___024root__Slow \
	Vtop___024root__DepSet_h84412442__0__Slow \
	Vtop___024root__DepSet_heccd7ead__0__Slow \

# 生成的支持类，快速路径，使用最高优化编译
VM_SUPPORT_FAST += \

# 生成的支持类，非快速路径，使用低/中等优化编译
VM_SUPPORT_SLOW += \
	Vtop__Syms \

# 全局类，每个可执行文件需要链接一次，快速路径，使用最高优化编译
VM_GLOBAL_FAST += \
	verilated \
	verilated_threads \

# 全局类，每个可执行文件需要链接一次，非快速路径，使用低/中等优化编译
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
