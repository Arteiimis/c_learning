//求4×4矩阵中，各行最大元素值之和//
#include<stdio.h>

int main() {
    int a[4][4] = {0};
    int max = 0, sum = 0;
    int i, j;

    for( i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            scanf("%d", &a[i][j]);
        }
    }

    for( i = 0; i < 4; i++ ) {
        for( j = 0; j < 4; j++ ) {
            printf("%d\t", a[i][j]);
            }
        printf("\n");
        }
    
    for( i = 0; i < 4; i++ ) {
        for( j = 0; j < 4; j++ ) {
            if( a[i][j] > max )
                max = a[i][j];
        }
        sum += max;
        max = 0;
    }    
    
    printf("%d\n", sum);
}