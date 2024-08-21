#include <stdio.h>

int main(int argc, char *argv[]) {
    int numbers[4] = {0};
    char name[4] = {'a'};

    //first, print them out raw
    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

    printf("name each :%c %c %c %c\n", name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    //setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    //setup the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';


    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

    printf("name each :%c %c %c %c\n", name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);


    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

    return 0;
}
/*
将一些字符赋给numbers的元素，之后用printf一次打印一个字符，你会得到什么编译器警告？
答：会提示未声明


对names执行上述的相反操作，把names当成int数组，并一次打印一个int，Valgrind会提示什么？
答：name each :   
name:      都输出空白

*/