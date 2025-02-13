# 定义工程的顶层模块名称和约束文件
TOPNAME = Top
NXDC_FILES = constr/Top.nxdc

# 头文件包含路径（可选）
INC_PATH ?=

# Verilator的路径和编译标志
VERILATOR = verilator
# Verilator编译标志，设置优化等级、跳过部分检查，提升性能
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

# 构建输出目录和二进制文件路径
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

# 默认目标：生成仿真器
default: $(BIN)

# 创建构建目录（如果不存在）
$(shell mkdir -p $(BUILD_DIR))

# 约束文件自动生成绑定代码
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# 项目的 Verilog 源文件，查找vsrc目录下所有.v文件以及项目的C源文件（包括 .c, .cc, .cpp）
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
# 添加自动生成的绑定代码
CSRCS += $(SRC_AUTO_BIND)

# NVBoard的相关规则（用于仿真调试）
include $(NVBOARD_HOME)/scripts/nvboard.mk

# Verilator编译器的附加标志
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

# 目标：生成仿真器的可执行文件
$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)	# 依赖Verilog,C++,NVBoard库
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

# 'all'目标，执行默认目标
all: default

# 'run'目标，运行生成的仿真器
run: $(BIN)
	@$^

# 'clean'目标，清理构建目录
clean:
	rm -rf $(BUILD_DIR)

# .PHONY：声明伪目标，不生成对应的文件
.PHONY: default all clean run

#接入NVBoard之前的遗留规则
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

include ~/ysyx-workbench/Makefile
