#!/bin/bash

# 设置文件名变量
MODULE_FILE="reg_control.v"
TESTBENCH_FILE="tb_reg_control.v"
OUTPUT_FILE="sim_output"

# 清理旧的输出文件
rm -f $OUTPUT_FILE dump.vcd

# 编译 Verilog 文件
iverilog -o $OUTPUT_FILE $MODULE_FILE $TESTBENCH_FILE
if [ $? -ne 0 ]; then
    echo "Error: 编译失败!"
    exit 1
fi

# 运行仿真
vvp $OUTPUT_FILE
if [ $? -ne 0 ]; then
    echo "Error: 模拟失败!"
    exit 1
fi

# 查看波形文件
if [ -f "dump.vcd" ]; then 
    echo "模拟成功。使用 GTKWave 查看波形："
    echo "gtkwave dump.vcd"
else
    echo "模拟完成，但未找到 VCD 文件。"
fi
