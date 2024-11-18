- [实验二 译码器和编码器](#实验二-译码器和编码器)
  - [示例：2-4译码器](#示例2-4译码器)
    - [decode24.v](#decode24v)
    - [测试代码 sim.cpp](#测试代码-simcpp)
    - [编译过程](#编译过程)


# 实验二 译码器和编码器
## 示例：2-4译码器
### decode24.v
```
module decode24(x, en, y);
    input [1:0] x;
    input en;
    output reg [3:0] y;

    always @(x or en)
        if(en)
        begin
            case (x)
                2'd0 : y = 4'b0001;
                2'd1 : y = 4'b0010;
                2'd2 : y = 4'b0100;
                2'd3 : y = 4'b1000;
            endcase 
        end
        else y = 4'b0000;

endmodule
```
### 测试代码 sim.cpp
```
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vdecode24.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vdecode24* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vdecode24;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
    sim_init();

    top->en = 0b0; top->x = 0b00; step_and_dump_wave();
                   top->x = 0b01; step_and_dump_wave();
                   top->x = 0b10; step_and_dump_wave();
                   top->x = 0b11; step_and_dump_wave();
    top->en = 0b1; top->x = 0b00; step_and_dump_wave();
                   top->x = 0b01; step_and_dump_wave();
                   top->x = 0b10; step_and_dump_wave();
                   top->x = 0b11; step_and_dump_wave();

    sim_exit();
}
```
### 编译过程
```
$ verilator --cc decode24.v --exe sim.cpp --trace  

```
--cc decode24.v : 将Verilog文件decode24.v转译为c++。  
--exe sim.cpp   ：指定用于仿真的C++脚本。  
--trace         ：生成波形文件。

```
$ make -C obj_dir -f Vdecode24.mk  
```

-C obj_dir      ：进入obj_dir  
-f Vdecode24.mk ：使用Verilator生成的Makefile。  


```
$ ./obj_dir/Vdecode24  
```
运行文件  

```
$ gtkwave wave.vcd  

```
查看波形
