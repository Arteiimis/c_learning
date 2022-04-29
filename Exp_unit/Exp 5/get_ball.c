//有两个红球，三个黄球，四个白球，任意取五个球，其中必须有一个黄球，编程输出所有的可能方案。//
#include<stdio.h>

int main() {
    int i, j, k;
    for ( i=0; i<=1; i++ ) {
        for ( j=1; j<=3; j++ ) {
            for ( k=1; k<=4; k++ ) {
                if ( i + j + k == 5 )
                printf("红球%d个，黄球%d个，白球%d个。\n", i, j, k);
            }
        }
    }
}