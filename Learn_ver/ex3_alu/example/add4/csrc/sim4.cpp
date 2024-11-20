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