/*
#ifndef _STACK_H
#define _STACK_H

#include "dbg.h"

//栈节点
typedef struct StackNode {
    void *value; //存储节点的值
    struct StackNode *next;//指向下一个节点
} StackNode;

//栈
typedef struct Stack {
    StackNode *top;//指向栈顶
    int count;//记录栈中元素数量
} Stack;

//创建栈
static inline Stack *Stack_create() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    assert(stack != NULL);
    stack->top = NULL;
    stack->count = 0;
    return stack;
}

static inline void Stack_destroy(Stack *stack) {
    while (stack->top != NULL) {
        StackNode *node = stack->top;
        stack->top = node->next;
        free(node);
    }
    free(stack);
}

//向栈顶压入一个元素
static inline void Stack_push(Stack *stack, void *value) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    assert(node != NULL);
    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
}

//弹出栈顶元素并返回该值
static inline void *Stack_pop(Stack *stack) {
    if (stack ->top == NULL) return NULL;
    StackNode *node = stack->top;
    void *value = node->value;
    stack->top = stack->top->next;
    free(node);
    stack->count--;
    return value;
}

//查看栈顶元素
static inline void *Stack_peek(Stack *stack) {
    if(stack->top == NULL) return NULL;
    return stack->top->value;
}

//获取栈中元素数量
static inline int Stack_count(Stack *stack) {
    return stack->count;
}

//遍历栈中元素
#define STACK_FOREACH(S, V) StackNode *_node = NULL;\
                            StackNode *V = NULL;\
for(V = _node = S->top; _node != NULL; V = _node = _node->next)


#endif
*/





#ifndef _STACK_H
#define _STACK_H


#include "darray.h"

typedef DArray Stack;

#define Stack_create() DArray_create(sizeof(void *), 10)

#define Stack_destroy(stack) DArray_clear_destroy(stack)

#define Stack_push(stack, value) DArray_push(stack, value)

#define Stack_pop(stack) DArray_pop(stack)

#define Stack_peek(stack) DArray_last(stack)

#define Stack_count(stack) DArray_count(stack)

#define STACK_FOREACH(stack, cur) \
    for (int _i = 0; _i < DArray_count(stack) && ((cur) = DArray_get(stack, _i), 1); _i++)
#endif