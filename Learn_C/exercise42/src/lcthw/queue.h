#ifndef _QUEUE_H
#define _QUEUE_H

#include "dbg.h"

typedef struct QueueNode {
    void *value;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *first;
    QueueNode *last;
    int count;
} Queue;

static inline Queue *Queue_create(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    assert(queue != NULL);
    queue->first = NULL;
    queue->last = NULL;
    queue->count = 0;
    return queue;
}

// 销毁队列并释放内存
static inline void Queue_destroy(Queue *queue) {
    while (queue->first != NULL) {
        QueueNode *node = queue->first;
        queue->first = queue->first->next;
        free(node);
    }
    free(queue);
}

// 向队列末尾发送（添加）一个元素
static inline void Queue_send(Queue *queue, void *value) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    assert(node != NULL);
    node->value = value;
    node->next = NULL;
    if (queue->last == NULL) {
        queue->first = node;
        queue->last = node;
    } else {
        queue->last->next = node;
        queue->last = node;
    }
    queue->count++;
}

// 从队列开头接收（移除）一个元素
static inline void *Queue_recv(Queue *queue) {
    if (queue->first == NULL) return NULL;
    QueueNode *node = queue->first;
    void *value = node->value;
    queue->first = queue->first->next;
    if (queue->first == NULL) queue->last = NULL;
    free(node);
    queue->count--;
    return value;
}

// 查看队列的第一个元素但不移除
static inline void *Queue_peek(Queue *queue) {
    if (queue->first == NULL) return NULL;
    return queue->first->value;
}

// 获取队列中元素的数量
static inline int Queue_count(Queue *queue) {
    return queue->count;
}


#define QUEUE_FOREACH(Q, V) QueueNode *_node = NULL;\
                            QueueNode *V = NULL;\
for(V = _node = Q->first; _node != NULL; V = _node = _node->next)


#endif