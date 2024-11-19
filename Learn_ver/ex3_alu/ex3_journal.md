

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
