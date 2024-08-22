// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i = 0;
//     while(i < argc) {
//         printf("arg %d: %s\n", i, argv[i]);
//         i++;
//     }

//     char *states[] = {
//         "California", "Oregon",
//         "Washington", "Texas"
//     };

//     int num_states = 4;
//     i = 0;
//     while(i < num_states) {
//         printf("state %d: %s\n", i, states[i]);
//         i++;
//     }

//     return 0;
// }

//让这些循环倒序执行，通过使用i--从argc开始递减直到0。你可能需要做一些算数操作让数组的下标正常工作。
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i = argc - 1;
//     while(i >= 0) {
//         printf("arg %d: %s\n", i, argv[i]);
//         i--;
//     }

//     char *states[] = {
//         "California", "Oregon",
//         "Washington", "Texas"
//     };

//     i = 3;
//     while(i >= 0) {
//         printf("state %d: %s\n", i, states[i]);
//         i--;
//     }

//     return 0;
// }
/*
run：
$./ex11 hello world
arg 2: world
arg 1: hello
arg 0: ./ex11
state 3: Texas
state 2: Washington
state 1: Oregon
state 0: California
*/

//使用while循环将argv中的值复制到states。
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }


    //使用while循环将argv中的值复制到states。
    i = 0;
    while(i < num_states) {
        states[i] = argv[i];
        printf("赋值后的state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
/*
run:
$./ex11 hello yjx
arg 0: ./ex11
arg 1: hello
arg 2: yjx
state 0: California
state 1: Oregon
state 2: Washington
state 3: Texas
赋值后的state 0: ./ex11
赋值后的state 1: hello
赋值后的state 2: yjx
赋值后的state 3: (null)
*/

//让这个复制循环不会执行失败，即使argv之中有很多元素也不会全部放进states。
int main(int argc, char *argv[])
{
    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }


    //使用while循环将argv中的值复制到states。
    i = 0;
    while(i < num_states && i < argc) {
        states[i] = argv[i];
        printf("赋值后的state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
/*
states[i] = argv[i];只是将地址赋给了states【】
*/