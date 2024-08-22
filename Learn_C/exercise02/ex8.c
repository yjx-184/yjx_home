// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int areas[] = {10, 12, 13, 14, 20};
//     char name[] = "Zed";
//     char full_name[] = {
//         'Z', 'e', 'd',
//          ' ', 'A', '.', ' ',
//          'S', 'h', 'a', 'w' , '\0'
//     };

//     printf("The size of an int: %ld\n", sizeof(int));
//     printf("The size of areas (int[]): %ld\n",
//             sizeof(areas));
//     printf("The number of ints in areas: %ld\n",
//             sizeof(areas) / sizeof(int));
//     printf("The first area is %d, the 2nd %d.\n",
//             areas[0], areas[1]);

//     printf("The size of a char: %ld\n", sizeof(char));
//     printf("The size of name (char[]): %ld\n",
//             sizeof(name));
//     printf("The number of chars: %ld\n",
//             sizeof(name) / sizeof(char));

//     printf("The size of full_name (char[]): %ld\n",
//             sizeof(full_name));
//     printf("The number of chars: %ld\n",
//             sizeof(full_name) / sizeof(char));

//     printf("name=\"%s\" and full_name=\"%s\"\n",
//             name, full_name);

//     return 0;
// }

/*
将full_name最后的'\0'去掉，并重新运行它，在valgrind下再运行一遍。
现在将full_name的定义从main函数中移到它的上面，尝试在Valgrind下运行它来看看是否能得到一些新的错误。
有些情况下，你会足够幸运，不会得到任何错误。
==227014== Memcheck, a memory error detector
==227014== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==227014== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==227014== Command: ./ex8
==227014== 
The size of an int: 4
The size of areas (int[]): 20
The number of ints in areas: 5
The first area is 10, the 2nd 12.
The size of a char: 1
The size of name (char[]): 4
The number of chars: 4
The size of full_name (char[]): 11
The number of chars: 11
name="Zed" and full_name="Zed A. Shaw"
==227014== 
==227014== HEAP SUMMARY:
==227014==     in use at exit: 0 bytes in 0 blocks
==227014==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==227014== 
==227014== All heap blocks were freed -- no leaks are possible
==227014== 
==227014== For lists of detected and suppressed errors, rerun with: -s
==227014== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



将areas[0]改为areas[10]并打印，来看看Valgrind会输出什么。
会导致数组越界。

*/

//尝试使用areas[0] = 100;以及相似的操作对areas的元素赋值。
#include <stdio.h>

int main(int argc, char *argv[])
{
        int areas[] = {10, 12, 13, 14, 20};
        char name[] = "Zed";
        char full_name[] = {
                'Z', 'e', 'd',
                ' ', 'A', '.', ' ',
                'S', 'h', 'a', 'w' , '\0'
        };
        areas[0] = 100;

        printf("The size of an int: %ld\n", sizeof(int));
        printf("The size of areas (int[]): %ld\n",
                sizeof(areas));
        printf("The number of ints in areas: %ld\n",
                sizeof(areas) / sizeof(int));
        printf("The first area is %d, the 2nd %d.\n",
                areas[0], areas[1]);

        printf("The size of a char: %ld\n", sizeof(char));
        printf("The size of name (char[]): %ld\n",
                sizeof(name));
        printf("The number of chars: %ld\n",
                sizeof(name) / sizeof(char));

        printf("The size of full_name (char[]): %ld\n",
                sizeof(full_name));
        printf("The number of chars: %ld\n",
                sizeof(full_name) / sizeof(char));

        printf("name=\"%s\" and full_name=\"%s\"\n",
                name, full_name);

        return 0;
}

/*
上网搜索在不同的CPU上整数所占的不同大小
四个规则在任何机器上都遵守
1 sizeof(short int)<=sizeof(int)
2 sizeof(int)<=sizeof(long int)
3 short int至少应为16位（2字节）
4 long int至少应为32位。

（1） 64位机器

Size of char is:                    1
Size of unsigned char is:           1
Size of signed char is:             1
Size of int is:                     4
Size of short is:                   2
Size of long is:                    8
Size of long int is:                 8
Size of signed int is:              4
Size of unsigned int is:            4
Size of unsigned long int is:     8
Size of long long int is:          8
Size of unsigned long long is:       8
Size of float is:                  4
Size of double is:                 8
Size of long double is:          16
任何数据类型的指针都是占8个字节

（2）32位机器上
Size of char is:                     1
Size of unsigned char is:            1
Size of signed char is:              1
Size of int is:                       4
Size of short is:                    2
Size of long is:                     4
Size of long int is:                4
Size of signed int is:             4
Size of unsigned int is:          4
Size of unsigned long int is:         4
Size of long long int is:                8
Size of unsigned long long is:       8
Size of float is:                    4
Size of double is:                 8
Size of long double is:          8

任何数据类型的指针都是占4个字节

（3）16位平台

char         1个字节8位
short        2个字节16位
int            2个字节16位
long         4个字节32位
指针         2个字节
*/