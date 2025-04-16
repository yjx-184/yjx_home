# 设置默认目标（如果不指定目标，则 `make` 默认执行 `app` 规则）
.DEFAULT_GOAL = app

# Add necessary options if the target is a shared library
# 如果目标是共享库，则添加必要的编译选项
ifeq ($(SHARE),1)
SO = -so
# 生成位置无关代码，并隐藏符号
CFLAGS  += -fPIC -fvisibility=hidden
# 生成共享库
LDFLAGS += -shared -fPIC
endif

# 目录定义
# 当前工作目录
WORK_DIR  = $(shell pwd)
# 构建输出目录
BUILD_DIR = $(WORK_DIR)/build

# 头文件路径
INC_PATH := $(WORK_DIR)/include $(INC_PATH)
# 对象文件存放目录
OBJ_DIR  = $(BUILD_DIR)/obj-$(NAME)$(SO)
# 生成的二进制文件路径
BINARY   = $(BUILD_DIR)/$(NAME)$(SO)

# Compilation flags
# 选择编译器
ifeq ($(CC),clang)
# 如果 CC 变量被设置为 `clang`，则使用 `clang++`
CXX := clang++
else
# 否则使用 `g++`
CXX := g++
endif
# 连接器
LD := $(CXX)

# 头文件包含路径
INCLUDES = $(addprefix -I, $(INC_PATH))

# 编译选项
 # 优化级别 O2，生成依赖文件，启用所有警告，并将警告视为错误
CFLAGS  := -O2 -MMD -Wall -Werror $(INCLUDES) $(CFLAGS)
# 连接选项，优化级别 O2
LDFLAGS := -O2 $(LDFLAGS)

# 源文件编译后的对象文件列表
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o) $(CXXSRC:%.cc=$(OBJ_DIR)/%.o)

# Compilation patterns
# C 语言文件的编译规则
$(OBJ_DIR)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

# C++ 语言文件的编译规则
$(OBJ_DIR)/%.o: %.cc
	@echo + CXX $<
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

# Depencies
# 依赖管理：包含所有 .d 依赖文件
-include $(OBJS:.o=.d)

# Some convenient rules
# 定义预处理结果存放目录
PREPROC_DIR = $(BUILD_DIR)/preproc

# 将所有 .c 源文件映射为对应的预处理文件 (.i)
PREPROC_SRCS = $(patsubst %.c,$(PREPROC_DIR)/%.i,$(SRCS))

# 为 .c 文件生成预处理结果的规则
$(PREPROC_DIR)/%.i: %.c
	@echo + Preprocessing $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -E $< -o $@

.PHONY: preprocess
preprocess: $(PREPROC_SRCS)
	@echo "所有源文件的预处理结果已生成。"

# 预处理rules结束

.PHONY: app clean

app: $(BINARY)

$(BINARY):: $(OBJS) $(ARCHIVES)
	@echo + LD $@
	@$(LD) -o $@ $(OBJS) $(LDFLAGS) $(ARCHIVES) $(LIBS)

clean:
	-rm -rf $(BUILD_DIR)
