#ifndef lcthw_List_h
#define lcthw_List_h

#include "dbg.h"

struct ListNode;

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();//创建链表
ListNode *ListNode_create(void *value);//创建链表节点
void List_destroy(List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);
void ListNode_destroy(ListNode *value);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void List_push(List *list, void *value);
void *List_pop(List *list);

void List_unshift(List *list, void *value);
void *List_shift(List *list);
void *List_remove(List *list, ListNode *node);
void *List_copy(List *list);
void List_concat(List *list1, List *list2);
List *List_split(List *list, int index);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)


#endif