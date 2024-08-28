#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
返回一个二维数组
思路：建立一个二维数组来存储提到的学生的信息

*/

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

//通过参数当作返回值返回
void Total_score(int st1, int st2, int *sum, int *average)
{
    *sum = st1 + st2;
    *average = (st1 + st2) / 2;
}

// 创建二维数组
int **Create_storage(int x, int y)
{
    int **array = (int**)malloc(sizeof(int*) * x);
    for(int i = 0; i < x; i++) {
        array[i] = (int*)malloc(sizeof(int) * y);
    }
    return array;
}

//输出打印
void Print_storage(int **array, int x, int y)
{
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%-10d",array[i][j]);
        }
        printf("\n");
    }
}

void Free_storage(int **array, int x) 
{
    for(int i = 0; i < x; i++) {
        free(array[i]);
    }
    free(array);
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

    int **array = Create_storage(2, 3);
    array[0][0] = tom->id;
    array[0][1] = tom->class;
    array[0][2] = tom->score;
    array[1][0] = yyy->id;
    array[1][1] = yyy->class;
    array[1][2] = yyy->score;

    printf("存储的学生信息\n");
    Print_storage(array, 2, 3);

    Free_storage(array, 2);


    free(tom);
    free(yyy);




    return 0;
}
