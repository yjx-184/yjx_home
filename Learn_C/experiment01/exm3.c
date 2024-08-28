#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//从参数返回值返回


typedef struct Student {
    char name[30];
    int id;
    int class;
    int score;
} Student;

Student *Create_student(const char *name, int id, int class, int score) 
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

void Total_score(int st1, int st2, int *sum, int *average)
{
    *sum = st1 + st2;
    *average = (st1 + st2) / 2;
}

int main() {
    int sum = 0;
    int average = 0;

    Student *tom = Create_student("Tom", 1, 2, 100);
    Student *yyy = Create_student("Yyy", 2, 2, 80);

    printf("姓名：%s , 学号：%d , 班级：%d , 分数：%d \n", tom->name, tom->id, tom->class, tom->score);
    printf("姓名：%s , 学号：%d , 班级：%d , 分数：%d \n", yyy->name, yyy->id, yyy->class, yyy->score);

    Total_score(tom->score, yyy->score, &sum, &average);

    printf("他两总分：%d , 平均分：%d \n", sum, average);

    free(tom);
    free(yyy);
}