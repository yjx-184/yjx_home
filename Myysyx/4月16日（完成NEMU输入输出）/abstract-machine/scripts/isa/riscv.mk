# 设置交叉编译工具链
CROSS_COMPILE := riscv64-linux-gnu-
# 定义通用编译选项
COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
# 设置 C 语言编译器选项
CFLAGS        += $(COMMON_CFLAGS) -static
# 设置汇编编译选项
ASFLAGS       += $(COMMON_CFLAGS)-O0
# 设置链接器选项
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
# 覆盖 $(AM_HOME)/Makefile 中定义的 ARCH_H
ARCH_H := arch/riscv.h
