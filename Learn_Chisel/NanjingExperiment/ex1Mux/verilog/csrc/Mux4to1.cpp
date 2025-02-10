#include <nvboard.h>
#include "VMux4to1.h"


//定义dut实例
//TOP_NAME 是宏定义，这里等效Vlight
static TOP_NAME dut;

//声明引脚绑定函数
void nvboard_bind_all_pins(TOP_NAME* top);

//时钟周期函数，dut.eval()用于根据当前输入计算出模块的输出。
void single_cycle() {
  dut.clock = 0; dut.eval();
  dut.clock = 1; dut.eval();
}

//复位函数
// void res(int n) {
//   dut.res = 1;
//   while (n -- > 0) single_cycle();
//   dut.res = 0;
// }

int main() {
    nvboard_bind_all_pins(&dut);
    nvboard_init();//初始化 nvboard，设置硬件板的状态和接口。
    
    // res(10);

    while(1) {
    nvboard_update();
    single_cycle();
  }
}