#include<stdio.h>

int main(){
    float c,f;
    
    printf("请输入华氏度：\n");
    scanf("%f", &f);
    
    c = 5.0/9.0 * (f - 32);

    printf("%f华氏度为%f摄氏度", f, c);

    return 0;
}