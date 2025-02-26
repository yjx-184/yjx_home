#include "minunit.h"
#include "../src/lcthw/list.h"
#include <assert.h>

//定义一个全局变量链表指针
static List *list = NULL;

//测试用的数据
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

//测试创建链表
char *test_create()
{
    //创建一个新的链表
    list = List_create();
    //检查链表是否成功创建
    mu_assert(list != NULL, "无法创建列表。");

    return NULL;
}

//测试销毁链表
char *test_destroy()
{
    //清除并销毁链表
    List_clear_destroy(list);

    return NULL;

}

//测试推送（push）和弹出（pop）操作
char *test_push_pop()
{
    List_push(list, test1);     // 推送 test1 到链表
    mu_assert(List_last(list) == test1, "最后一个值错误。");

    List_push(list, test2);     // 推送 test2 到链表
    mu_assert(List_last(list) == test2, "最后一个值错误");

    List_push(list, test3);     // 推送 test3 到链表
    mu_assert(List_last(list) == test3, "最后一个值错误.");
    mu_assert(List_count(list) == 3, "推送计数错误。");

    char *val = List_pop(list); // 弹出最后一个值，并检查返回值是否为 test3
    mu_assert(val == test3, "弹出的值错误。");

    val = List_pop(list);       // 弹出最后一个值，并检查返回值是否为 test2
    mu_assert(val == test2, "弹出的值错误。");

    val = List_pop(list);        // 弹出最后一个值，并检查返回值是否为 test1
    mu_assert(val == test1, "弹出的值错误。");
    mu_assert(List_count(list) == 0, "弹出后计数错误。");

    return NULL;
}

// 测试取消移位（unshift）操作
char *test_unshift()
{
    List_unshift(list, test1);  // 在链表开头添加 test1
    mu_assert(List_first(list) == test1, "第一个值错误。");

    List_unshift(list, test2);  // 在链表开头添加 test2
    mu_assert(List_first(list) == test2, "第一个值错误。");

    List_unshift(list, test3);  // 在链表开头添加 test3
    mu_assert(List_first(list) == test3, "最后一个值错误。");
    mu_assert(List_count(list) == 3, "取消移位时的计数错误。");

    return NULL;
}

// 测试移除（remove）操作
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

// 测试复制（copy）操作
char *test_copy() {
    List *copy = List_copy(list);
    mu_assert(copy != NULL, "无法复制列表。");
    mu_assert(List_count(copy) == List_count(list), "复制的列表计数错误。");

    List_clear_destroy(copy);
    return NULL;
}

// 测试连接（concat）操作
char *test_concat() {
    List *list2 = List_create();
    List_push(list2, test3);

    List_concat(list, list2);
    mu_assert(List_last(list) == test3, "连接后的最后一个值错误。");
    mu_assert(List_count(list) == 4, "连接后的列表计数错误。");

    List_clear_destroy(list2);
    return NULL;
}

// 测试换班（shift）操作
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


// 执行所有的测试
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