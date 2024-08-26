#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <stdlib.h>
#include "../src/lcthw/dbg.h"

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message) if (!(test)) { log_err(message); return message; }
#define mu_run_test(test) debug("\n-----%s", " " #test); \
    message = test(); tests_run++; if (message) return message;

#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
    (void)argc; (void)argv; \
    argc = 1; \
    debug("----- 运行中: %s", argv[0]);\
        printf("----\n运行中: %s\n", argv[0]);\
        char *result = name();\
        if (result != 0) {\
            printf("失败: %s\n", result);\
        }\
        else {\
            printf("所有测试通过\n");\
        }\
    printf("测试运行: %d\n", tests_run);\
        exit(result != 0);\
}


int tests_run;

#endif