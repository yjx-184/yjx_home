// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     if(argc != 2) {
//         printf("ERROR:You need one argument.\n");
//         return 1;
//     }

//     int i = 0;
//     for(i = 0; argv[1][i] != '\0'; i++) {
//         char letter = argv[1][i];

//         switch(letter) {
//             case 'a':
//             case 'A':
//                 printf("%d: 'A'\n", i);
//                 break;

//             case 'e':
//             case 'E':
//                 printf("%d: 'E'\n", i);
//                 break;
            
//             case 'i':
//             case 'I':
//                 printf("%d: 'I'\n", i);
//                 break;

//             case 'o':
//             case 'O':
//                 printf("%d: 'O'\n", i);
//                 break;

//             case 'u':
//             case 'U':
//                 printf("%d: 'U'\n", i);
//                 break;

//             case 'y':
//             case 'Y':
//                 if(i > 2) {
//                     // it's only sometimes Y
//                     printf("%d: 'Y'\n", i);
//                 }
//                 break;

//             default:
//                 printf("%d: %c is not a vowel\n", i, letter);
//         }
//     }

//     return 0;
// }

//编写另一个程序，在字母上做算术运算将它们转换为小写，并且在switch中移除所有额外的大写字母
//'A' 的 ASCII 值是 65，加上 32 后得到 97，即 'a'。
//'B' 的 ASCII 值是 66，加上 32 后得到 98，即 'b'。
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     if(argc != 2) {
//         printf("ERROR:You need one argument.\n");
//         return 1;
//     }

//     int i = 0;
//     for(i = 0; argv[1][i] != '\0'; i++) {
//         char letter = argv[1][i];

//         //将字母换成消协
//         if(letter >= 'A' && letter <= 'Z') {
//             letter = letter + 32;
//         }

//         switch(letter) {
//             case 'a':
//                 printf("%d: 'A'\n", i);
//                 break;

//             case 'e':
//                 printf("%d: 'E'\n", i);
//                 break;
            
//             case 'i':
//                 printf("%d: 'I'\n", i);
//                 break;

//             case 'o':
//                 printf("%d: 'O'\n", i);
//                 break;

//             case 'u':
//                 printf("%d: 'U'\n", i);
//                 break;

//             case 'y':
//                 if(i > 2) {
//                     // it's only sometimes Y
//                     printf("%d: 'Y'\n", i);
//                 }
//                 break;

//             default:
//                 printf("%d: %c is not a vowel\n", i, letter);
//         }
//     }

//     return 0;
// }

//使用','（逗号）在for循环中初始化letter。
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     if(argc != 2) {
//         printf("ERROR:You need one argument.\n");
//         return 1;
//     }

//     int i;
//     char letter;
//     for(i = 0, letter = argv[1][i]; letter != '\0'; i++, letter = argv[1][i]) {

//         //将字母换成消协
//         if(letter >= 'A' && letter <= 'Z') {
//             letter = letter + 32;
//         }

//         switch(letter) {
//             case 'a':
//                 printf("%d: 'A'\n", i);
//                 break;

//             case 'e':
//                 printf("%d: 'E'\n", i);
//                 break;
            
//             case 'i':
//                 printf("%d: 'I'\n", i);
//                 break;

//             case 'o':
//                 printf("%d: 'O'\n", i);
//                 break;

//             case 'u':
//                 printf("%d: 'U'\n", i);
//                 break;

//             case 'y':
//                 if(i > 2) {
//                     // it's only sometimes Y
//                     printf("%d: 'Y'\n", i);
//                 }
//                 break;

//             default:
//                 printf("%d: %c is not a vowel\n", i, letter);
//         }
//     }

//     return 0;
// }



//使用另一个for循环来让它处理你传入的所有命令行参数。
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     if(argc != 2) {
//         printf("ERROR:You need one argument.\n");
//         return 1;
//     }

//     // 外层 for 循环遍历所有的命令行参数
//     for(int j = 1; j < argc; j++) {
//         printf("处理参数 %d: %s\n", j, argv[j]);

//         // 内层 for 循环遍历当前参数的每一个字符
//         for(int i = 0; argv[j][i] != '\0'; i++) {
//             char letter = argv[j][i];

//             // 将字母转换为小写
//             if(letter >= 'A' && letter <= 'Z') {
//                 letter = letter + 32;
//             }

//             switch(letter) {
//                 case 'a':
//                     printf("%d: 'A'\n", i);
//                     break;

//                 case 'e':
//                     printf("%d: 'E'\n", i);
//                     break;

//                 case 'i':
//                     printf("%d: 'I'\n", i);
//                     break;

//                 case 'o':
//                     printf("%d: 'O'\n", i);
//                     break;

//                 case 'u':
//                     printf("%d: 'U'\n", i);
//                     break;

//                 case 'y':
//                     if(i > 2) {
//                         printf("%d: 'Y'\n", i);
//                     }
//                     break;

//                 default:
//                     printf("%d: %c is not a vowel\n", i, letter);
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }


/*
在“Y”的例子中，我在if代码块外面写了个break。
这样会产生什么效果？
如果把它移进if代码块，会发生什么？
自己试着解答它，并证明你是正确的。

答：在if代码块的外面，说明break不属于if代码快的一部分，无论if是否为真，
    都会从switch跳出。如果brak在if代码快中，说明if为真的时候，才会执行break
    跳出switch语句。
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR:You need one argument.\n");
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        //将字母换成消协
        if(letter >= 'A' && letter <= 'Z') {
            letter = letter + 32;
        }

        switch(letter) {
            case 'a':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
                printf("%d: 'E'\n", i);
                break;
            
            case 'i':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
                break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}