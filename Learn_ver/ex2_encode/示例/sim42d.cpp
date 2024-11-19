#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vencode42d.h"

//全局变量定义
VerilatedContext* contextp = NULL;  //定义仿真上下文指针，用于管理仿真时间、状态等。
VerilatedVcdC* tfp = NULL;  //定义一个只想波形文件的指针，用于记录仿真过程中产生的信号变化。
static Vencode42d* top;  //定义一个指向顶层模块Vencode42d的实例指针，用于仿真该模块

//仿真辅助函数
void step_and_dump_wave(){      //该函数作用：模拟单个时间步长，并将信号写入波形文件
  top->eval();                  //计算模块当前时刻的输出
  contextp->timeInc(1);         //仿真时间前进1单位
  tfp->dump(contextp->time());  //将当前时间点的信号写入波形文件
}
void sim_init(){                    //该函数作用：初始化仿真环境，包括上下文、波形记录和模块实例
  contextp = new VerilatedContext;  //创建仿真上下文对象
  tfp = new VerilatedVcdC;          //创建波形记录对象
  top = new Vencode42d;              //创建顶层模块实例
  contextp->traceEverOn(true);      //启用波形跟踪功能
  top->trace(tfp, 0);               //将顶层模块的信号连接到波形记录对象
  tfp->open("dump42d.vcd");            //打开名为“dump42d.vcd”的波形文件
}

void sim_exit(){        //该函数作用：结束仿真并关掉所有资源
  step_and_dump_wave(); //仿真最后一个步长并记录波形
  tfp->close();         //关闭波形文件
}

int main() {
    sim_init();     //初始化仿真环境

    //当使能en信号为0时
    top->en = 0; top->in_code = 0b0001; step_and_dump_wave();
                 top->in_code = 0b0010; step_and_dump_wave();
                 top->in_code = 0b0100; step_and_dump_wave();
                 top->in_code = 0b1000; step_and_dump_wave();

    //当使能en信号为1时
    top->en = 1; top->in_code = 0b0001; step_and_dump_wave();
                 top->in_code = 0b0010; step_and_dump_wave();
                 top->in_code = 0b0100; step_and_dump_wave();
                 top->in_code = 0b1000; step_and_dump_wave();

    //当高位为1时，优先选择高位
                 top->in_code = 0b1010; step_and_dump_wave();
                 top->in_code = 0b1100; step_and_dump_wave();

    sim_exit();
    return 0;
}