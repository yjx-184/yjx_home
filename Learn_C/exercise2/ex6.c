#include <stdio.h>

int main(int argc, char *argv[]) {
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super power.\n", super_power);
    printf("i have an inital %c.\n", initial);
    printf("i have a first name %s.\n", first_name);
    printf("i have a last name %s.\n", last_name);
    printf("my whole name is %s %c %s.\n", first_name, initial, last_name);

    return 0;
}

/*
printf格式化输出
%d , %i :   输出整数。
%u      :   输出无符号整数
%f      :   输出浮点数
%c      :   输出字符
%s      :   输出字符串
%p      :   输出指针的地址
%%      :   输出百分号%
*/