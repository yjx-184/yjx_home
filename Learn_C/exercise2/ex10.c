// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i = 0;

    
//     //遍历
//     for(i = 0; i < argc; i++) {
//         printf("arg %d: %s\n", i, argv[i]);
//     }

//     //让我们创建自己的字符串数组
//     char *states[] = {
//         "California", "Oregon",
//         "Washington", NULL
//     };
//     int num_states = 4;

//     for(i = 0; i < num_states; i++) {
//         printf("state %d: %s\n", i, states[i]);
//     }

//     return 0;
// }

/*
for（表达式1；表达式2；表达式3）
{
    语句块；
}
for循环中，表达式1是循环变量的初值， 表达式2是循环的条件，表达式3是循环变量的增减值。


查询NULL是什么东西，尝试将它用做states的一个元素，看看它会打印出什么
arg 0: ./ex10
state 0: California
state 1: Oregon
state 2: Washington
state 3: (null)

*/

//看看你是否能在打印之前将states的一个元素赋值给argv中的元素，再试试相反的操作。
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i = 0;

    
//     //遍历
//     for(i = 0; i < argc; i++) {
//         printf("arg %d: %s\n", i, argv[i]);
//     }

//     //让我们创建自己的字符串数组
//     char *states[] = {
//         "California", "Oregon",
//         "Washington", "Texas"
//     };

//     argv[1] = states[1];
//     argv[2] = states[2];

//     int num_states = 4;

//     for(i = 0; i < num_states; i++) {
//         printf("state %d: %s\n", i, states[i]);
//     }

//     for(i = 0; i < argc; i++) {
//         printf("修改之后arg %d: %s\n", i, argv[i]);
//     }

//     return 0;
// }
/*
运行结果：
yjx@yjx-Lenovo-Legion-R7000-2020:~/user/Learn_C/exercise2$ ./ex10 1 2
arg 0: ./ex10
arg 1: 1
arg 2: 2
state 0: California
state 1: Oregon
state 2: Washington
state 3: Texas
修改之后arg 0: ./ex10
修改之后arg 1: Oregon
修改之后arg 2: Washington

*/

//相反
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    
    //遍历
    for(i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    //让我们创建自己的字符串数组
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    states[0] = argv[0];
    states[1] = argv[1];
    states[2] = argv[2];
    states[3] = argv[3];
    for(i = 0; i < num_states; i++) {
            printf("修改之后state %d: %s\n", i, states[i]);
        }

    return 0;
}

/*
运行结果：
yjx@yjx-Lenovo-Legion-R7000-2020:~/user/Learn_C/exercise2$ ./ex10 hello world
arg 0: ./ex10
arg 1: hello
arg 2: world
state 0: California
state 1: Oregon
state 2: Washington
state 3: Texas
修改之后state 0: ./ex10
修改之后state 1: hello
修改之后state 2: world
修改之后state 3: (null)
*/