#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "ex19.h"

int Monster_attack(void *self, int damage)
{
    assert(self != NULL);
    Monster *monster = self;

    printf("你攻击 %s!\n", monster->_(description));

    monster->hit_points -= damage;

    if(monster->hit_points > 0) {
        printf("他还活着\n");
        return 0;
    } else {
        printf("他已经死了。\n");
        return 1;
    }
}

int Monster_init(void *self)
{
    assert(self != NULL);
    Monster *monster = self;
    monster->hit_points = 10;
    return 1;
}

Object MonsterProto = {
    .init = Monster_init,
    .attack = Monster_attack
};

void *Room_move(void *self, Direction direction)
{
    assert(self != NULL);
    Room *room = self;
    Room *next = NULL;

    if(direction == NORTH && room->north) {
        printf("你前往北边,进入：");
        next = room->north;
    } else if(direction == SOUTH && room->south) {
        printf("你前往南边，进入：\n");
        next = room->south;
    } else if(direction == EAST && room->east) {
        printf("你前往东边，进入：\n");
        next = room->east;
    } else if(direction == WEST && room->west) {
        printf("你前往西边，进入：\n");
        next = room->west;
    } else {
        printf("你不能去这个方向。");
        next = NULL;
    }
    //如果存在下一个房间
    if(next) {
        next->_(describe)(next);
    }

    return next;
}

int Room_attack(void *self, int damage)
{
    assert(self != NULL);
    Room *room = self;
    Monster *monster = room->bad_guy;
    //如果房间有怪物
    if(monster) {
        monster->_(attack)(monster, damage);
        return 1;
    } else {
        printf("你在原地乱搞。哥们。\n");
        return 0;
    }
}

Object RoomProto = {
    .move = Room_move,
    .attack = Room_attack
};

//地图移动函数，控制玩家在地图上移动
void *Map_move(void *self, Direction direction)
{
    assert(self != NULL);
    Map *map = self;
    Room *location = map->location;
    Room *next = NULL;

    //调用当前房间的移动函数，得到下一个房间
    next = location->_(move)(location, direction);

    if(next) {
        map->location = next;
    }

    return next;
}

int Map_attack(void *self, int damage)
{
    assert(self != NULL);
    Map* map = self;
    Room *location = map->location;
    assert(location != NULL);
    return location->_(attack)(location, damage);
}

int Map_init(void *self)
{
    assert(self != NULL);
    Map *map = self;

    //在地图上制作房间
    Room *hall = NEW(Room, "大厅");
    Room *throne = NEW(Room, "王的房间");
    Room *arena = NEW(Room, "竞技场，有牛头怪");
    Room *kitchen = NEW(Room, "厨房，你现在有刀了");

    //把坏人放到竞技场
    arena->bad_guy = NEW(Monster, "邪恶的牛头怪");

    //设置房间
    hall->north = throne;

    throne->west = arena;
    throne->east = kitchen;
    throne->south = hall;

    arena->east = throne;
    kitchen->west = throne;

    //开始地图并将角色从大厅移出
    map->start = hall;
    map->location = hall;

    return 1;
}

Object MapProto = {
    .init = Map_init,
    .move = Map_move,
    .attack = Map_attack
};

//处理输入信息
int process_input(Map *game)
{
    assert(game != NULL);
    printf("\n> ");

    char ch = getchar();
    getchar();

    int damage = rand() % 4;

    switch(ch) {
        case -1:
            printf("放弃？你输了。\n");
            return 0;
            break;

        case 'n':
            game->_(move)(game, NORTH);
            break;

        case 's':
            game->_(move)(game, SOUTH);
            break;

        case 'e':
            game->_(move)(game, EAST);
            break;

        case 'w':
            game->_(move)(game, WEST);
            break;

        case 'a':

            game->_(attack)(game, damage);
            break;
        case 'l':
            printf("你可以去:\n");
            if(game->location->north) printf("北边\n");
            if(game->location->south) printf("南边\n");
            if(game->location->east) printf("东边\n");
            if(game->location->west) printf("西边\n");
            break;

        default:
            printf("什么? : %d\n", ch);
    }

    return 1;

}

int main(int argc, char *argv[])
{
    //设置随机
    srand(time(NULL));

    //制作地图
    Map *game = NEW(Map, "牛头怪的大厅。");
    assert(game != NULL);
    printf("玩家初始位置");
    game->location->_(describe)(game->location);

    while(process_input(game)) {

    }

    return 0;
}