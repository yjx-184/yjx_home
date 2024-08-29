#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将指针转化为二维数组

int main() {
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {0, 9, 10, 532}
    };

    int (*p)[4] = array;
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 4; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}