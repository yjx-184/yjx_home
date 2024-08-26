#ifndef _RingBuffer_Posix_h
#define _RingBuffer_Posix_h

#include "bstrlib.h"

// 定义一个环形缓冲区结构体
typedef struct {
    char *buffer;  // 缓冲区的指针
    int length;    // 缓冲区的长度
    int start;     // 数据读取的起始位置
    int end;       // 数据写入的结束位置
    int fd;        // 文件描述符，用于共享内存
    char *shm_name; // 共享内存名称
} RingBufferPOSIX;

// 创建一个指定长度的环形缓冲区
RingBufferPOSIX *RingBufferPOSIX_create(int length, const char *name);

// 销毁环形缓冲区并释放内存
void RingBufferPOSIX_destroy(RingBufferPOSIX *buffer);

// 从环形缓冲区读取指定数量的数据到目标位置
int RingBufferPOSIX_read(RingBufferPOSIX *buffer, char *target, int amount);

// 向环形缓冲区写入指定长度的数据
int RingBufferPOSIX_write(RingBufferPOSIX *buffer, char *data, int length);

// 判断环形缓冲区是否为空
int RingBufferPOSIX_empty(RingBufferPOSIX *buffer);

// 判断环形缓冲区是否已满
int RingBufferPOSIX_full(RingBufferPOSIX *buffer);

// 获取缓冲区可用的数据量
int RingBufferPOSIX_available_data(RingBufferPOSIX *buffer);

// 获取缓冲区可用的空间量
int RingBufferPOSIX_available_space(RingBufferPOSIX *buffer);

// 从缓冲区获取指定数量的数据并返回bstring类型
bstring RingBufferPOSIX_gets(RingBufferPOSIX *buffer, int amount);

#define RingBufferPOSIX_available_data(B) (((B)->end + (B)->length - (B)->start) % (B)->length)
#define RingBufferPOSIX_available_space(B) ((B)->length - 1 - RingBufferPOSIX_available_data(B))
#define RingBufferPOSIX_full(B) (RingBufferPOSIX_available_space(B) == 0)
#define RingBufferPOSIX_empty(B) (RingBufferPOSIX_available_data(B) == 0)
#define RingBufferPOSIX_puts(B, D) RingBufferPOSIX_write((B), bdata((D)), blength((D)))
#define RingBufferPOSIX_get_all(B) RingBufferPOSIX_gets((B), RingBufferPOSIX_available_data((B)))
#define RingBufferPOSIX_starts_at(B) ((B)->buffer + (B)->start)
#define RingBufferPOSIX_ends_at(B) ((B)->buffer + (B)->end)
#define RingBufferPOSIX_commit_read(B, A) ((B)->start = ((B)->start + (A)) % (B)->length)
#define RingBufferPOSIX_commit_write(B, A) ((B)->end = ((B)->end + (A)) % (B)->length)

#endif