# Makefile for AbstractMachine Kernels and Libraries
# AbstractMachine 内核和库的 Makefile

### *Get a more readable version of this Makefile* by `make html` (requires python-markdown)
### 通过 `make html`（需要 python-markdown）获取更易读的版本
html:
	cat Makefile | sed 's/^\([^#]\)/    \1/g' | markdown_py > Makefile.html
.PHONY: html

## 1. Basic Setup and Checks
## 1. 基本设置与检查

### Default to create a bare-metal kernel image
### 默认生成裸机内核映像
ifeq ($(MAKECMDGOALS),)
  MAKECMDGOALS  = image
  .DEFAULT_GOAL = image
endif

### Override checks when `make clean/clean-all/html`
### 在 `make clean/clean-all/html` 时跳过检查
ifeq ($(findstring $(MAKECMDGOALS),clean|clean-all|html),)

### Print build info message
### 打印构建信息
# $(info # Building $(NAME)-$(MAKECMDGOALS) [$(ARCH)])
$(info # 正在构建 $(NAME)-$(MAKECMDGOALS) [$(ARCH)])

### Check: environment variable `$AM_HOME` looks sane
### 检查环境变量 `$AM_HOME` 是否有效
ifeq ($(wildcard $(AM_HOME)/am/include/am.h),)
  $(error $$AM_HOME 必须是一个 AbstractMachine 仓库)
  # $(error $$AM_HOME must be an AbstractMachine repo)
endif

### Check: environment variable `$ARCH` must be in the supported list
### 检查环境变量 `$ARCH` 是否在支持的列表中
ARCHS = $(basename $(notdir $(shell ls $(AM_HOME)/scripts/*.mk)))
ifeq ($(filter $(ARCHS), $(ARCH)), )
  $(error 预期 $$ARCH 在 {$(ARCHS)} 之中，得到 "$(ARCH)")
  # $(error Expected $$ARCH in {$(ARCHS)}, Got "$(ARCH)")
endif

### Extract instruction set architecture (`ISA`) and platform from `$ARCH`. Example: `ARCH=x86_64-qemu -> ISA=x86_64; PLATFORM=qemu`
# 从 `$ARCH` 中提取指令集架构（ISA）和平台。例如：
# `ARCH=x86_64-qemu` -> `ISA=x86_64`；`PLATFORM=qemu`
ARCH_SPLIT = $(subst -, ,$(ARCH))
ISA        = $(word 1,$(ARCH_SPLIT))
PLATFORM   = $(word 2,$(ARCH_SPLIT))

### Check if there is something to build
### 检查是否有需要编译的文件
ifeq ($(flavor SRCS), undefined)
  $(error 没有需要编译的文件)
  # $(error Nothing to build)
endif

### Checks end here
### 检查结束
endif

## 2. General Compilation Targets
## 2. 通用编译目标

### Create the destination directory (`build/$ARCH`)
### 创建目标目录 (`build/$ARCH`)
WORK_DIR  = $(shell pwd)
DST_DIR   = $(WORK_DIR)/build/$(ARCH)
$(shell mkdir -p $(DST_DIR))

### Compilation targets (a binary image or archive)
### 编译目标（可执行映像或静态库）
IMAGE_REL = build/$(NAME)-$(ARCH)
IMAGE     = $(abspath $(IMAGE_REL))
ARCHIVE   = $(WORK_DIR)/build/$(NAME)-$(ARCH).a

### Collect the files to be linked: object files (`.o`) and libraries (`.a`)
### 收集需要链接的文件：目标文件（`.o`）和库（`.a`）
OBJS      = $(addprefix $(DST_DIR)/, $(addsuffix .o, $(basename $(SRCS))))
LIBS     := $(sort $(LIBS) am klib) # 使用惰性赋值 ("=") 以避免无限递归 lazy evaluation ("=") causes infinite recursions
LINKAGE   = $(OBJS) \
  $(addsuffix -$(ARCH).a, $(join \
    $(addsuffix /build/, $(addprefix $(AM_HOME)/, $(LIBS))), \
    $(LIBS) ))

## 3. General Compilation Flags
## 3. 通用编译选项

### (Cross) compilers, e.g., mips-linux-gnu-g++
### (交叉) 编译器，例如 `mips-linux-gnu-g++`
AS        = $(CROSS_COMPILE)gcc
CC        = $(CROSS_COMPILE)gcc
CXX       = $(CROSS_COMPILE)g++
LD        = $(CROSS_COMPILE)ld
AR        = $(CROSS_COMPILE)ar
OBJDUMP   = $(CROSS_COMPILE)objdump
OBJCOPY   = $(CROSS_COMPILE)objcopy
READELF   = $(CROSS_COMPILE)readelf

### Compilation flags
### 编译选项
INC_PATH += $(WORK_DIR)/include $(addsuffix /include/, $(addprefix $(AM_HOME)/, $(LIBS)))
INCFLAGS += $(addprefix -I, $(INC_PATH))

ARCH_H := arch/$(ARCH).h
CFLAGS   += -O2 -MMD -Wall -Werror $(INCFLAGS) \
            -D__ISA__=\"$(ISA)\" -D__ISA_$(shell echo $(ISA) | tr a-z A-Z)__ \
            -D__ARCH__=$(ARCH) -D__ARCH_$(shell echo $(ARCH) | tr a-z A-Z | tr - _) \
            -D__PLATFORM__=$(PLATFORM) -D__PLATFORM_$(shell echo $(PLATFORM) | tr a-z A-Z | tr - _) \
            -DARCH_H=\"$(ARCH_H)\" \
            -fno-asynchronous-unwind-tables -fno-builtin -fno-stack-protector \
            -Wno-main -U_FORTIFY_SOURCE -fvisibility=hidden
CXXFLAGS +=  $(CFLAGS) -ffreestanding -fno-rtti -fno-exceptions
ASFLAGS  += -MMD $(INCFLAGS)
LDFLAGS  += -z noexecstack $(addprefix -T, $(LDSCRIPTS))

## 4. Arch-Specific Configurations
## 4. 体系结构相关的配置

### Paste in arch-specific configurations (e.g., from `scripts/x86_64-qemu.mk`)
### 引入特定架构的配置文件（例如 `scripts/x86_64-qemu.mk`）
-include $(AM_HOME)/scripts/$(ARCH).mk

## 5. Compilation Rules
## 5. 编译规则

### Rule (compile): a single `.c` -> `.o` (gcc)
### 规则（编译）：单个 `.c` 文件编译为 `.o` 文件（使用 gcc）
$(DST_DIR)/%.o: %.c
	@mkdir -p $(dir $@) && echo + CC $<
	@$(CC) -std=gnu11 $(CFLAGS) -c -o $@ $(realpath $<)

### Rule (compile): a single `.cc` -> `.o` (g++)
### 规则（编译）：单个 `.cc` 文件编译为 `.o` 文件（使用 g++）
$(DST_DIR)/%.o: %.cc
	@mkdir -p $(dir $@) && echo + CXX $<
	@$(CXX) -std=c++17 $(CXXFLAGS) -c -o $@ $(realpath $<)

### Rule (compile): a single `.cpp` -> `.o` (g++)
### 规则（编译）：单个 `.cpp` 文件编译为 `.o` 文件（使用 g++）
$(DST_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@) && echo + CXX $<
	@$(CXX) -std=c++17 $(CXXFLAGS) -c -o $@ $(realpath $<)

### Rule (compile): a single `.S` -> `.o` (gcc, which preprocesses and calls as)
### 规则（编译）：单个 `.S` 汇编文件编译为 `.o` 文件（使用 gcc）
$(DST_DIR)/%.o: %.S
	@mkdir -p $(dir $@) && echo + AS $<
	@$(AS) $(ASFLAGS) -c -o $@ $(realpath $<)

### Rule (recursive make): build a dependent library (am, klib, ...)
### 规则（递归构建）：编译依赖库（如 am、klib）
$(LIBS): %:
	@$(MAKE) -s -C $(AM_HOME)/$* archive

### Rule (link): objects (`*.o`) and libraries (`*.a`) -> `IMAGE.elf`, the final ELF binary to be packed into image (ld)
### 规则（链接）：目标文件（`*.o`）和库文件（`*.a`） -> `IMAGE.elf`，最终的 ELF 二进制文件
$(IMAGE).elf: $(LINKAGE) $(LDSCRIPTS)
	@echo \# Creating image [$(ARCH)]
	@echo + LD "->" $(IMAGE_REL).elf
ifneq ($(filter $(ARCH),native),)
	@$(CXX) -o $@ -Wl,--whole-archive $(LINKAGE) -Wl,-no-whole-archive $(LDFLAGS_CXX)
else
	@$(LD) $(LDFLAGS) -o $@ --start-group $(LINKAGE) --end-group
endif

### Rule (archive): objects (`*.o`) -> `ARCHIVE.a` (ar)
### 规则（归档）：目标文件（`*.o`） -> `ARCHIVE.a`（使用 ar）
$(ARCHIVE): $(OBJS)
	@echo + AR "->" $(shell realpath $@ --relative-to .)
	@$(AR) rcs $@ $^

### Rule (`#include` dependencies): paste in `.d` files generated by gcc on `-MMD`
### 规则（包含头文件依赖）：包含 gcc 生成的 `.d` 文件
-include $(addprefix $(DST_DIR)/, $(addsuffix .d, $(basename $(SRCS))))

## 6. Miscellaneous
## 6. 其他

### Build order control
### 构建顺序控制
image: image-dep
archive: $(ARCHIVE)
image-dep: $(LIBS) $(IMAGE).elf
.NOTPARALLEL: image-dep
.PHONY: image image-dep archive run $(LIBS)

### Clean a single project (remove `build/`)
### 清理单个项目（删除 `build/` 目录）
clean:
	rm -rf Makefile.html $(WORK_DIR)/build/
.PHONY: clean

### Clean all sub-projects within depth 2 (and ignore errors)
### 清理所有子项目（深度 2），忽略错误
CLEAN_ALL = $(dir $(shell find . -mindepth 2 -name Makefile))
clean-all: $(CLEAN_ALL) clean
$(CLEAN_ALL):
	-@$(MAKE) -s -C $@ clean
.PHONY: clean-all $(CLEAN_ALL)
