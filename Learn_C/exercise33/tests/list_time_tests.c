#include "minunit.h"
#include "../src/lcthw/list_algos.h"
#include <time.h>

#define NUM_ELEMENTS 1000   //每个链表的元素数量
#define ITERATIONS 100      //每个测试的迭代次数

//创建一个能够生成随机整数的链表
List *create_random_list(int num_elements) {
    List *list = List_create();
    check_mem(list);

    for (int i = 0; i < num_elements; i++) {
        int *value = malloc(sizeof(int));
        check_mem(value);
        *value = rand() % 10000;  // 生成0到9999的随机数
        List_push(list, value);
    }

    return list;

error:
    if (list) List_destroy(list);
    return NULL;
}

//比较
int int_compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

//冒泡测试
char *test_bubble_sort() {
    clock_t start, end;     //定义用于存储开始和结束时间的变量
    double total_time = 0;  //定义一个变量来存储总时间

    for (int i = 0; i < ITERATIONS; i++) {
        List *list = create_random_list(NUM_ELEMENTS);
        check(list != NULL, "无法创建随机链表");

        start = clock();    //记录排序开始时间
        List_bubble_sort(list, int_compare);//使用冒泡排序
        end = clock();  //记录结束时间

        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;

        List_destroy(list);
    }

    printf("冒泡排序平均时间: %.6f秒\n", total_time / ITERATIONS);

    return NULL;

error:
    return "冒泡排序测试失败";
}

//归并测试
char *test_merge_sort() {
    clock_t start, end;//定义存储开始和结束时间的变量
    double total_time = 0;//定义一个存储总时间

    for (int i = 0; i < ITERATIONS; i++) {
        List *list = create_random_list(NUM_ELEMENTS);
        check(list != NULL, "无法创建随机链表");

        start = clock();
        List *sorted_list = List_merge_sort(list, int_compare);
        end = clock();

        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;

        List_destroy(sorted_list);
        List_destroy(list);
    }

    printf("归并排序平均时间: %.6f秒\n", total_time / ITERATIONS);

    return NULL;

error:
    return "归并排序测试失败";
}


//插入排序测试
char *test_insert_sorted() {
    clock_t start, end;//存储开始和结束时间
    double total_time = 0;//存储总时间

    for(int i = 0; i < ITERATIONS; i++) {
        List *list = List_create();
        check(list != NULL, "无法创建链表");

    //插入元素保持有序
    start = clock();
    for(int j = 0; j < NUM_ELEMENTS; j++) {
        int *value = malloc(sizeof(int));
        check_mem(value);
        *value = rand() % 10000;
        List_insert_sorted(list, value, int_compare);
    }
    end = clock();

    total_time += ((double)(end - start)) / CLOCKS_PER_SEC;

    List_destroy(list);
    }
    printf("插入排序平均时间: %.6f秒\n", total_time / ITERATIONS);

    return NULL;

    


error:
    return "插入排序测试失败";
}



char *all_tests() {
    mu_suite_start();//初始化

    mu_run_test(test_bubble_sort);
    mu_run_test(test_merge_sort);
    mu_run_test(test_insert_sorted);

    return NULL;
}

RUN_TESTS(all_tests);
