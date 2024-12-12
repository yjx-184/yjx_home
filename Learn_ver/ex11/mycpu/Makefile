# 定义变量
TOP_MODULE = tb_mycpu
SIM_TOOL = iverilog
WAVE_VIEWER = gtkwave
DUMP_FILE = my_cpu.vcd

# 目录和文件分组
SRCS = tb_mycpu.v \
       ALU/adder_less.v ALU/adder.v ALU/alu_control.v ALU/ALU_Input_Select.v ALU/ALU.v ALU/barrel_shifter.v ALU/log_and.v ALU/log_or.v ALU/log_xor.v \
       Branch_Cond/Branch_Cond.v \
       Contr_Gen/Contr_Gen.v \
       CPU/Mycpu.v \
       Data_Mem/Data_Mem.v Data_Mem/Data_Mux.v \
       Imm_Gen/Imm_Gen.v \
       Instr_Mem/Instr_Mem.v \
       PC/PC.v PC/PCMux.v \
       Reg_File/Reg_File.v

# 编译和仿真目标
all: sim

sim: $(SRCS)
	$(SIM_TOOL) -o mycpu -g2005-sv -I ALU -I Branch_Cond -I Contr_Gen -I CPU -I Data_Mem -I Imm_Gen -I Instr_Mem -I PC -I Reg_File $(SRCS)
	./mycpu

view: $(DUMP_FILE)
	$(WAVE_VIEWER) $(DUMP_FILE)

# 清理
clean:
	rm -f simv $(DUMP_FILE)

.PHONY: all simulate view clean