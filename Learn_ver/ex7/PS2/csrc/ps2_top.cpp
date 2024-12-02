#include <nvboard.h>
#include "Vps2_top.h"

//TOP_NAME 是宏定义，通常在 Verilator 仿真代码中，它等效于 Vtop，表示顶层 Verilog 模块。
static TOP_NAME dut;

//声明引脚绑定函数
void nvboard_bind_all_pins(TOP_NAME* top);

//时钟周期函数
//dut.eval() 是 Verilator 自动生成的仿真函数，用于根据当前输入计算出模块的输出。
static void single_cycle() {
  dut.clk = 0; dut.eval();
  dut.clk = 1; dut.eval();
}

//复位函数
static void clrn(int n) {
  dut.clrn = 0;
  while (n -- > 0) single_cycle();
  dut.clrn = 1;
}

int main() {
    nvboard_bind_all_pins(&dut);
    nvboard_init();//初始化 nvboard，设置硬件板的状态和接口。

    clrn(10);//复位模块，保持复位状态 10 个时钟周期。

    while(1) {
      nvboard_update();
      single_cycle();
    }
}