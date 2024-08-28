#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//返回一个malloc地址
typedef struct Student {
    char name[30];
    int id;
    int class;
    int score;
} Student;

Student *create_student(const char *name, int id, int class, int score) 
{
    Student *student = (Student*)malloc(sizeof(Student));
    if (student == NULL) {
        printf("内存分配失败!\n");
        exit(1); 
    }

    strncpy(student->name, name, sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0';
    student->id = id;
    student->class = class;
    student->score = score;

    return student;
}

int main() {
    Student *tom = create_student("Tom", 1, 2, 100);
    printf("姓名：%s , 学号：%d , 班级：%d , 分数：%d \n", tom->name, tom->id, tom->class, tom->score);
    free(tom);
}