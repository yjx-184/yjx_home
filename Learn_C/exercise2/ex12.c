// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i = 0;

//     if(argc == 1) {
//         printf("You only have one argument. You suck.\n");
//     } else if(argc > 1 && argc < 4) {
//         printf("Here's your argument:\n");

//         for(i = 0; i < argc; i++) {
//             printf("%s", argv[i]);
//         }
//         printf("\n");
//     } else {
//         printf("You have too many argument.You suck.\n");
//     }

//     return 0;
// }

//argv【0】是程序的名称，因此不是用户输入的第一个参数
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You didn't provide any arguments. You suck.\n");
    } else if(argc == 2) {
        printf("You have one argument:\n");
        printf("%s\n", argv[1]);
    } else if(argc > 2 && argc < 5) {
        printf("Here are your arguments:\n");
        for(i = 0; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many argument.You suck.\n");
    }

    return 0;
}