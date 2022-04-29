//编写程序输出半径为1—15的圆的面积，若面积在30—100之间的则输出，否则不输出。
#include<stdio.h>

int main() {
    int r;
    double round;

    for ( r = 1; r <= 15; r++ ){
        round = 3.14*r*r;
        if ( round >= 30 && round <= 100 ){
            printf("%lf ", round);
        }
        round = 1;
    }
    return 0;
}