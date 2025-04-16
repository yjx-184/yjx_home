AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

# 添加编译选项
# 将数据和函数放入独立的段，便于链接时优化
CFLAGS    += -fdata-sections -ffunction-sections

# 添加链接脚本
# 指定链接器脚本
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld

# 添加链接选项
# 定义符号，指定物理
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0

# 内存起始地址和入口偏移
# 启用无用段回收，并指定程序入口点为 _start
LDFLAGS   += --gc-sections -e _start

# 指定 NPC 的日志文件路径
# NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt

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

run: insert-arg
	$(NPC_HOME)/build/Npc $(abspath $(IMAGE).bin) \
	-d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so \
	-e $(abspath $(IMAGE).elf) \
	-l $(shell dirname $(IMAGE).elf)/npc-log.txt
# $(NPC_HOME)/build/Npc  $(abspath $(IMAGE).bin) -e $(abspath $(IMAGE).elf) -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
.PHONY: insert-arg
