#include "minunit.h"
#include "../src/lcthw/queue.h"

static Queue *queue = NULL;
char *tests[] = {"测试数据1", "测试数据2", "测试数据3"};
#define NUM_TESTS 3

char *test_create()
{
    queue = Queue_create();
    mu_assert(queue != NULL, " 创造队列失败！");

    return NULL;
}

char *test_destroy()
{
    mu_assert(queue != NULL, "制作队列失败！");
    Queue_destroy(queue);

    return NULL;
}

char *test_send_recv()
{
    int i = 0;
    for(i = 0; i < NUM_TESTS; i++) {
        Queue_send(queue, tests[i]);
        mu_assert(Queue_peek(queue) == tests[0], "下一个值错误。");
    }
    mu_assert(Queue_count(queue) == NUM_TESTS, "发送计数错误。");
    QUEUE_FOREACH(queue, cur) {
        debug("VAL: %s", (char *)cur->value);
    }

    for(i = 0; i < NUM_TESTS; i++) {
        char *val = Queue_recv(queue);
        mu_assert(val == tests[i], "接收值错误。");
    }

    mu_assert(Queue_count(queue) == 0, "接收后计数错误。");

    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_send_recv);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);