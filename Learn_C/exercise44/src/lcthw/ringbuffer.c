#undef NDEBUG
#include "ringbuffer.h"

RingBuffer *RingBuffer_create(int length)
{
    //分配内存并初始化环形缓冲区结构体
    RingBuffer *buffer = calloc(1, sizeof(RingBuffer));

    //设置缓冲区的实际长度，比请求的长度多1
    buffer->length = length + 1;
    buffer->start = 0;//初始化开始位置为0
    buffer->end = 0;//初始化结束位置为0
    buffer->buffer = calloc(buffer->length, 1);//分配缓冲区内存空间
    return buffer;//返回值：指向新建的RingBuffer结构体的指针

}

//销毁
void RingBuffer_destroy(RingBuffer *buffer)
{
    if(buffer) {//如果缓冲区不为空
        free(buffer->buffer);//释放缓冲区的数据缓冲区内存
        free(buffer);//释放环形缓冲区结构体内存
    }
}

//向环形缓冲区写入数据
int RingBuffer_write(RingBuffer *buffer, char *data, int length)
{
    //如果环形缓冲区为空，重置开始和结束位置为0
    if(RingBuffer_available_data(buffer) == 0) {
        buffer->start = buffer->end = 0;
    }
    //检查缓冲区中是否有足够的空间来写入数据
    check(length <= RingBuffer_available_space(buffer),
        "空间不足：%d 个请求，%d 个可用",
        RingBuffer_available_data(buffer), length);
    //将数据写入缓冲区
    void *result = memcpy(RingBuffer_ends_at(buffer), data, length);
    //检查写入是否成功
    check(result != NULL,"无法将数据写入缓冲区。");

    //提交写入操作并更新结束位置
    RingBuffer_commit_write(buffer, length);

    return length;//返回成功写入的数据长度

error:
    return -1;//如果发生错误，返回-1

}

//从环形缓冲区读取数据
int RingBuffer_read(RingBuffer *buffer, char *target, int amount)
{
    //检查缓冲区中是否有足够的数据可供读取
    check_debug(amount <= RingBuffer_available_data(buffer) ,
    "缓冲区不足：有 %d，需要 %d",
    RingBuffer_available_data(buffer), amount);

    //将数据从环形缓冲区复制到目标缓冲区
    void *result = memcpy(target, RingBuffer_starts_at(buffer), amount);
    check(result != NULL, "无法将数据写入缓冲区。");//检查读取是否成功

    //提交读取操作并更新开始位置
    RingBuffer_commit_read(buffer, amount);

    //如果读取后缓冲区为空，重置开始和结束位置为0
    if(buffer->end == buffer->start) {
        buffer->start = buffer->end = 0;
    }

    return amount;//返回成功读取的数据长度

error:
    return -1;//如果发生错误，返回-1
}

//从环形缓冲区中获取指定长度的数据，并返回一个bstring字符串
bstring RingBuffer_gets(RingBuffer *buffer, int amount)
{
    //检查获取的数据长度是否大于0
    check(amount > 0,"需要大于 0 才能获取，您给出了：%d", amount);
    //检查缓冲区中是否有足够的数据可供获取
    check_debug(amount <= RingBuffer_available_data(buffer),
        "缓冲区不足。"
    );

    //将缓冲区中的数据复制到一个新的bstring字符串
    bstring result = blk2bstr(RingBuffer_starts_at(buffer), amount);
    //检查复制是否成功
    check(result !=NULL, "创建获取结果失败。");
    //检查结果长度是否正确
    check(blength(result) == amount, "结果长度错误。");

    //提交读取操作并更新开始位置
    RingBuffer_commit_read(buffer, amount);
    //确保读取后的数据量有效
    assert(RingBuffer_available_data(buffer) >= 0 && "读取提交时出错。");

    return result;//返回包含数据的bstring字符串

error:
    return NULL;//如果发生错误，返回NULL
}