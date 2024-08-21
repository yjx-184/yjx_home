#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

//test_debug：演示如何使用 debug 宏打印调试信息。
void test_debug()
{
    debug("我有一头棕色的头发。");

    debug("我今年 %d 岁了", 37);
}

//test_log_err：演示如何使用 log_err 宏记录错误信息。
void test_log_err()
{
    log_err("我相信一切都破碎了。");
    log_err("有 %d 个问题在 %s 里面。", 0, "space");
}

//test_log_warn：演示如何使用 log_warn 宏记录警告信息。
void test_log_warn()
{
    log_warn("您可以放心地忽略这一点。");
    log_warn("也许可以考虑: %s.", "/etc/passwd");
}

//test_log_info：演示如何使用 log_info 宏记录普通信息。
void test_log_info()
{
    log_info("我做了一点普通的事情。");
    log_info("今天已经发生了 %f 次", 1.3f);
}

//test_check：测试 check 和 check_mem 宏的使用。
//尝试分配内存并打开文件，如果失败，则跳转到 error 标签处理。
int test_check(char *file_name)
{
    FILE *input = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block); // should work

    input = fopen(file_name,"r");
    check(input, "Failed to open %s.", file_name);

    free(block);
    fclose(input);
    return 0;

error:
    if(block) free(block);
    if(input) fclose(input);
    return -1;
}

//sentinel 用于标记不应执行的代码路径，并提供一个默认的错误处理逻辑。
int test_sentinel(int code)
{
    char *temp = malloc(100);
    check_mem(temp);

    switch(code) {
        case 1:
            log_info("It worked.");
            break;
        default:
            sentinel("I shouldn't run.");
    }

    free(temp);
    return 0;

error:
    if(temp) free(temp);
    return -1;
}

//test_check_mem：测试 check_mem 宏，当 test 为 NULL 时，会触发错误。
int test_check_mem()
{
    char *test = NULL;
    check_mem(test);

    free(test);
    return 1;

error:
    return -1;
}

//测试 check_debug 宏，用于调试检查。
int test_check_debug()
{
    int i = 0;
    check_debug(i != 0, "Oops, I was 0.");

    return 0;
error:
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc == 2, "Need an argument.");

    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    check(test_check("ex20.c") == 0, "failed with ex20.c");
    check(test_check(argv[1]) == -1, "failed with argv");
    check(test_sentinel(1) == 0, "test_sentinel failed.");
    check(test_sentinel(100) == -1, "test_sentinel failed.");
    check(test_check_mem() == -1, "test_check_mem failed.");
    check(test_check_debug() == -1, "test_check_debug failed.");

    return 0;

error:
    return 1;
}