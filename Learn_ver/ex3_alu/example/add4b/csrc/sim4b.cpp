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