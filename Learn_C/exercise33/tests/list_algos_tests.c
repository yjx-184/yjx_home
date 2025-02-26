#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>

// 定义一组字符串用于测试
char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
#define NUM_VALUES 5  // 定义数组的长度

// 创建一个包含测试字符串的链表
List *create_words()
{
    int i = 0;
    List *words = List_create();  // 创建一个空链表

    // 将values数组中的字符串依次添加到链表中
    for(i = 0; i < NUM_VALUES; i++) {
        List_push(words, values[i]);
    }

    return words;  // 返回创建的链表
}

// 检查链表是否已排序
int is_sorted(List *words)
{
    LIST_FOREACH(words, first, next, cur) {
        // 如果当前节点的值大于下一个节点的值，则链表未排序
        if(cur->next && strcmp(cur->value, cur->next->value) > 0) {
            debug("%s %s", (char *)cur->value, (char *)cur->next->value);
            return 0;  // 返回0表示未排序
        }
    }

    return 1;  // 返回1表示已排序
}

// 测试冒泡排序
char *test_bubble_sort()
{
    List *words = create_words();  // 创建一个测试链表

    // 测试对需要排序的链表进行排序
    int rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "冒泡排序失败。");
    mu_assert(is_sorted(words), "冒泡排序后链表未排序。");

    // 测试对已经排序的链表进行排序
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "对已排序链表进行冒泡排序失败。");
    mu_assert(is_sorted(words), "链表在冒泡排序后应保持排序状态。");

    List_destroy(words);  // 销毁链表

    // 测试对空链表进行排序
    words = List_create(words);
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "对空链表进行冒泡排序失败。");
    mu_assert(is_sorted(words), "空链表应被视为已排序。");

    List_destroy(words);  // 销毁链表

    return NULL;
}

// 测试归并排序
char *test_merge_sort()
{
    List *words = create_words();  // 创建一个测试链表

    // 测试对需要排序的链表进行排序
    List *res = List_merge_sort(words, (List_compare)strcmp);
    mu_assert(is_sorted(res), "归并排序后链表未排序。");

    // 测试对已经排序的链表进行排序
    List *res2 = List_merge_sort(res, (List_compare)strcmp);
    mu_assert(is_sorted(res), "链表在归并排序后应保持排序状态。");
    List_destroy(res2);  // 销毁链表
    List_destroy(res);  // 销毁链表

    List_destroy(words);  // 销毁链表
    return NULL;
}

// 运行所有测试
char *all_tests()
{
    mu_suite_start();  // 初始化测试套件

    mu_run_test(test_bubble_sort);  // 运行冒泡排序测试
    mu_run_test(test_merge_sort);  // 运行归并排序测试

    return NULL;
}

// 执行所有测试
RUN_TESTS(all_tests);