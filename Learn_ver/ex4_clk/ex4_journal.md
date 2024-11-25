- [实验四 计数器和时钟](#实验四-计数器和时钟)
  - [生成需要的时钟信号](#生成需要的时钟信号)
  - [实验验收内容（基础）](#实验验收内容基础)
    - [分频计数器 clockdivider.v](#分频计数器-clockdividerv)
    - [数码管模块seg\_clk.v](#数码管模块seg_clkv)
    - [顶层模块clk\_top.v](#顶层模块clk_topv)
    - [约束文件 clk\_top.nxdc](#约束文件-clk_topnxdc)
    - [实验时遇到的错误](#实验时遇到的错误)
      - [位宽不匹配](#位宽不匹配)
      - [仿真程序没有按预期执行](#仿真程序没有按预期执行)


# 实验四 计数器和时钟
## 生成需要的时钟信号
```
always @(posedge clk)
  if(count_clk==24999999)
  begin
    count_clk <=0;
    clk_1s <= ~clk_1s;
  end
  else
    count_clk <= count_clk+1;
```
这段代码是通过计数器count_clk实现从时钟信号clk（假设为50MHz）的分频，生成周期为1秒的信号clk_1s。count_clk起始为0,每当clk产生一个上升沿，count_clk增加1,当count_clk==24999999时，count_clk重置为0,并生成clk_1s的翻转信号，完成半个周期。已知count_clk最大值为24999999,所以需要2的n次方 > 24999999,n至少要为25,才能正确计数到24999999.宽度应该定义为reg [24:0] count_clk。

## 实验验收内容（基础）
### 分频计数器 clockdivider.v
根据要求，设计一个分频器，其输入为50MHz的时钟，输出为一个频率为1Hz，周期为1秒的时钟信号。  
```
module clockdivider(clk, reset, clk_1s);
    input clk;          //输入时钟信号
    input reset;        //异步复位信号，高电平有效
    output reg clk_1s;  //输出1秒的分频时钟

    //定义计数器
    reg [24:0] count_clk;

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            //复位条件，清零计数器和输出时钟
            count_clk <=25'd0;
            clk_1s <= 1'b0;
        end else begin
            if(count_clk == 25'd24999999) begin
                //当计数器到达目标值时，翻转信号并重置计数器
                count_clk <= 25'd0;
                clk_1s <= ~clk_1s;
            end else begin
                count_clk <= count_clk + 1;
            end
        end
    end
endmodule
```  
### 数码管模块seg_clk.v
```
module seg_clk(seg_in, seg_out);
    input [3:0] seg_in;
    output reg [7:0] seg_out;

    //定义参数
    parameter seg0 = 8'b11111101; // 数字 0
    parameter seg1 = 8'b01100000; // 数字 1
    parameter seg2 = 8'b11011010; // 数字 2
    parameter seg3 = 8'b11110010; // 数字 3
    parameter seg4 = 8'b01100110; // 数字 4
    parameter seg5 = 8'b10110110; // 数字 5
    parameter seg6 = 8'b10111110; // 数字 6
    parameter seg7 = 8'b11100000; // 数字 7
    parameter seg8 = 8'b11111111; // 数字 8
    parameter seg9 = 8'b11110111; // 数字 9

    always @(seg_in)begin
        case (seg_in)
            4'd0: seg_out = ~seg0;
            4'd1: seg_out = ~seg1;
            4'd2: seg_out = ~seg2;
            4'd3: seg_out = ~seg3;
            4'd4: seg_out = ~seg4;
            4'd5: seg_out = ~seg5;
            4'd6: seg_out = ~seg6;
            4'd7: seg_out = ~seg7;
            4'd8: seg_out = ~seg8;
            4'd9: seg_out = ~seg9;
            default: seg_out = 8'b00000000;
        endcase
    end
endmodule
```  
### 顶层模块clk_top.v
根据要求计时器有开始、暂停和清零功能，要求从00计数到99，计数值到99后重新从零开始计数。在数码管上用两位数字显示。在计时结束的时候让某一个发光二极管闪烁一个时钟周期，提示计时结束。
```
module clk_top(clk, reset, sta, seg_tens, seg_units, led_o);
    input clk;              //时钟信号
    input reset;            //异步复位
    input sta;              //状态：1开始和0停止
    output [7:0] seg_tens;  //数码管十位显示
    output [7:0] seg_units; //数码管个位显示
    output reg led_o;       //led闪烁信号

    //参数定义
    wire clk_1s;
    reg [6:0] count;    //计数器，0-99

    always @(posedge clk_1s or posedge reset) begin
        if(reset) begin
            //复位
            count <= 7'b0;
            led_o <= 1'b0;
        end else if(sta) begin
            if(count == 7'd99) begin
                count <= 7'd0;      //99后重置计数器
                led_o <= 1'b1;      //触发闪烁
            end else begin
                count <= count + 1;
                led_o <= 1'b0;
            end
        end
    end

    //分离十位数和个位数
    wire [6:0] tens_full = count / 10;
    wire [6:0] units_full = count % 10;

    wire [3:0] tens = tens_full[3:0];  // 截断到 4 位
    wire [3:0] units = units_full[3:0]; // 截断到 4 位

    //实例化
    clockdivider clkck_divider(
        .clk(clk),
        .reset(reset),
        .clk_1s(clk_1s)
    );

    seg_clk tens_seg(
        .seg_in(tens),
        .seg_out(seg_tens)
    );

    seg_clk units_seg(
        .seg_in(units),
        .seg_out(seg_units)
    );

endmodule
```
### 约束文件 clk_top.nxdc
```
top = clk_top

led_o (LD0)
reset (BTNR)
sta (SW0)
seg_units (SEG0A,SEG0B,SEG0C,SEG0D,SEG0E,SEG0F,SEG0G,DEC0P)
seg_tens (SEG1A,SEG1B,SEG1C,SEG1D,SEG1E,SEG1F,SEG1G,DEC1P)

```
### 实验时遇到的错误
#### 位宽不匹配
**问题描述：** 在clk_top.v模块中，我在分离十位数和个位数的时候，以计数器count来区分十位和个位，但第一次的时候没有处理好位宽，导致了出现警告。  
**解决方法：** 我找了一些参考资料以后，使用中间值来截取所需的4位。  

#### 仿真程序没有按预期执行
**原因及解决过程：** 一开始我是选择多两个输入，分别是开始start和暂停pasue,分别连接了两个按钮，导致程序一直是0没有计数，当我用状态sta高电平1来表示start，低电平0表示pasue的时候，问题得到了解决。我认为是按钮不能持续提供高电平,导致程序一直处于暂停状态。