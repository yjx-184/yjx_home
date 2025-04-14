# 包含 RISC-V 相关的 `Makefile`，定义了编译选项和工具链
include $(AM_HOME)/scripts/isa/riscv.mk
# 包含 NEMU 平台相关的 `Makefile`，定义了构建规则
include $(AM_HOME)/scripts/platform/nemu.mk
# 指定编译时的预处理宏 `ISA_H`，用于选择 RISC-V 架构的头文件
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
# 指定 RISC-V 32 位 `rv32im_zicsr` 架构，并使用 `ilp32` ABI
COMMON_CFLAGS += -march=rv32im_zicsr -mabi=ilp32    # 覆盖（overwrite）默认的架构设置
# 指定链接选项，目标格式为 32 位 RISC-V ELF
LDFLAGS       += -melf32lriscv  # 覆盖（overwrite）默认的链接格式

# 指定 RISC-V 平台的源文件
AM_SRCS += riscv/nemu/start.S \
           riscv/nemu/cte.c \
           riscv/nemu/trap.S \
           riscv/nemu/vme.c
