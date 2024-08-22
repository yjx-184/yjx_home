
#ifndef _object_h
#define _object_h

#include <stddef.h>

typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;


typedef struct {
    char *description;      //存储对象的描述或名称
    int (*init)(void *self);    //初始化对象
    void (*describe)(void *self);    //打印对象信息
    void (*destroy)(void *self);    //销毁对象，释放内存
    void *(*move)(void *self, Direction direction); //移动
    int (*attack)(void *self, int damage);  //对象攻击，damage表示伤害值
} Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N
#endif