#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

//定义链表节点
struct ListNode;

typedef struct ListNode {
    struct ListNode *next;                  //指向下一个节点的指针
    struct ListNode *prev;                  //指向前一个节点的指针
    void *value;                            //存储节点的值
} ListNode;

//定义链表结构
typedef struct List {
    int count;                              //链表节点的数量
    ListNode *first;                        //指向链表头部的指针
    ListNode *last;                         //指向链表尾部的指针
} List;

List *List_create();                        //创建一个新的空链表
void List_destroy(List *list);              //销毁链表
void List_clear(List *list);                //清除链表中每个节点的值，但不销毁链表
void List_clear_destroy(List *list);        //清除链表并销毁链表

//获取链表节点数
#define List_count(A) ((A)->count)
//获取链表第一个节点的值
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
//获取链表最后一个节点的值
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void List_push(List *list, void *value);    //向链表末尾添加一个新节点
void *List_pop(List *list);                 //从链表末尾移除并返回节点的值

void List_unshift(List *list, void *value); //向链表开头添加一个新节点
void *List_shift(List *list);               //从链表开头移除并返回节点的值
void *List_remove(List *list, ListNode *node);//从链表中移除指定节点，并返回该节点的值
void *List_copy(List *list);                //复制链表并返回新的链表
void List_concat(List *list1, List *list2); //将两个链表连接起来
List *List_split(List *list, int index);    //分割链表，返回一个新的链表

//遍历链表的宏定义
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)


#endif