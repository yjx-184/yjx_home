#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *Create_storage(int rows, int cols)
{
    int (*array)[cols] = (int(*)[cols])malloc(sizeof(int) * rows * cols);
    if(array == NULL) {
        printf("内存分配给二维数组失败！\n");
        exit(1);
    }

    //初始化
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = 0;
        }
    }

    return array;

}
int main() {

    // 创建二维数组
    int rows = 3, cols = 4;
    int (*array)[cols] = (int (*)[cols])Create_storage(rows, cols);


    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = (10 + j);
        }
    }


    // 打印二维数组
    printf("二维数组内容：\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    free(array);
    return 0;
}
/*
利用数组指针形式申请一个二位数组

#include<stdio.h>  
#include<stdlib.h>  
  
  
int main()  
{  
    int i,j;  
    //申请一个3行2列的整型数组  
    int (*a)[2]=(int(*)[2])malloc(sizeof(int)*3*2);  
    for(i=0;i<3;i++)  
    {
        for(j=0;j<2;j++)  
        {  
            printf("%p\n",&a[i][j]);  //输出数组每个元素地址，每个元素的地址是连续的
        }
    }
 
 
    free(a);
    return 0;  
}

*/