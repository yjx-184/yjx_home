#include "minunit.h"
#include "../src/lcthw/list_algos.h"
#include <assert.h>
#include <string.h>

char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
#define NUM_VALUES 5

List *create_words()
{
    int i = 0;
    List *words = List_create();

    for(i = 0; i < NUM_VALUES; i++) {
        List_push(words, values[i]);
    }

    return words;
}

int is_sorted(List *words)
{
    LIST_FOREACH(words, first, next, cur) {
        if(cur->next && strcmp(cur->value, cur->next->value) > 0) {
            debug("%s %s", (char *)cur->value, (char *)cur->next->value);
            return 0;
        }
    }

    return 1;
}

char *test_bubble_sort()
{
    List *words = create_words();

    // 应该适用于需要排序的列表
    int rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "冒泡排序失败。");
    mu_assert(is_sorted(words), "冒泡排序后单词没有排序。");

    // 应该在已经排序的列表上工作
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "冒泡排序已经排序失败。");
    mu_assert(is_sorted(words), "如果已经按冒泡排序，则应该对单词进行排序。");

    List_destroy(words);

    // 应该在空列表上工作
    words = List_create(words);
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "冒泡排序在空列表上失败。");
    mu_assert(is_sorted(words), "如果为空，则需要对单词进行排序。");

    List_destroy(words);

    return NULL;
}

char *test_merge_sort()
{
    List *words = create_words();

    // 应该适用于需要排序的列表
    List *res = List_merge_sort(words, (List_compare)strcmp);
    mu_assert(is_sorted(res), "合并排序后单词没有排序。");

    List *res2 = List_merge_sort(res, (List_compare)strcmp);
    mu_assert(is_sorted(res), "归并排序后应该还是有序的。");
    List_destroy(res2);
    List_destroy(res);

    List_destroy(words);
    return NULL;
}


char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_bubble_sort);
    mu_run_test(test_merge_sort);

    return NULL;
}

RUN_TESTS(all_tests);