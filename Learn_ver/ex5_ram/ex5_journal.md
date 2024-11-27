- [实验五 寄存器组及存储器](#实验五-寄存器组及存储器)
  - [存储器的行为和FPGA的RAM模块](#存储器的行为和fpga的ram模块)



# 实验五 寄存器组及存储器
## 存储器的行为和FPGA的RAM模块
以下存储器综合时，综合器是否会用FPGA的RAM模块来实现这个模块？
```
module ram #(
    //#(...):声明模块的参数。参数化允许在实例化时灵活地指定模块的关键属性
    parameter RAM_WIDTH = 32,           //定义存储器的每个单元宽度为32位，可以通过修改参数调整宽度。
    parameter RAM_ADDR_WIDTH = 10       //定义存储器的地址宽度位10位，即存储器有2的10次方=1024个地址空间
)(
    input clk,                          //时钟信号，触发存储器的写入操作。
    input we,                           //写的使能信号。
    input [RAM_WIDTH-1:0] din,          //写入数据输入端口，宽度为RAM_WIDTH
    input [RAM_ADDR_WIDTH-1:0] inaddr,  //写地址输入端口，用于指定数据写入的存储器地址。
    input [RAM_ADDR_WIDTH-1:0] outaddr, //读地址输入端口，用于指定要读取的数据地址。
    output [RAM_WIDTH-1:0] dout         //读数据输出端口，宽度为RAM_WIDTH
);

/*
    reg：表示存储器数组，存储的数据可以在程序运行时被修改。
    [RAM_WIDTH-1:0]：定义存储器单元的宽度，每个单元为RAM_WIDTH
    ram [(2**RAM_ADDR_WIDTH)-1:0]：定义存储器的大小，即地址范围为2的RAM_ADDR_WIDTH次方
*/
    reg [RAM_WIDTH-1:0] ram [(2**RAM_ADDR_WIDTH)-1:0];

    //写操作
    always @(posedge clk)           //时钟上升沿触发操作
        if (we)                     //当写使能信号we为高时，执行写操作
            ram[inaddr] <= din;     //将输入数据din写入到存储器地址的inaddr的位值

    //读操作
    //使用赋值语句将存储器中指定地址的数据输出到dout，通过地址outaddr获取存储器中对应位值的数据。
    assign dout = ram[outaddr];
endmodule
```
当改成：  
```
always @(posedge clk)
  if (we)
    ram[inaddr] <= din;
  else
    dout <= ram[outaddr];
```  
**原来的操作：** 在进行写操作时，时钟的上升沿，如果we为高，则将din写入地址inaddr的存储单元。在进行读操作时，由于读操作是组合逻辑实现的，与时钟无关，dout时钟反映地址outaddr对应的存储单元内容。dout的值随outaddr的改变而立即更新。  
**修改后的操作：** 写操作是在时钟上升沿，如果we为高，将din写入地址为inaddr的存储单元。读操作是在时钟上升沿，如果we为低，dout被赋值为地址outaddr对应存储单元的内容。与原来不同的是，读操作也受时钟控制。