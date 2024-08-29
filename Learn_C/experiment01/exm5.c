
#include <stdio.h>
 
int main()
{
    // 定义指向char类型的指针s
    char* s = "hello world.";
    // 定义指向int类型的指针a
    int x = 11;
    int* a = &x;
 
    // 打印指针s所指向的字符串内容
    printf("s is: %s\n", s);
    printf("s + 1 is: %s\n", s + 1);
 
    // 打印指向char类型的指针类型（s）的大小
    printf("char类型的指针类型（s）的大小: %ld\n", sizeof(s));
 
    // 打印指向int类型的指针类型（a）的大小
    printf("int类型的指针类型（a）的大小: %ld\n", sizeof(a));
 
    // 打印指针s以及s+1中保存的地址信息
    printf("s的地址是: %p\n", s);
    printf("s + 1 的地址是: %p\n", s + 1);
 
    // 打印指针a以及a+1中保存的地址信息
    printf("a的地址是: %p\n", a);
    printf("a + 1的地址是: %p\n", a + 1);
 
    return 0;
}
/*
运行结果：
s is: hello world.
s + 1 is: ello world.
char类型的指针类型（s）的大小: 8
int类型的指针类型（a）的大小: 8
s的地址是: 0x5f4a617ee008
s + 1 的地址是: 0x5f4a617ee009
a的地址是: 0x7fff1999d9e4
a + 1的地址是: 0x7fff1999d9e8


*/