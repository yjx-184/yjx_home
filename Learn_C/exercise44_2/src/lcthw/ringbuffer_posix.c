#include "ringbuffer_posix.h"


RingBufferPOSIX *RingBufferPOSIX_create(int length, const char *name)
{
    RingBufferPOSIX *buffer = malloc(sizeof(RingBufferPOSIX));
    if (!buffer) {
        perror("分配 RingBufferPOSIX 结构体内存失败");
        return NULL;
    }

    buffer->length = length + 1; 
    buffer->start = 0;
    buffer->end = 0;
    buffer->shm_name = strdup(name);

    buffer->fd = shm_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (buffer->fd == -1) {
        perror("打开共享内存失败");
        free(buffer);
        return NULL;
    }

    if (ftruncate(buffer->fd, buffer->length) == -1) {
        perror("设置共享内存大小失败");
        close(buffer->fd);
        free(buffer);
        return NULL;
    }

    buffer->buffer = mmap(NULL, buffer->length, PROT_READ | PROT_WRITE, MAP_SHARED, buffer->fd, 0);
    if (buffer->buffer == MAP_FAILED) {
        perror("映射共享内存失败");
        close(buffer->fd);
        free(buffer);
        return NULL;
    }

    return buffer;
}

void RingBufferPOSIX_destroy(RingBufferPOSIX *buffer)
{
    if (buffer) {
        munmap(buffer->buffer, buffer->length);
        close(buffer->fd);
        shm_unlink(buffer->shm_name);
        free(buffer->shm_name);
        free(buffer);
    }
}

int RingBufferPOSIX_write(RingBufferPOSIX *buffer, char *data, int length)
{
    if (length > RingBufferPOSIX_available_space(buffer)) {
        fprintf(stderr, "缓冲区空间不足：请求 %d 字节，剩余 %d 字节\n", length, RingBufferPOSIX_available_space(buffer));
        return -1;
    }

    memcpy(RingBufferPOSIX_ends_at(buffer), data, length);
    RingBufferPOSIX_commit_write(buffer, length);
    return length;
}

int RingBufferPOSIX_read(RingBufferPOSIX *buffer, char *target, int amount)
{
    if (amount > RingBufferPOSIX_available_data(buffer)) {
        fprintf(stderr, "缓冲区数据不足：已有 %d 字节，要求 %d 字节\n", RingBufferPOSIX_available_data(buffer), amount);
        return -1;
    }

    memcpy(target, RingBufferPOSIX_starts_at(buffer), amount);
    RingBufferPOSIX_commit_read(buffer, amount);
    return amount;
}

bstring RingBufferPOSIX_gets(RingBufferPOSIX *buffer, int amount)
{
    if (amount > RingBufferPOSIX_available_data(buffer)) {
        fprintf(stderr, "缓冲区数据不足：已有 %d 字节，要求 %d 字节\n", RingBufferPOSIX_available_data(buffer), amount);
        return NULL;
    }

    bstring result = blk2bstr(RingBufferPOSIX_starts_at(buffer), amount);
    RingBufferPOSIX_commit_read(buffer, amount);
    return result;
}