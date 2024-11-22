

# 实验三 加法器与ALU
## 一位全加器
![](./pic/add1.png)  
### add1.v
```
module add1(a_i, b_i, c_i, s_i, c_o);
    input a_i;      //待加位a
    input b_i;      //待加位b
    input c_i;      //待加进位ci
    output s_i;     //结果和s
    output c_o;     //下一位进位c_i+1

    //si = （a异或b）异或ci
    assign s_i = (a_i ^ b_i) ^ c_i;

    //c_i+1进位运算
    assign c_o = ((a_i ^ b_i)&c_i) | (a_i & b_i);

endmodule
```
### 测试模块
```
#include "Vadd1.h"
#include "verilated.h"
#include <stdio.h>

//测试一位加法器函数
void test_add1(int a, int b, int c) {
    //创建仿真模块对象
    Vadd1* add1 = new Vadd1;

    //设置输入
    add1->a_i = a;
    add1->b_i = b;
    add1->c_i = c;

    //计算
    add1->eval();

    //输出结果
    printf("%d,  %d,  %d ,  %d,  %d\n",
           c, b, a, add1->s_i, add1->c_o);
    delete add1;
}

int main(int argc, char** argv) {
    //初始化
    Verilated::commandArgs(argc, argv);

    printf("Ci, ai, bi, Si, C_i+1\n");

    for(int c = 0; c <= 1; c++) {
        for(int b = 0; b <= 1; b++) {
            for(int a = 0; a <= 1; a++) {
                test_add1(a, b, c);
            }
        }
    }
    return 0;
}
```
### 运行结果
![](./pic/add12.png)  

## 四位串行全加器
### add4.v
```
module add4(a,b,ci,sum,co);
    input [3:0] a;
    input [3:0] b;
    input ci;
    output [3:0] sum;
    output co;
    wire [3:0] count;

    //实例化加法器
    add1 u0(a[0], b[0], ci, sum[0], count[0]);
    add1 u1(a[1], b[1], count[0], sum[1], count[1]);
    add1 u2(a[2], b[2], count[1], sum[2], count[2]);
    add1 u3(a[3], b[3], count[2], sum[3], count[3]);
    assign co = count[3];

endmodule

module add1(a, b, ci, sum, co);
    input a;
    input b;
    input ci;
    output sum;
    output co;

    //和
    assign sum = (a ^ b) ^ ci;

    //c_i+1进位运算
    assign co = ((a ^ b)&ci) | (a & b);

endmodule
```

### 测试 sim4.cpp
```
#include "Vadd4.h"
#include "verilated.h"
#include <bitset>
#include <iostream>

void test_add4(int a, int b, int ci ) {
    //创建仿真模块对象
    Vadd4* add4 = new Vadd4;

    //设置输入
    add4->a = a;
    add4->b = b;
    add4->ci = ci;

    //计算
    add4->eval();

    //输出结果
    std::cout << "a: " << std::bitset<4>(a)
              << ", b: " << std::bitset<4>(b)
              << ", ci: " << ci
              << " -> sum: " << std::bitset<4>(add4->sum)
              << ", co: " << std::bitset<4>(add4->co)
              << std::endl;

    delete add4;
}

int main(int argc, char** argv) {
    //初始化
    Verilated::commandArgs(argc, argv);

    for (int ci = 0; ci <= 1; ci++) {
        for (int a = 0; a <= 15; a++) {  // 4 位输入 a
            for (int b = 0; b <= 15; b++) {  // 4 位输入 b
                test_add4(a, b, ci);
            }
        }
    }
    return 0;
}
```
## 使用算术赋值语句和向量重新实验 四位加法器
### add4b.v
```

//使用算术赋值语句和向量来实现4位加法器

module add4b(a,b,sum,co);
    input [3:0] a;
    input [3:0] b;
    output [3:0] sum;
    output co;

    assign {co,sum} = a + b;

endmodule

```

### 测试 sim4b.cpp
```
#include "Vadd4b.h"
#include "verilated.h"
#include <iomanip> 
#include <iostream>
#include <bitset> 

void test_add4b(int a, int b) {
    //创建仿真模块对象
    Vadd4b* add4b = new Vadd4b;

    //设置输入
    add4b->a = a;
    add4b->b = b;

    //计算
    add4b->eval();

    //输出结果
    std::cout << "a: " << std::bitset<4>(a)
              << ", b: " << std::bitset<4>(b)
              << " -> sum: " << std::bitset<4>(add4b->sum)
              << ", co: " << static_cast<int>(add4b->co)
              << std::endl;

    delete add4b;
}

int main(int argc, char** argv) {
    //初始化
    Verilated::commandArgs(argc, argv);

    for (int a = 0; a < 16; ++a) {
        for (int b = 0; b < 16; ++b) {
            test_add4b(a, b);
        }
    }
    return 0;
}
```

## 简单加减法运算器的设计
### 对实验讲义中提出的方法进行思考
**方法一：**  
```
assign t_no_Cin = {n{ Cin }}^B;
assign {Carry,Result} = A + t_no_Cin + Cin;
assign Overflow = (A[n-1] == t_no_Cin[n-1]) && (Result [n-1] != A[n-1]);
```  

第一步是将 Cin 复制 n 位等同于 {Cin, Cin, Cin, Cin....n个},并逐位与B进行异或操作。  
第二步是算术表达式，将Cin既参与异或操作也参与加法操作。  
第三步是溢出信号判断。

***
***
**方法二：**  
```
assign t_add_Cin =( {n{Cin}}^B )+ Cin;  //  在这里请注意^运算和+运算的顺序
assign { Carry, Result } = A + t_add_Cin;
assign Overflow = (A[n-1] == t_add_Cin[n-1]) && (Result [n-1] != A[n-1]);
```  

第一步是将Cin 复制 n 位并逐位与B进行异或操作然后再加上Cin。  
第二步是算术表达式，这次的操作包含了预算计算的Cin。  
第三步是溢出信号判断。  

***
***
**二者对比**  
1.方法二使用括号明确了运算顺序，先进行异或操作然后再加上Cin。  
2.方法一中，Cin既参与异或，也参与最终的加法。方法二将Cin提前加到了t_add_Cin 中，将逻辑等价转化为结构化计算。  
总结：方法二明确了运算顺序，能减少误读风险，同时更具结构化，方便复用。  

### subadd.v
```
module subadd(a,b,cin,carry,overflow,result,zero);
    input [3:0] a;          //操作数a
    input [3:0] b;          //操作数b
    input cin;              //控制加减法，sub为1,add为0
    output carry;           //进位
    output overflow;         //溢出
    output [3:0] result;    //结果
    output zero;            //零判断位

    wire [3:0] t_add_cin;   //中间变量，用于存储经过cin控制的b的处理结果

    //功能实现，通过控制cin来实现加法和减法逻辑
    assign t_add_cin = ({4{cin}}^b) + cin;
    assign {carry, result} = a + t_add_cin;
    assign overflow = (a[3] == t_add_cin[3]) && (result[3] != a[3]);

    assign zero = ~(| result);
    
endmodule
```  
在功能的实现上，使用了讲义所提到的减法的处理。

### subadd_tb.v
```
`timescale 1ns / 1ps

module subadd_tb;

    //输入信号
    reg signed [4:0] i, j;          //测试输入，扩展为5位以检测溢出
    reg inputaluop;                 //控制信号，加法0,减法1
    reg [3:0] inputa, inputb;       //加法器的输入

    //输出信号
    wire [3:0] outputs;             //输出结果
    wire resultc, resultof, resultz;//进位，溢出，零标志位

    //预期结果
    reg [4:0] k;                    //计算结果扩展为5位
    reg of, c, z;                   //预期的溢出，进位，零位

    //实例化
    subadd uut (
        .a(inputa),
        .b(inputb),
        .cin(inputaluop),
        .carry(resultc),
        .overflow(resultof),
        .zero(resultz)
    );

    //错误计数器
    integer errors = 0;

    //测试任务
    task check;
        input [3:0] results;        //alu的结果预期正确输出
        input resultof, resultc, resultz;   //alu的预期溢出，进位，零位
        begin
            //比较预期结果和测试单元输出的outputs
            if(outputs != results)  
                begin
                    $display("Error:a = %h, b = %h, ctrl = %b,sum should be %h,get %h\n", inputa, inputb, inputaluop, results, outputs);
                    errors = errors + 1;
                end

            //比较预期溢出和测试单元溢出的resultof
            if(resultof != of)
                begin
                    $display("overflow Error:a = %h, b = %h, ctrl = %b,overflow should be %b,get %b\n", inputa, inputb, inputaluop, of, resultof);
                    errors = errors + 1; 
                end

            //比较预期进位和测试单元进位的resultc
            if(resultc != c)
                begin
                    $display("carry Error:a = %h, b = %h, ctrl = %b,carry should be %b, get %b\n",inputa, inputb, inputaluop, c, resultc);
                    errors = errors + 1; 
                end

            //比较预期零位和测试单元零位的resultz
            if(resultz != z)
                begin
                    $display("zero Error:a = %h, b = %h,ctrl = %b, zero should be %b,get %b\n",inputa, inputb, inputaluop, z, resultz);
                    errors = errors + 1; 
                end
        end
        endtask

        //测试流程
        initial begin
            $display("开始测试subadd.v ......\n");

            //遍历
            for(i = -8; i <= 7; i = i+1)
            begin
                for(j = -8; j <= 7; j = j+1)
                begin
                    inputa = i[3:0];
                    inputb = j[3:0];            //设置两个输入
                    inputaluop = 4'b0000;       //alu的操作码
                    k = i + j;                  //计算加法预期结果
                    of = ((i[3] == j[3]) && (k[4] != k[3]));    //溢出检测
                    z = (k[3:0] == 0);          //零位
                    c = (k[4] == 1);            //进位
                    #20 check(k[3:0],of,c,z);
                end
        end

        //显示测试结果
        if (errors == 0) begin
            $display("所有测试通过，没有出错！");
        end else begin
            $display("有%d个错误", errors);
        end
        $stop;
        end
    endmodule
```
### 测试结果
![](./pic/subadd_tb.png)

## ALU设计：对讲义中比较运算尝试分析
![](./pic/alu_fenxi.png)  

### 带符号
Out_s(n-1)表示减法结果的符号位（最高位）。当未溢出时，结果为负（符号位为1），表示A < B。  
Overflow是溢出信号。  

1.当Outs(n-1) = 1, Overflow = 0:符号位正确，结果为负，表示A < B，Less(s) = 1;  
2.当Outs(n-1) = 1, Overflow = 1:符号位错误，修正后 A >= B, Less(s) = 0;
3.当Outs(n-1) = 0, Overflow = 0:符号位正确，结果非负，表示A >=B, Less(s) = 0;  
4.当Outs(n-1) = 0, Overflow = 1:符号位错误,修正后 A < B,Less(s) = 1;  

### 无符号
cin是借位信号。Carry是最高位的进位信号。A < B 等价为 A -B < 0 等价为A + ~B+1 < 0.用上文讲义所提到的对减法的处理方法。

## 验收实验：实现一个带有逻辑运算的简单ALU
### 加法器adder.v
```
module adder(i_a, i_b,cin,o_carry,o_overflow,o_result,zero);
    input [3:0] i_a;          //操作数a
    input [3:0] i_b;          //操作数b
    input cin;                //控制加减法，sub为1,add为0
    output o_carry;           //进位
    output o_overflow;        //溢出
    output [3:0] o_result;    //结果
    output zero;            //零判断位

    wire [3:0] t_add_cin;   //中间变量，用于存储经过cin控制的b的处理结果


    //功能实现，通过控制cin来实现加法和减法逻辑
    assign t_add_cin = ({4{cin}}^i_b) + {3'b0,cin};
    assign {o_carry, o_result} = i_a + t_add_cin;
    assign o_overflow = (i_a[3] == t_add_cin[3]) && (o_result[3] != i_a[3]);

    assign zero = ~(| o_result);
    
endmodule
```
### 逻辑操作
```
//取反
module log_not(i_a, o_result);
    input [3:0] i_a;
    output [3:0] o_result;

    assign o_result = ~i_a;

endmodule

//与
module log_and(i_a, i_b, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output [3:0] o_result;

    assign o_result = i_a & i_b;

endmodule

//或
module log_or(i_a, i_b, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output [3:0] o_result;

    assign o_result = i_a | i_b;

endmodule

//异或
module log_xor(i_a, i_b, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output [3:0] o_result;

    assign o_result = i_a ^ i_b;
endmodule

//比较大小
module log_max(i_a, i_b, o_max, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output o_max;
    output [3:0] o_result;

    assign o_max = (i_a > i_b)?1'b1:1'b0;
    assign o_result = (i_a > i_b)?i_a:i_b;

endmodule

//相等
module log_equ(i_a, i_b, o_equ, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output o_equ;
    output [3:0] o_result;

    assign o_equ = (i_a == i_b)?1'b1:1'b0;
    assign o_result = i_a;

endmodule
```
### 数码管 seg.v
```
module seg(i_signbit, seg_in, seg_out);
    input i_signbit;            // 控制是否输出符号位
    input [3:0] seg_in;         // 4位的输入
    output reg [7:0] seg_out;   // 8位输出，对数码管的控制信号

    // 参数定义：数码管显示编码
    parameter seg0 = 8'b11111101; // 数字 0
    parameter seg1 = 8'b01100000; // 数字 1
    parameter seg2 = 8'b11011010; // 数字 2
    parameter seg3 = 8'b11110010; // 数字 3
    parameter seg4 = 8'b01100110; // 数字 4
    parameter seg5 = 8'b10110110; // 数字 5
    parameter seg6 = 8'b10111110; // 数字 6
    parameter seg7 = 8'b11100000; // 数字 7
    parameter seg8 = 8'b11111111; // 数字 8

    always @(*) begin
        // 当收到i_signbit = 0,无符号数显示 (0 到 7)
        if (~i_signbit) begin
            case (seg_in)
                4'd0:  seg_out = ~seg0;
                4'd1:  seg_out = ~seg1;
                4'd2:  seg_out = ~seg2;
                4'd3:  seg_out = ~seg3;
                4'd4:  seg_out = ~seg4;
                4'd5:  seg_out = ~seg5;
                4'd6:  seg_out = ~seg6;
                4'd7:  seg_out = ~seg7;
                4'd8:  seg_out = ~seg8;
                default: seg_out = 8'b00000000; // 默认熄灭
            endcase
        end
        // 有符号数显示 (-1 到 -8)
        else begin
            case (seg_in)
                4'd1:  seg_out = ~seg1; // 显示 -1
                4'd2:  seg_out = ~seg2; // 显示 -2
                4'd3:  seg_out = ~seg3; // 显示 -3
                4'd4:  seg_out = ~seg4; // 显示 -4
                4'd5:  seg_out = ~seg5; // 显示 -5
                4'd6:  seg_out = ~seg6; // 显示 -6
                4'd7:  seg_out = ~seg7; // 显示 -7
                4'd8:  seg_out = ~seg8; // 显示 -8
                default: seg_out = 8'b00000000; // 默认熄灭
            endcase
        end
    end
endmodule

```

### 综合模块 alu_top.v
```
module alu_top(i_a, i_b, i_op, o_result, o_cin, o_carry, o_overflow, o_max, o_equ, o_zero, o_signbit, o_seg);
    input [3:0] i_a;        //4位输入数a
    input [3:0] i_b;        //4位输入数b
    input [2:0] i_op;       //3位操作码，选择alu的操作
    output [3:0] o_result;  //4位运算结果
    output o_cin;           //输出1位加减法的控制标志
    output o_carry;         //输出1位进位标志
    output o_overflow;      //输出1位溢出标志
    output o_max;           //输出1位最大值标志
    output o_equ;           //输出1位相等标志
    output o_zero;          //输出零位标志
    output [7:0] o_signbit; //符号位标志
    output [7:0] o_seg;     //7段数码管控制信号

    //中间信号
    //加法与减法的控制码
    wire cin_0, cin_1;
    //不同运算结果
    wire [3:0] result_0, result_1, result_2, result_3, result_4, result_5, result_6, result_7, o_result_0;
    //加法和减法的进位信号
    wire carry_0, carry_1;
    //加法和减法的溢出信号
    wire overflow_0, overflow_1;
    //零位
    wire zero_0, zero_1;
    //比较运算
    wire max_0, equ_0;


    //控制信号逻辑
    assign cin_0 = 1'b0;  // 初始化加法的控制信号，固定为0
    assign cin_1 = 1'b1;  // 初始化减法的控制信号，固定为1
    assign o_max = (i_op == 3'b110)?max_0:1'b0;     //当操作码到110,o_max输出比较结果
    assign o_equ = (i_op == 3'b111)?equ_0:1'b0;     //当操作码到111,o_equ输出是否相等
    assign o_result = o_overflow?4'b0:o_result_0;   //如果发生溢出，o_result输出全0,否则输出o_led_0


    //符号位控制,当最高位为1时点亮-号，否则熄灭
    assign o_signbit = o_result[3]?8'b11111101:8'b11111111;

    //绝对值处理
    wire [3:0] abs_result;
    assign abs_result = o_result[3] ? (~o_result + 1) : o_result; // 若为负数，取补码

    //实例化
    //加法模块
    adder u0_adder(
        .i_a(i_a),
        .i_b(i_b),
        .cin(cin_0),
        .o_carry(carry_0),
        .o_overflow(overflow_0),
        .o_result(result_0),
        .zero(zero_0)
    );

    //减法模块
    adder u1_adder(
        .i_a(i_a),
        .i_b(i_b),
        .cin(cin_1),
        .o_carry(carry_1),
        .o_overflow(overflow_1),
        .o_result(result_1),
        .zero(zero_1)
    );

    //逻辑运算
    //取反
    log_not u0_log_not(
        .i_a(i_a), 
        .o_result(result_2)
    );

    //与
    log_and u0_log_and(
        .i_a(i_a), 
        .i_b(i_b), 
        .o_result(result_3)
    );

    //或
    log_or u0_log_or(
        .i_a(i_a), 
        .i_b(i_b), 
        .o_result(result_4)
    );

    //异或
    log_xor u0_log_xor(
        .i_a(i_a), 
        .i_b(i_b), 
        .o_result(result_5)
    );

    //比较大小
    log_max u0_log_max(
        .i_a(i_a),
        .i_b(i_b),
        .o_max(max_0),
        .o_result(result_6)
    );
    
    //判断相等
    log_equ u0_log_equ(
        .i_a(i_a),
        .i_b(i_b),
        .o_equ(equ_0),
        .o_result(result_7)
    );

    //数码管模块
    seg u0_seg(
        .i_signbit(o_result[3]),
        .seg_in(abs_result),
        .seg_out(o_seg)
    );

    //加减法标志选择
    MuxKey #(2,3,1) i0(o_cin, i_op, {
    3'b000, cin_0,  // 加法的标志
    3'b001, cin_1   // 减法的标志
    });

    //进位标志选择
    MuxKey #(2,3,1) i1(o_carry, i_op, { 
        3'b000, carry_0, // 加法的进位
        3'b001, carry_1  // 减法的进位
    });

    //溢出标志选择
    MuxKey #(2,3,1) i2(o_overflow, i_op, { 
        3'b000, overflow_0, // 加法的溢出
        3'b001, overflow_1  // 减法的溢出
    });

    //结果输出选择
    MuxKey #(8,3,4) i3(o_result_0, i_op, { 
        3'b000, result_0,   // 加法
        3'b001, result_1,   // 减法
        3'b010, result_2,   // 取反
        3'b011, result_3,   // 与
        3'b100, result_4,   // 或
        3'b101, result_5,   // 异或
        3'b110, result_6,   // 较大值
        3'b111, result_7    // 判断相等
    });

endmodule
```
### 约束文件 aly_top.nxdc
```
top=alu_top

i_a (SW3,SW2,SW1,SW0)
i_b (SW7,SW6,SW5,SW4)
i_op (SW14,SW13,SW12) 
i_op (LD14,LD13,LD12)
o_result (LD3,LD2,LD1,LD0)
o_cin (LD5)
o_carry (LD6)
o_overflow (LD7)
o_max (LD8)
o_equ (LD9)
o_zero (LD10)
o_signbit (SEG1A,SEG1B,SEG1C,SEG1D,SEG1E,SEG1F,SEG1G,DEC1P)
o_seg (SEG0A,SEG0B,SEG0C,SEG0D,SEG0E,SEG0F,SEG0G,DEC0P)
```

### 实验过程中出现的问题
#### 问题1：当操作码位001时应该实现减法，但在nvborad上仍然是实现加法
**原因：** 应该是没有正确初始化加减法的控制标志0_cin。  
**解决办法：** 在定义完参数后，对其进行了初始化。
```
    assign cin_0 = 1'b0;  // 初始化加法的控制信号，固定为0
    assign cin_1 = 1'b1;  // 初始化减法的控制信号，固定为1
```
#### 问题2：数码管无法正确显示负数(一直是-8)
**原因：** 在负数情况下，未对输入的绝对值进行处理，直接传递负数到数码管显示模块。  
**解决办法：** 在 alu_top.v 中，对负数取绝对值后传递给数码管显示模块。  
```
    //绝对值处理
    wire [3:0] abs_result;
    assign abs_result = o_result[3] ? (~o_result + 1) : o_result; // 若为负数，取补码
```
