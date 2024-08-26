#ifndef _DArray_h
#define _DArray_h

#include "dbg.h"

typedef struct DArray {
    int end;                //数组中最后一个元素的索引+1
    int max;                //数组中最大容量
    size_t element_size;    //每个元素的大小
    size_t expand_rate;     //数组扩展的步长
    void **contents;        //指向存储元素的指针数组
} DArray;

//创造一个动态数组
DArray *DArray_create(size_t element_size, size_t initial_max);

//销毁动态数组
void DArray_destroy(DArray *array);

//清除数组内容而不销毁数组本身
void DArray_clear(DArray *array);

//扩展数组的容量
int DArray_expand(DArray *array);

//收缩数组的容量到实际使用量
int DArray_contract(DArray *array);

//向数组中添加一个元素
int DArray_push(DArray *array, void *el);

//从数组中弹出一个元素
void *DArray_pop(DArray *array);

//清除并销毁数组
void DArray_clear_destroy(DArray *array);

#define DArray_last(A) ((A)->contents[(A)->end - 1])
#define DArray_first(A) ((A)->contents[0])
#define DArray_end(A) ((A)->end)
#define DArray_count(A) DArray_end(A)
#define DArray_max(A) ((A)->max)

//默认的扩展步长
#define DEFAULT_EXPAND_RATE 300

//设置数组中的某个元素
static  inline void DArray_set(DArray *array, int i, void *el)
{
    check(i < array->max, "darray 尝试设置超过最大值");
    if(i > array->end) array->end = i;//更新索引
    array->contents[i] = el;

error:
    return;
}

//获取数组中某个元素
static inline void *DArray_get(DArray *array, int i)
{
    check(i < array->max, "darray 尝试超越最大值");
    return array->contents[i];

error:
    return NULL;
}

//移除数组中的某个元素并返回该元素
static inline void *DArray_remove(DArray *array, int i)
{
    void *el = array->contents[i];

    array->contents[i] = NULL;

    return el;
}

//为数组中新元素分配内存
static inline void *DArray_new(DArray *array)
{
    check(array->element_size > 0, "不能在 0 大小的 darrays 上使用 DArray_new。");

    return calloc(1, array->element_size);

error:
    return NULL;
}

//释放某个元素的内存
#define DArray_free(E) free((E))

#endif