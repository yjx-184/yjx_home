#ifndef _RingBuffer_h
#define _RingBuffer_h


#include "bstrlib.h"

//定义一个环形缓冲区结构体
typedef struct {
    char *buffer;//缓冲区的指针
    int length;//缓冲区的长度
    int start;//数据读取的起始位置
    int end;//数据写入的结束位置
} RingBuffer;

//创建一个指定长度的环形缓冲区
RingBuffer *RingBuffer_create(int length);

//销毁环形缓冲区并释放内存
void RingBuffer_destroy(RingBuffer *buffer);

//从环形缓冲区读取指定数量的数据到目标位置
int RingBuffer_read(RingBuffer *buffer, char *target, int amount);

//向环形缓冲区写入指定长度的数据
int RingBuffer_write(RingBuffer *buffer, char *data, int length);

//判断环形缓冲区是否为空
int RingBuffer_empty(RingBuffer *buffer);

//判断环形缓冲区是否已满
int RingBuffer_full(RingBuffer *buffer);

//获取缓冲区可用的数据量
int RingBuffer_available_data(RingBuffer *buffer);

//获取缓冲区可用的空间量
int RingBuffer_available_space(RingBuffer *buffer);

//从缓冲区获取指定数量的数据并返回bstring类型
bstring RingBuffer_gets(RingBuffer *buffer, int amount);

//宏定义：计算缓冲区中可用的数据量
#define RingBuffer_available_data(B) (((B)->end + 1) % (B)->length - (B)->start - 1)

//计算缓冲区中可用的空间量
#define RingBuffer_available_space(B) ((B)->length - (B)->end - 1)

//判断缓冲区是否已满
#define RingBuffer_full(B) (RingBuffer_available_data((B)) - (B)->length == 0)

//判断缓冲区是否为空
#define RingBuffer_empty(B) (RingBuffer_available_data((B)) == 0)

//将bstring数据写入缓冲区
#define RingBuffer_puts(B, D) RingBuffer_write((B), bdata((D)), blength((D)))

//获取缓冲区中的所有数据
#define RingBuffer_get_all(B) RingBuffer_gets((B), RingBuffer_available_data((B)))

//获取缓冲区中数据的起始位置
#define RingBuffer_starts_at(B) ((B)->buffer + (B)->start)

//获取缓冲区中数据的结束位置
#define RingBuffer_ends_at(B) ((B)->buffer + (B)->end)

//提交读取操作后更新缓冲区起始位置
#define RingBuffer_commit_read(B, A) ((B)->start = ((B)->start + (A)) % (B)->length)

#define RingBuffer_commit_write(B, A) ((B)->end = ((B)->end + (A)) % (B)->length)

#endif