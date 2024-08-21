// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// void print_letters(char arg[]);

// void print_arguments(int argc, char *argv[])
// {
//     int i = 0;

//     for(i = 0; i < argc; i++) {
//         print_letters(argv[i]);
//     }
// }

// void print_letters(char arg[])
// {
//     int i = 0;

//     for(i = 0; arg[i] != '\0'; i++) {
//         char ch = arg[i];

//         //修改之后，省了一个函数
//         if(isalpha(ch) || isblank(ch)) {
//             printf("'%c' == %d ", ch, ch);
//         }
//     }

//     printf("\n");
// }



// int main(int argc, char *argv[])
// {
//     print_arguments(argc, argv);
//     return 0;
// }

//使用strlen函数，让print_arguments知道每个字符串参数都有多长，之后将长度传入print_letters。
//然后重写print_letters，让它只处理固定的长度，不按照'\0'终止符。你需要#include <string.h>来实现它。
// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>


// void print_arguments(int argc, char *argv[])
// {
//     for(int i = 0; i < argc; i++) {
//         int length = strlen(argv[i]);
//         print_letters(argv[i], length);
//     }
// }

// void print_letters(char arg[], int length)
// {

//     for(int i = 0; arg[i] != '\0'; i++) {
//         char ch = arg[i];

//         //修改之后，省了一个函数
//         if(isalpha(ch) || isblank(ch)) {
//             printf("'%c' == %d ", ch, ch);
//         }
//     }

//     printf("\n");
// }



// int main(int argc, char *argv[])
// {
//     print_arguments(argc, argv);
//     return 0;
// }


//使用man来查询isalpha和isblank的信息。使用其它相似的函数来只打印出数字或者其它字符。
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void print_arguments(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++) {
        int length = strlen(argv[i]);
        print_letters(argv[i], length);
    }
}

void print_letters(char arg[], int length)
{

    for(int i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];

        //isalnum可以打印数字
        if(isalnum(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}



int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
/*
isalpha （字母，包括大写、小写）
islower（小写字母）
isupper（大写字母）
isalnum（字母大写小写+数字）
isblank（space和\t）
isspace（space、\t、\r、\n）
*/