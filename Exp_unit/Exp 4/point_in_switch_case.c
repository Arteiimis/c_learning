#include <stdio.h>

void main(){
    int point, expoint;
    
    scanf("%d", &point);

    expoint = point / 10;
    switch (expoint){
        case 9:
        case 8:printf("A");
            break;
        case 7:printf("B");
            break;
        case 6:printf("C");
            break;
        default:printf("D");
    }
}