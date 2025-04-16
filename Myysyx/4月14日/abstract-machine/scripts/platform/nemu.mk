# 指定 AM（Abstract Machine）相关的源文件
AM_SRCS := platform/nemu/trm.c \
           platform/nemu/ioe/ioe.c \
           platform/nemu/ioe/timer.c \
           platform/nemu/ioe/input.c \
           platform/nemu/ioe/gpu.c \
           platform/nemu/ioe/audio.c \
           platform/nemu/ioe/disk.c \
           platform/nemu/mpe.c

# 添加编译选项
# 将数据和函数放入独立的段，便于链接时优化
CFLAGS    += -fdata-sections -ffunction-sections
# 添加头文件搜索路径
CFLAGS    += -I$(AM_HOME)/am/src/platform/nemu/include

# 添加链接脚本
# 指定链接器脚本
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld

# 添加链接选项
# 定义符号，指定物理
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0

# 内存起始地址和入口偏移
# 启用无用段回收，并指定程序入口点为 _start
LDFLAGS   += --gc-sections -e _start

# 添加 NEMU 模拟器的运行选项
# 指定 NEMU 模拟器的日志文件路径
NEMUFLAGS += -l $(shell dirname $(IMAGE).elf)/nemu-log.txt

# 定义主函数参数的最大长度和占位符
# 主函数参数的最大长度
MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

# 插入主函数参数的规则
insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

# 生成镜像文件的规则
image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

# 运行模拟器的规则
run: insert-arg
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NEMUFLAGS) -e $(IMAGE).elf" IMG=$(IMAGE).bin

gdb: insert-arg
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NEMUFLAGS) -e $(IMAGE).elf" IMG=$(IMAGE).bin

.PHONY: insert-arg
