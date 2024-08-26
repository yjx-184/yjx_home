#include "minunit.h"
#include "../src/lcthw/darray.h"

static DArray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;

char *test_create()
{
    array = DArray_create(sizeof(int), 100);
    mu_assert(array != NULL, "DArray_create 失败。");
    mu_assert(array->contents != NULL, "darray 中的内容错误");
    mu_assert(array->end == 0, "结束的位置不对");
    mu_assert(array->element_size == sizeof(int), "元素尺寸错误。");
    mu_assert(array->max == 100, "初始大小的最大长度错误");

    return NULL;
}

char *test_destroy()
{
    DArray_destroy(array);

    return NULL;
}

char *test_new()
{
    val1 = DArray_new(array);
    mu_assert(val1 != NULL, "无法创建新元素");

    val2 = DArray_new(array);
    mu_assert(val2 != NULL,"无法创建新元素");

    return NULL;
}

char *test_set()
{
    DArray_set(array, 0, val1);
    DArray_set(array, 1, val2);

    return NULL;
}

char *test_get()
{
    mu_assert(DArray_get(array, 0) == val1, "第一个值错误");
    mu_assert(DArray_get(array, 1) == val2, "第二个值错误");

    return NULL;
}

char *test_remove()
{
    int *val_check = DArray_remove(array, 0);
    mu_assert(val_check != NULL, "不应获取 NULL。");
    mu_assert(*val_check == *val1, "应该获取第一个值。");
    mu_assert(DArray_get(array, 0) == NULL, "第一个位置的值应该被移除。");
    DArray_free(val_check);

    val_check = DArray_remove(array, 1);
    mu_assert(val_check != NULL, "不应获取 NULL。");
    mu_assert(*val_check == *val2, "应该获取第一个值。");
    mu_assert(DArray_get(array, 1) == NULL, "应该沒有。");
    DArray_free(val_check);

    return NULL;
}

char *test_expand_contract()
{
    int old_max = array->max;
    DArray_expand(array);
    mu_assert((unsigned int)array->max == old_max + array->expand_rate, "展开后尺寸错误。");

    DArray_contract(array);
    mu_assert((unsigned int)array->max == array->expand_rate + 1, "至少应该保持在 expand_rate。");

    DArray_contract(array);
    mu_assert((unsigned int)array->max == array->expand_rate + 1, "至少应该保持在 expand_rate。");

    return NULL;
}

char *test_push_pop()
{
    int i = 0;
    for(i = 0; i < 1000; i++) {
        int *val = DArray_new(array);
        *val = i * 333;
        DArray_push(array, val);
    }

    mu_assert(array->max == 1201, "最大尺寸错误。");

    for(i = 999; i >= 0; i--) {
        int *val = DArray_pop(array);
        mu_assert(val != NULL, "不应得到 NULL。");
        mu_assert(*val == i * 333, "值错误。");
        DArray_free(val);
    }

    return NULL;
}


char * all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_new);
    mu_run_test(test_set);
    mu_run_test(test_get);
    mu_run_test(test_remove);
    mu_run_test(test_expand_contract);
    mu_run_test(test_push_pop);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);