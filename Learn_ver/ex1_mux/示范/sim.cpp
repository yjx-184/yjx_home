#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vmux21.h"

VerilatedContext* contextp = NULL;    //Verilator 的仿真上下文对象，用于管理时间和其他全局状态。
VerilatedVcdC* tfp = NULL;            //指向 VCD 文件写入对象，用于记录信号波形。

static Vmux21* top;                   //指向顶层模块实例

//负责进行一次时间步进
void step_and_dump_wave(){
  top->eval();                        //调用顶层模块的仿真方法，计算信号的当前状态
  contextp->timeInc(1);               //将仿真时间增加1个时间单位
  tfp->dump(contextp->time());        //将当前时间点的信号状态写入VCD文件中
}

//初始化
void sim_init(){
  contextp = new VerilatedContext;    //创建 Verilator 的上下文（contextp）和波形文件对象（tfp）
  tfp = new VerilatedVcdC;
  top = new Vmux21;                   //实例化顶层模块
  contextp->traceEverOn(true);        //启用波形跟踪功能
  top->trace(tfp, 0);                 //将顶层模块的信号绑定到波形文件对象
  tfp->open("dump.vcd");              //打开波形文件，准备记录
}

//结束
void sim_exit(){
  step_and_dump_wave();               //调用 step_and_dump_wave 确保记录最后一个时间点的信号状态。
  tfp->close();                       //关闭 VCD 文件
}

int main() {
  sim_init();   //初始化

  top->s=0; top->a=0; top->b=0;  step_and_dump_wave();   // 将s，a和b均初始化为“0”
                      top->b=1;  step_and_dump_wave();   // 将b改为“1”，s和a的值不变，继续保持“0”，
            top->a=1; top->b=0;  step_and_dump_wave();   // 将a，b分别改为“1”和“0”，s的值不变，
                      top->b=1;  step_and_dump_wave();   // 将b改为“1”，s和a的值不变，维持10个时间单位
  top->s=1; top->a=0; top->b=0;  step_and_dump_wave();   // 将s，a，b分别变为“1,0,0”，维持10个时间单位
                      top->b=1;  step_and_dump_wave();
            top->a=1; top->b=0;  step_and_dump_wave();
                      top->b=1;  step_and_dump_wave();

  sim_exit();
}