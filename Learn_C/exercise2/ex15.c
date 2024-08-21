// #include  <stdio.h>

// int main(int argc, char *argv[])
// {
//     int ages[] = {23, 43, 12, 89, 2};
//     char *names[] = {
//         "Alan", "Frank",
//         "Mary", "John", "Lisa"
//     };

//     int count = sizeof(ages) / sizeof(int);
//     int i = 0;

//     for(i = 0; i < count; i++) {
//         printf("%s has %d years alive.\n", names[i], ages[i]);
//     }

//     printf("---\n");

//     int *cur_age = ages;
//     char **cur_name = names;

//     for(i = 0; i < count; i++) {
//         printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);

//     }
//     printf("---\n");

//     for(cur_name = names, cur_age = ages;
//             (cur_age - ages) < count;
//             cur_name++, cur_age++)
//     {
//         printf("%s lived %d years so far.\n",
//                 *cur_name, *cur_age);
//     }

//     return 0;
// }

// //使用访问数组的方式重写所有使用指针的地方。
// #include <stdio.h>

// int main(int argc, char *argv[]) {
//     int ages[] = {23, 43, 12, 89, 2};
//     char *names[] = {
//         "Alan", "Frank",
//         "Mary", "John", "Lisa"
//     };

//     int count = sizeof(ages) / sizeof(int);
//     int i = 0;

//     for(i = 0; i < count; i++) {
//          printf("%s has %d years alive.\n", names[i], ages[i]);
//     }

//     printf("---\n");

//     for(i = 0; i < count ; i++) {
//         printf("%s is %d years old again.\n", names[i], ages[i]);
//     }

//     printf("---\n");

//     for(i = 0; i < count; i++) {
//         printf("%s lived %d years so far.\n",
//                 names[i], ages[i]);
//     }
//     return 0;
// }


//使用指针来处理命令行参数，就像处理names那样。
#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // 第一种方式，使用索引
    for(i = 0; i < count; i++) {
        printf("%s has %d years alive.\n",
                names[i], ages[i]);
    }

    printf("---\n");

    // 设置指针指向数组的起始位置
    int *cur_age = ages;
    char **cur_name = names;

    // 第二种方式，使用指针
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name+i), *(cur_age+i));
    }

    printf("---\n");

    // 第三种方式，指针其实就是数组
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
                cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // 第四种方式，用指针方式
    for(cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }

    printf("---\n");
    //使用指针处理命令行参数
    for(i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, *(argv + i));
    }

     printf("---\n");

     printf("打印指针的地址：\n");

     printf("ages: %p\n", (void *)ages);

     printf("names:%p\n", (void *)names);

     
    return 0;
}