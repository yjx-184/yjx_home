# 定义工程的顶层模块名称
TOPNAME = Npc

# Capstone 配置
CAPSTONE_DIR = $(abspath tools/capstone)
CAPSTONE_REPO = $(CAPSTONE_DIR)/repo
CAPSTONE_LIB = $(CAPSTONE_REPO)/libcapstone.so.5
CAPSTONE_INC = $(CAPSTONE_REPO)/include

# 检查是否启用指令追踪
CONFIG_ITRACE ?= 1

# Verilator 配置
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc -O3 --x-assign fast --x-initial fast --noassert --trace
VERILATOR_CFLAGS += -I$(abspath include)
VERILATOR_CFLAGS += --CFLAGS "-I$(abspath include) -I$(CAPSTONE_INC)"
VERILATOR_CFLAGS += --LDFLAGS "-lreadline -lncurses -L$(CAPSTONE_REPO) -lcapstone"
VERILATOR_CFLAGS += --CFLAGS "-I$(abspath include) -I$(abspath include)/config -include $(abspath include)/config/npc_config.h"

# 构建输出目录
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

# 获取所有 C/C++ 源文件
SRCS-y += $(shell find $(abspath csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

# 黑名单处理（如果需要）
DISASM_SRC = csrc/utils/disasm.c
ifeq ($(CONFIG_ITRACE),1)
  # 启用反汇编功能
else
  SRCS-BLACKLIST-y += $(DISASM_SRC)
endif

# 源文件路径
VSRCS = $(shell find $(abspath vsrc) -name "*.v")
CSRCS = $(filter-out $(SRCS-BLACKLIST-y), $(SRCS-y))
# 默认目标：生成仿真器
default: $(BIN)

# 创建构建目录
$(shell mkdir -p $(BUILD_DIR))

# 生成仿真可执行文件
$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) \
		--Mdir $(OBJ_DIR) \
		--exe -o $(abspath $(BIN)) \
		$(VSRCS) $(CSRCS)
	@make -j -C $(OBJ_DIR) -f V$(TOPNAME).mk CXXFLAGS="$(CXXFLAGS)" LDFLAGS="-lreadline -lncurses"

# 运行仿真
run: $(BIN)
	@$(BIN)


# 清理构建产物
clean:
	rm -rf $(BUILD_DIR)

.PHONY: default run clean
