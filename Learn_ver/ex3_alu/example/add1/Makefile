# 顶层模块名
TOP = add1

# 仿真目标名称
TARGET = V$(TOP)

# 文件路径
VSRCDIR = ./vsrc
CSRC = ./csrc/sim.cpp
VSRCS = $(VSRCDIR)/$(TOP).v

# 生成的对象目录
OBJDIR = ./obj_dir

# Verilator 编译器路径
VERILATOR = verilator

# 仿真器生成路径
EXE = $(OBJDIR)/$(TARGET)

# 编译选项
CFLAGS = -O3 --trace

# 默认目标
all: $(EXE)

# 生成仿真器
$(EXE): $(VSRCS) $(CSRC)
	$(VERILATOR) --cc $(VSRCS) --exe $(CSRC) $(CFLAGS) \
		--top-module $(TOP) --Mdir $(OBJDIR)
	make -C $(OBJDIR) -f V$(TOP).mk $(TARGET)

# 运行仿真
run: $(EXE)
	$(EXE)

# 清理生成文件
clean:
	rm -rf $(OBJDIR) *.vcd
