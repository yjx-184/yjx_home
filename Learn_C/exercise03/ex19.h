#ifndef _ex19_h
#define _ex19_h

#include "object.h"

//结构体“怪物”
struct Monster {
    Object proto;
    int hit_points; //怪兽生命值
};

typedef struct Monster Monster;

int Monster_attack(void *self, int damage);//怪物的攻击函数
int Monster_init(void *self);//怪物的初始化

//房间
struct Room {
    Object proto;

    Monster *bad_guy;//指向房间中的怪物

    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
};

typedef struct Room Room;

void *Room_move(void *self, Direction direction);//房间中的移动函数
int Room_attack(void *self, int damage);//房间中的攻击函数
int Room_init(void *self);//房间的初始化

//地图
struct Map {
    Object proto;
    Room *start;    //指向初始房间
    Room *location; //当前所在位置
};

typedef struct Map Map;

void *Map_move(void *self, Direction direction);//在地图中移动
int Map_attack(void *self, int damage);//在地图中执行攻击
int Map_init(void *self);//初始化

#endif