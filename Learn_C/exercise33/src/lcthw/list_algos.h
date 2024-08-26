#ifndef LCTHW_LIST_ALGOS_H
#define LCTHW_LIST_ALGOS_H

#include "list.h"

// 比较函数指针类型定义
typedef int (*List_compare)(const void *a, const void *b);

// 排序函数声明
int List_bubble_sort(List *list, List_compare cmp);
List *List_merge_sort(List *list, List_compare cmp);
void List_insert_sorted(List *list, void *value, List_compare cmp);


#endif