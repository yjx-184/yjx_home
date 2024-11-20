

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