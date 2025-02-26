#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//上一节的错误处理函数
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

//定义函数指针类型compare_cb，用于比较两个整数
typedef int (*compare_cb)(int a, int b);

/**
* 经典的冒泡排序函数，使用
* compare_cb 进行排序。
*/
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;                                   //临时变量，用于交换元素
    int i = 0;                                      //外层循环变量
    int j = 0;                                      //内层循环变量
    int *target = malloc(count * sizeof(int));      //分配内存用于存储排序后的数组

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));   //将原始数组复制给目标数组

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            //使用比较函数cmp判断是否需要交换元素
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;  //返回排序后的数组
}

//升序
int sorted_order(int a, int b)
{
    return a - b;
}

//降序
int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
* 用于测试我们是否正确地对事物进行排序
* 通过进行排序并将其打印出来。
*/
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);     //调用冒泡排序函数

    if(!sorted) die("Failed to sort as requested.");

    //打印排序后的数组
    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);                                       //释放排序后的数组内存

    // unsigned char *data = (unsigned char *)cmp;

    // for(i = 0; i < 25; i++) {
    //     printf("%02x:", data[i]);
    // }

    // printf("\n");
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;                               //计算输入的整数哥舒
    int i = 0;
    char **inputs = argv + 1;                           //跳过程序名称

    int *numbers = malloc(count * sizeof(int));         //分配内存给存储输入的整数
    if(!numbers) die("Memory error.");

    //将输入的字符串参数转换为整数并存储到numbers数组中
    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    //测试三种排序
    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);                                      //释放内存

    return 0;
}