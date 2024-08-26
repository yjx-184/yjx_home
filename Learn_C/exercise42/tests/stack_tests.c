#include "minunit.h"
#include "../src/lcthw/stack.h"

//声明一个全局栈指针
static Stack *stack = NULL;
char *tests[] = {"测试数据1", "测试数据2", "测试数据3"};
#define NUM_TESTS 3//定义测试数据的数量

//创建栈堆
char *test_create()
{
    stack = Stack_create();
    mu_assert(stack != NULL, "无法创建堆栈。");

    return NULL;
}

//销毁栈堆
char *test_destroy()
{
    mu_assert(stack != NULL,"制作栈堆失败")
    Stack_destroy(stack);

    return NULL;
}

//测试栈的压入和弹出
char *test_push_pop()
{
    int i = 0;
    for(i = 0; i < NUM_TESTS; i++) {
        Stack_push(stack, tests[i]);
        mu_assert(Stack_peek(stack) == tests[i], "下一个值错误。");
    }
    mu_assert(Stack_count(stack) == NUM_TESTS, "推送计数错误。");

void *cur = NULL;

    // 遍历栈中的每个元素
    STACK_FOREACH(stack, cur) {
        debug("VAL:%s", (char *)cur);//因附加题修改，原debug("VAL:%s", (char *)cur->value);
    }

    for(i = NUM_TESTS - 1; i >= 0; i--) {
        char *val = Stack_pop(stack);
        mu_assert(val == tests[i], "弹出的值错误。");
    }

    mu_assert(Stack_count(stack) == 0, "弹出后计数错误。");

    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);

