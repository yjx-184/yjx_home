#include "darray.h"


//创建动态数组
DArray *DArray_create(size_t element_size, size_t initial_max)
{
    DArray *array = malloc(sizeof(DArray));
    check_mem(array);
    array->max = initial_max;//设置数组最大容量
    check(array->max > 0, "您必须设置 initial_max > 0.");

    //为内容指针分配内存
    array->contents = calloc(initial_max, sizeof(void *));
    check_mem(array->contents);

    array->end = 0;//初始化数组结束索引
    array->element_size = element_size;
    array->expand_rate = DEFAULT_EXPAND_RATE;

    return array;

error:
    if(array) free(array);
    return NULL;
}

//清除数组内容而不销毁数组本身
void DArray_clear(DArray *array)
{
    int i = 0;
    if(array->element_size > 0) {//仅在元素大小大于0的时候清除内容
        for(i = 0; i < array->max; i++) {
            if(array->contents[i] != NULL) {
                free(array->contents[i]);//释放每个元素
            }
        }
    }
}

//调整数组大小
static inline int DArray_resize(DArray *array, size_t newsize)
{
    array->max = newsize;//设置新的容量
    check(array->max > 0, "newsize必须是 > 0.");
    //重新分配内存
    void *contents = realloc(array->contents, array->max * sizeof(void *));

    // 检查内容并假设 realloc 不会在发生错误时损害原始内容
    check_mem(contents);

    array->contents = contents;//更新内容指针数组

    return 0;
error:
    return -1;
}

//扩展数组容量
int DArray_expand(DArray *array)
{
    size_t old_max = array->max;//记录旧的最大容量
    check(DArray_resize(array, array->max + array->expand_rate) == 0,
            "无法将数组扩展至新大小: %d",
            array->max + (int)array->expand_rate);
    //将新扩展部分初始化
    memset(array->contents + old_max, 0, array->expand_rate + 1);
    return 0;

error:
    return -1;
}

//收缩
int DArray_contract(DArray *array)
{
    int new_size = array->end < (int)array->expand_rate ? (int)array->expand_rate : array->end;

    return DArray_resize(array, new_size + 1);
}

//销毁
void DArray_destroy(DArray *array)
{
    if(array) {
        if(array->contents) free(array->contents);
        free(array);
    }
}

//清除数组并销毁数组
void DArray_clear_destroy(DArray *array)
{
    DArray_clear(array);
    DArray_destroy(array);
}

//向数组中添加元素
int DArray_push(DArray *array, void *el)
{
    array->contents[array->end] = el;//将元素添加到数组末尾
    array->end++;//更新数组结束索引

    if(DArray_end(array) >= DArray_max(array)) {
        return DArray_expand(array);//如果数组已经满了则扩展容量
    } else {
        return 0;
    }
}

//从数组中弹出元素
void *DArray_pop(DArray *array)
{
    check(array->end - 1 >= 0, "尝试从空数组中弹出。");

    void *el = DArray_remove(array, array->end - 1);
    array->end--;

    if(DArray_end(array) > (int)array->expand_rate && DArray_end(array) % array->expand_rate) {
        DArray_contract(array);
    }

    return el;
error:
    return NULL;
}