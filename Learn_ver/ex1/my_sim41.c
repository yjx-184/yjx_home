#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vmy_mux41.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmy_mux41* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vmy_mux41;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("my_dump41.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();
    
    // 初始化4个输入信号
    top->X0 = 0b00;
    top->X1 = 0b01;
    top->X2 = 0b10;
    top->X3 = 0b11;

    // 测试 Y 为不同值时的行为
    top->Y = 0b00;  step_and_dump_wave();
    top->Y = 0b01;  step_and_dump_wave();
    top->Y = 0b10;  step_and_dump_wave();
    top->Y = 0b11;  step_and_dump_wave();

    sim_exit();
}