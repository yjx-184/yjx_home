#include "minunit.h"
#include "../src/lcthw/list.h"
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";


char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "无法创建列表。");

    return NULL;
}


char *test_destroy()
{
    List_clear_destroy(list);

    return NULL;

}


char *test_push_pop()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "最后一个值错误。");

    List_push(list, test2);
    mu_assert(List_last(list) == test2, "最后一个值错误");

    List_push(list, test3);
    mu_assert(List_last(list) == test3, "最后一个值错误.");
    mu_assert(List_count(list) == 3, "推送计数错误。");

    char *val = List_pop(list);
    mu_assert(val == test3, "弹出的值错误。");

    val = List_pop(list);
    mu_assert(val == test2, "弹出的值错误。");

    val = List_pop(list);
    mu_assert(val == test1, "弹出的值错误。");
    mu_assert(List_count(list) == 0, "弹出后计数错误。");

    return NULL;
}

char *test_unshift()
{
    List_unshift(list, test1);
    mu_assert(List_first(list) == test1, "第一个值错误。");

    List_unshift(list, test2);
    mu_assert(List_first(list) == test2, "第一个值错误。");

    List_unshift(list, test3);
    mu_assert(List_first(list) == test3, "最后一个值错误。");
    mu_assert(List_count(list) == 3, "取消移位时的计数错误。");

    return NULL;
}

char *test_remove()
{
    // 我们只需要测试中间的删除情况，因为 push/shift
    // 已经测试了其他情况
    char *val = List_remove(list, list->first->next);
    mu_assert(val == test2, "错误删除了元素。");
    mu_assert(List_count(list) == 2, "删除后计数错误。");
    mu_assert(List_first(list) == test3, "先错后删。");
    mu_assert(List_last(list) == test1, "删除后最后结果错误。");

    return NULL;
}

char *test_copy() {
    List *copy = List_copy(list);
    mu_assert(copy != NULL, "无法复制列表。");
    mu_assert(List_count(copy) == List_count(list), "复制的列表计数错误。");

    List_clear_destroy(copy);
    return NULL;
}

char *test_concat() {
    List *list2 = List_create();
    List_push(list2, test3);

    List_concat(list, list2);
    mu_assert(List_last(list) == test3, "连接后的最后一个值错误。");
    mu_assert(List_count(list) == 4, "连接后的列表计数错误。");

    List_clear_destroy(list2);
    return NULL;
}

char *test_shift()
{
    mu_assert(List_count(list) != 0, "换班前计数错误。");

    char *val = List_shift(list);
    mu_assert(val == test3, "移位值错误。");

    val = List_shift(list);
    mu_assert(val == test1, "移位值错误。");
    mu_assert(List_count(list) == 0, "换班后计数错误。");

    return NULL;
}



char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_unshift);
    mu_run_test(test_remove);
    mu_run_test(test_shift);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);