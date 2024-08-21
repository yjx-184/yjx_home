#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

//销毁
void Object_destroy(void *self)
{
    Object *obj = self;

    if(obj) {
        if(obj->description) free(obj->description);
        free(obj);
    }
}

//打印对象信息
void Object_describe(void *self) 
{
    Object *obj = self;
    printf("%s.\n",obj->description);
}

//初始化
int Object_init(void *self)
{
    return 1;
}

//移动
void *Object_move(void *self, Direction direction)
{
    printf("你不能移动到那个地方\n");
    return NULL;
}

//伤害
int Object_attack(void *self, int damage)
{
    printf("你不能伤害这些\n");
    return 0;
}

//创建
void *Object_new(size_t size, Object proto, char *description)
{
    //设置默认函数（如果未设置）
    if(!proto.init) proto.init = Object_init;
    if(!proto.describe) proto.describe = Object_describe;
    if(!proto.destroy) proto.destroy = Object_destroy;
    if(!proto.attack) proto.attack = Object_attack;
    if(!proto.move) proto.move = Object_move;

    // 这看起来很奇怪，但我们可以创建一个大小相同的结构体，
    // 然后指向另一个指针来“转换”它
    Object *el = calloc(1, size);
    assert(el != NULL);//添加了assert();
    *el = proto;
    

    // 复制描述
    el->description = strdup(description);

    //初始化
    if(!el->init(el)) {
        el->destroy(el);
        return NULL;
    } else {
        return el;
    }
}