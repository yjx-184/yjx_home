#include "../src/lcthw/ringbuffer_posix.h"
#include "minunit.h"

int tests_run = 0;

char *test_create_destroy()
{
    RingBufferPOSIX *buffer = RingBufferPOSIX_create(10, "/test_ringbuffer");
    mu_assert(buffer != NULL, "创建 RingBufferPOSIX 失败");
    mu_assert(buffer->length == 11, "缓冲区长度不正确");
    mu_assert(RingBufferPOSIX_empty(buffer), "缓冲区应该为空");
    mu_assert(RingBufferPOSIX_available_space(buffer) == 10, "缓冲区应该有10字节的空间");

    RingBufferPOSIX_destroy(buffer);
    return NULL;
}

char *test_write_read()
{
    RingBufferPOSIX *buffer = RingBufferPOSIX_create(10, "/test_ringbuffer");
    char *data = "abcdef";

    int rc = RingBufferPOSIX_write(buffer, data, 6);
    mu_assert(rc == 6, "写入数据到缓冲区失败");
    mu_assert(RingBufferPOSIX_available_data(buffer) == 6, "缓冲区应该有6字节的数据");
    mu_assert(RingBufferPOSIX_available_space(buffer) == 4, "缓冲区剩余空间应该是4字节");

    char target[7];
    rc = RingBufferPOSIX_read(buffer, target, 6);
    mu_assert(rc == 6, "读取数据失败");
    target[6] = '\0';
    mu_assert(strcmp(target, data) == 0, "读取的数据不正确");

    RingBufferPOSIX_destroy(buffer);
    return NULL;
}

char *test_gets()
{
    RingBufferPOSIX *buffer = RingBufferPOSIX_create(10, "/test_ringbuffer");
    char *data = "abcdefgh";
    RingBufferPOSIX_write(buffer, data, 8);

    bstring result = RingBufferPOSIX_gets(buffer, 5);
    mu_assert(result != NULL, "从缓冲区获取数据失败");
    mu_assert(bstrcmp(result, bfromcstr("abcde")) == 0, "获取的数据不正确");

    bdestroy(result);
    RingBufferPOSIX_destroy(buffer);
    return NULL;
}

// 运行所有测试
char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create_destroy);
    mu_run_test(test_write_read);
    mu_run_test(test_gets);

    return NULL;
}

RUN_TESTS(all_tests);