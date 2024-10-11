#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "Vtop.h"

int main() {
    
    srand(time(NULL));
    //实例化
    Vtop* top = new Vtop;

    while(true) {

        //随机生存01
        int a = rand() & 1;
        int b = rand() & 1;

        //将随机数赋给输入端口
        top->a = a;
        top->b = b;

        //评估模块
        top->eval();

        printf("a = %d, b = %d, f= %d\n", a, b, top->f);

        assert(top->f == (a ^b));
    }
    delete top;
    return 0;
}