#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

int print_a_message(const char *msg)
{
    printf("字符串: %s\n", msg);
    return 0;
}

//大写
int uppercase(const char *msg)
{
    check(msg != NULL, "收到一个 NULL 指针。");
    int i = 0;
    for(i = 0; msg[i] != '\0'; i++) {
        printf("%c", toupper(msg[i]));//转换成大写
    }

    printf("\n");

    return 0;
error:

    return 1;
}

int lowercase(const char *msg)
{
    check(msg != NULL, "收到一个 NULL 指针。");
    int i = 0;
    for(i = 0; msg[i] != '\0'; i++) {
        printf("%c", tolower(msg[i]));//转化成小写
    }

    printf("\n");

    return 0;
error:

    return 1;
}

//目标失败
int fail_on_purpose(const char *msg) 
{
    return 1;
}