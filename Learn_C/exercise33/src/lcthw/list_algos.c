#include "list_algos.h"
#include "dbg.h"

// 交换两个节点的值
void ListNode_swap(ListNode *a, ListNode *b)
{
    void *temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// 冒泡排序函数
int List_bubble_sort(List *list, List_compare cmp)
{
    int sorted = 1;

    if (List_count(list) <= 1) {
        return 0;
    }

    do {
        sorted = 1;
        LIST_FOREACH(list, first, next, cur) {
            if (cur->next) {
                if (cmp(cur->value, cur->next->value) > 0) {
                    ListNode_swap(cur, cur->next);
                    sorted = 0;
                }
            }
        }
    } while (!sorted);

    return 0;
}

// 合并两个已排序链表
List *List_merge(List *left, List *right, List_compare cmp)
{
    List *result = List_create();
    void *val = NULL;

    while (List_count(left) > 0 || List_count(right) > 0) {
        if (List_count(left) > 0 && List_count(right) > 0) {
            if (cmp(List_first(left), List_first(right)) <= 0) {
                val = List_shift(left);
            } else {
                val = List_shift(right);
            }
            List_push(result, val);
        } else if (List_count(left) > 0) {
            val = List_shift(left);
            List_push(result, val);
        } else if (List_count(right) > 0) {
            val = List_shift(right);
            List_push(result, val);
        }
    }

    return result;
}

// 归并排序函数
List *List_merge_sort(List *list, List_compare cmp)
{
    if (List_count(list) <= 1) {
        return list;
    }

    int middle = List_count(list) / 2;
    List *left = List_create();
    List *right = List_create();
    check_mem(left);
    check_mem(right);

    // 将链表拆分成两个部分
    ListNode *node = list->first;
    for (int i = 0; i < middle; i++) {
        List_push(left, node->value);
        node = node->next;
    }
    while (node) {
        List_push(right, node->value);
        node = node->next;
    }

    // 递归排序
    List *sort_left = List_merge_sort(left, cmp);
    List *sort_right = List_merge_sort(right, cmp);

    // 销毁临时链表
    if (sort_left != left) List_destroy(left);
    if (sort_right != right) List_destroy(right);

    // 合并排序后的链表
    return List_merge(sort_left, sort_right, cmp);

error:
    if (left) List_destroy(left);
    if (right) List_destroy(right);
    return NULL;
}


//附加题：实现List_insert_sorted（有序链表），它使用List_compare，接收一个值，将其插入到正确的位置，使链表有序
void List_insert_sorted(List *list, void *value, List_compare cmp) {
    if(!list || !value || !cmp) {
        log_err("传递List_insert_sorted函数的参数无效");
        return;
    }

    ListNode *node = list->first;
    ListNode *new_node = ListNode_create(value);
    check_mem(new_node);

    //如果链表为空或者新值小于第一个节点，则插入头部
    if(node == NULL || cmp(value, node->value) <= 0) {
        List_unshift(list, value);
        return;
    }

    //找到第一个大于新值的节点
    while(node->next != NULL && cmp(value, node->next->value) > 0) {
        node = node->next;
    }

    //将新节点插入找到的位置
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;

    if(new_node->next != NULL) {
        new_node->next->prev = new_node;
    } else {
        list->last = new_node;
    }

    list->count++;

    return;

error:
    if(new_node) free(new_node);
    return;
}