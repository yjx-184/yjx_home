// #include <stdio.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <string.h>

// struct Person {
//     char *name;
//     int age;
//     int height;
//     int weight;
// };

// struct Person *Person_create(char *name, int age, int height, int weight)
// {
//     struct Person *who = malloc(sizeof(struct Person));
//     assert(who != NULL);

//     who->name = strdup(name);
//     who->age = age;
//     who->height = height;
//     who->weight = weight;

//     return who;
// }

// void Person_destroy(struct Person *who)
// {
//     assert(who != NULL);

//     free(who->name);
//     free(who);
// }

// void Person_print(struct Person *who)
// {
//     printf("Name: %s\n", who->name);
//     printf("\tAge: %d\n", who->age);
//     printf("\tHeight: %d\n", who->height);
//     printf("\tWeight: %d\n", who->weight);
// }

// int main(int argc, char *argv[])
// {
//     struct Person *joe = Person_create(
//             "Joe Alex", 32, 64, 140);

//     struct Person *frank = Person_create(
//             "Frank Blank", 20, 72, 180);

//     printf("Joe is at memory location %p:\n", joe);
//     Person_print(joe);

//     printf("Frank is at memory location %p:\n", frank);
//     Person_print(frank);

//     joe->age += 20;
//     joe->height -= 2;
//     joe->weight += 40;
//     Person_print(joe);

//     frank->age += 20;
//     frank->weight += 20;
//     Person_print(frank);

//     Person_destroy(joe);
//     Person_destroy(frank);

//     return 0;
// }

//附加题
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    int height;
    int weight;
};

void Person_create(struct Person *who, const char *name, int age, int height, int weight)
{
    strncpy(who->name, name, sizeof(who->name )- 1);
    who->name[sizeof(who->name) - 1] = '\0';
    who->age = age;
    who->height = height;
    who->weight = weight;
}


void Person_print(const struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    //栈上结构体实例
    struct Person joe;
    struct Person frank;

    //初始化
    Person_create(&joe, "JOe Alex", 32, 64, 140);
    Person_create(&frank, "Frank Blank", 20, 72, 180);

    printf("Joe is at memory location %p:\n", (void *)&joe);
    Person_print(&joe);

    printf("Frank is at memory location %p:\n", (void *)&frank);
    Person_print(&frank);

    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(&joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(&frank);

    return 0;
}