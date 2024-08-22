#include "list.h"
#include "dbg.h"

//创建新链表
List *List_create()
{
    //分配内存给链表结构体，并初始化为0
    return calloc(1, sizeof(List));
}

//销毁链表
void List_destroy(List *list)
{
    //遍历链表每个节点
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) { //如果当前节点不是头节点
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

//清除链表中的每个节点的值，但不销毁节点本身
void List_clear(List *list)
{
    //遍历
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);//释放节点的值的内存
    }
}

//清除并销毁链表
void List_clear_destroy(List *list)
{
    List_clear(list);   //先清除链表中的值
    List_destroy(list); //再销毁链表
}

//在链表末尾添加新节点
void List_push(List *list, void *value)
{
    //分配内存
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->last == NULL) {//如果是空链表
        list->first = node;
        list->last = node;
    } else {    //如果不是空链表
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;//增加链表节点计数

error:
    return;
}

//从链表的末尾移除并返回节点的值
void *List_pop(List *list)
{
    ListNode *node = list->last;//获取最后一个节点
    return node != NULL ? List_remove(list, node) : NULL;
}

//在链表的开头添加一个节点
void List_unshift(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

//从链表的开头移除并返回节点的值
void *List_shift(List *list)
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

//从链表中移除指定节点，并返回该节点的值
void *List_remove(List *list, ListNode *node)
{
    void *result = NULL;

    check(list->first && list->last, "列表为空");
    check(node, "节点不能为 NULL");

    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        check(list->first != NULL,"无效列表，不知何故得到了第一个为 NULL");
        list->first->prev = NULL;
    } else if(node == list->last) { // 处理删除最后一个节点的情况
        list->last = node->prev;
        list->last->next = NULL;
    } else {
        ListNode *before = node->prev;
        ListNode *after = node->next;

        if (before) {
            before->next = after;
        }

        if (after) {
            after->prev = before;
        }
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result;
}

//复制
void *List_copy(List *list) {
    List *new_list = List_create();
    check_mem(new_list);

    //遍历当前链表并复制节点
    LIST_FOREACH(list, first, next, cur) {
        List_push(new_list, cur->value);
    }

    return new_list;

error:
    if (new_list) List_destroy(new_list);
    return NULL;
}

//连接 
void List_concat(List *list1, List *list2) {
    //检查是否为空
    if(list2->first == NULL) return;
    //如果list1为空，list1就是list2
    if(list1->last == NULL) {
        list1->first = list2->first;
        list1->last = list2->last;
    } else {//如果非空，list1尾节点的下一个指向list2的头节点
        list1->last->next = list2->first;
        list2->first->prev = list1->last;
        list1->last = list2->last;
    }

    list1->count += list2->count;

    list2->first = NULL;
    list2->last = NULL;
    list2->count = 0;
}

/*
单向链表：
    特点：只能从头节点开始顺序访问，无法直接访问前一个节点
    优点：占用内存少，每个节点只需要存储一个指针。
    缺点：无法从尾部向头部遍历链表；删除节点复杂，需要知道它的前驱节点。

双向链表：
    特点：每个节点包含一个指向下一个节点的指针next和指向前一个节点的prev，可以从头或尾节点遍历
    优点：双向遍历；删除节点简单。
    缺点：占用内存多，每个节点要存储两个指针。
*/