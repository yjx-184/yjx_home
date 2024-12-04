# 定义项目路径，使用 `pwd` 命令获取当前工作目录路径。
PROJ_PATH = $(shell pwd)

# 定义设计模块名称
DESIGN ?= ps2_top

# 定义时序约束文件
SDC_FILE ?= $(PROJ_PATH)/ex7_yosys/ps2_top.sdc

# 使用 `find` 命令在 文件夹中查找所有 `.v` 后缀的 Verilog 源代码文件。
RTL_FILES ?= $(shell find $(PROJ_PATH)/ex7_yosys -name "*.v")

# 定义时钟频率，默认设置为500 MHz
export CLK_FREQ_MHZ ?= 500

# 定义结果目录路径，将综合、修正和分析结果保存在 `result/设计名称-时钟频率` 目录下。
RESULT_DIR = $(PROJ_PATH)/result/$(DESIGN)-$(CLK_FREQ_MHZ)MHz

# 定义脚本目录路径，所有综合、修正和时序分析的脚本存放在此目录下。
SCRIPT_DIR = $(PROJ_PATH)/scripts

# 定义综合后的网表文件路径，存放在结果目录中。
NETLIST_SYN_V   = $(RESULT_DIR)/$(DESIGN).netlist.syn.v

# 定义修正风扇效应后的网表文件路径，存放在结果目录中。
NETLIST_FIXED_V = $(RESULT_DIR)/$(DESIGN).netlist.fixed.v

# 定义时序分析报告文件路径，存放在结果目录中。
TIMING_RPT = $(RESULT_DIR)/$(DESIGN).rpt

# 运行初始化目标，从指定 URL 下载并运行一个脚本，用于设置 Yosys 和 STA 工具环境。
init:
	bash -c "$$(wget -O - https://ysyx.oscc.cc/slides/resources/scripts/init-yosys-sta.sh)"

# 定义 `syn` 目标，依赖于综合生成的网表文件 `$(NETLIST_SYN_V)`。
syn: $(NETLIST_SYN_V)
$(NETLIST_SYN_V): $(RTL_FILES) $(SCRIPT_DIR)/yosys.tcl
	mkdir -p $(@D)
	echo tcl $(SCRIPT_DIR)/yosys.tcl $(DESIGN) \"$(RTL_FILES)\" $@ | yosys -l $(@D)/yosys.log -s -

# 定义 `fix-fanout` 目标，依赖修正风扇效应后的网表文件 `$(NETLIST_FIXED_V)`。
fix-fanout: $(NETLIST_FIXED_V)
$(NETLIST_FIXED_V): $(SCRIPT_DIR)/fix-fanout.tcl $(SDC_FILE) $(NETLIST_SYN_V)
	./bin/iEDA -script $^ $(DESIGN) $@ 2>&1 | tee $(RESULT_DIR)/fix-fanout.log

# 定义 `sta` 目标，依赖于时序分析报告 `$(TIMING_RPT)`。
sta: $(TIMING_RPT)
$(TIMING_RPT): $(SCRIPT_DIR)/sta.tcl $(SDC_FILE) $(NETLIST_FIXED_V)
	./bin/iEDA -script $^ $(DESIGN) 2>&1 | tee $(RESULT_DIR)/sta.log

clean:
	-rm -rf result/

.PHONY: init syn fix-fanout sta clean
