//打印所有水仙花数。所谓水仙花数是指一个三位数，其各位数字的立方和正好等于该数本身，如153=1^3+5^3+3^3//
#include<stdio.h>

int main() {
    int i, j, k, sum;
    for ( i = 1; i <= 9; i++ ) {
        for ( j = 0; j <= 9; j++ ) {
            for ( k = 0; k <= 9; k++ ) {
                sum = i*100 + j*10 + k;
                if ( sum == i*i*i + j*j*j + k*k*k )
                    printf("%d\n", sum);
            }
        }
    }
}