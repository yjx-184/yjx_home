#include "minunit.h"
#include "../src/lcthw/ringbuffer.h"

int tests_run = 0;

//测试环形缓冲区的创建和销毁
char *test_create_destroy() {
    //创建一个长度为10的环形缓冲区
    RingBuffer *buffer = RingBuffer_create(10);
    //验证是否创建成功
    mu_assert(buffer != NULL, "创建缓冲区失败");
    //验证缓冲区是否正确
    mu_assert(buffer->length == 11, "缓冲区长度不正确");
    //验证缓冲区中数据量是否为0
    mu_assert(RingBuffer_empty(buffer), "缓冲区不应该有数据");
    //验证缓冲区中空间量是否为10
    mu_assert(RingBuffer_available_space(buffer) == 10, "缓冲区应该有10个字节的空间");

    //销毁缓冲区并释放内存
    RingBuffer_destroy(buffer);
    return NULL;
}

//测试写入和读取操作
char *test_write_read() {
    //创建一个长度为10的环形缓冲区
    RingBuffer *buffer = RingBuffer_create(10);
    char *data = "abcdef";

    //向缓冲区写入6个字节的数据
    int rc = RingBuffer_write(buffer, data, 6);
    //验证写入操作是否成功
    mu_assert(rc == 6, "写入数据到缓冲区失败");
    //验证缓冲区中数据量是否为6
    mu_assert(RingBuffer_available_data(buffer) == 6, "缓冲区应该有6个字节");
    //验证缓冲区中剩余空间量是否为4
    mu_assert(RingBuffer_available_space(buffer) == 4, "缓冲区剩余空间应该是4个字节");

    char target[7];
    //从缓冲区中读取6个字节的数据
    rc = RingBuffer_read(buffer, target, 6);
    //验证读取操作是否成功
    mu_assert(rc == 6, "读取失败");
    //在字符串末尾添加终止符以进行比较
    target[6] = '\0';
    //验证读取数据是否与原始数据一致
    mu_assert(strcmp(target, data) == 0, "从缓冲区读取的数据不正确");
    //销毁缓冲区并释放内存
    RingBuffer_destroy(buffer);
    return NULL;
}

//测试获取数据到bstring的操作
char *test_gets() {
    //创建一个长度为10的环形缓冲区
    RingBuffer *buffer = RingBuffer_create(10);
    //向缓冲区写入一个8字节的数据
    char *data = "abcdefgh";
    RingBuffer_write(buffer, data, 8);
    //从缓冲区获取5个字节的数据
    bstring result = RingBuffer_gets(buffer, 5);
    //验证获取操作是否成功
    mu_assert(result != NULL, "从缓冲区获取数据失败");
    //验证获取的数据是否正确
    mu_assert(bstrcmp(result, bfromcstr("abcde")) == 0, "从缓冲区获取的数据不正确");

    //销毁bstring对象
    bdestroy(result);
    //销毁缓冲区并释放内存
    RingBuffer_destroy(buffer);
    return NULL;

}

//测试环形缓冲区的循环行为
// char *test_ring_behavior() {
//     //创建一个长度为10的环形缓冲区
//     RingBuffer *buffer = RingBuffer_create(10);
//     char *data1 = "abcd";
//     char *data2 = "efghij";
//     //向缓冲区写入4个字节的数据
//     int rc = RingBuffer_write(buffer, data1, 4);
//     mu_assert(rc == 4, "写入data1数据到缓冲区失败");
//     //向缓冲区写入6个字节的数据 
//     rc = RingBuffer_write(buffer, data2, 6);
//     mu_assert(rc == 6, "写入data2数据到缓冲区失败");
//     //验证缓冲区是否已满
//     mu_assert(RingBuffer_full(buffer), "写入10个字节数据后缓冲区应该已满。");
//     char target[11];
//     //从缓冲区读取10个字节的数据
//     RingBuffer_read(buffer, target, 10);    
//     mu_assert(rc == 10, "没有读取到10个字节")
//     //在字符串末尾添加终止符进行比较
//     target[10] = '\0';
//     //验证读取的数据是否正确处理了缓冲区的循环行为
//     mu_assert(strcmp(target, "abcdefghij") == 0, "环形缓冲区未正确处理循环行为。");

//     //销毁缓冲区并释放内存
//     RingBuffer_destroy(buffer);
//     return NULL;
// }

//运行所有测试
char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create_destroy);
    mu_run_test(test_write_read);
    mu_run_test(test_gets);

    return NULL;
}

RUN_TESTS(all_tests);