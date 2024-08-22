#include "ex22.h"
#include "dbg.h"

//创建常量
const char *MY_NAME = "Zed A.Shaw";

//创建一个函数来展示作用域问题
void scope_demo(int count)
{
    //在函数顶端打印出count的值。
    log_info("count 是: %d", count);
    //if语句会开启一个新的作用域区块，并且在其中创建了另一个count变量。
    if(count > 10) {
        int count = 100;//有漏洞

        log_info("此范围内的计数为 %d", count);
    }

    log_info("退出时计数：%d", count);

    count = 3000;

    log_info("分配后计数：%d", count);
}

int main(int argc, char *argv[])
{
    // 测试 THE_AGE 访问器
    log_info("我的名字是%s,年龄是%d", MY_NAME, get_age());

    set_age(100);

    log_info("我现在的年龄是%d", get_age());

    // 测试 THE_SIZE extern
    log_info("THE_SIZE是 %d", THE_SIZE);
    print_size();

    THE_SIZE = 9;

    log_info("现在的THE_SIZE是%d", THE_SIZE);
    print_size();

    // 测试比率函数静态
    log_info("最初比率: %f", update_ratio(2.0));
    log_info("之后比率: %f", update_ratio(10.0));
    log_info("再次比率: %f", update_ratio(300.0));

    // 测试范围演示
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("调用 scope_demo 后计数: %d", count);

    return 0;
}