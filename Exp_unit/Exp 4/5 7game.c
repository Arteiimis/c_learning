#include <stdio.h>
main(){
    int n;
    float temp1, temp2;

    scanf("%d", &n);

    temp1 = n % 5;
    temp2 = n % 7;
    
    if (temp1 == 0 && temp2 == 0){
        printf("yes");
    }else{
        printf("no");
    }
    
    return 0l;
}