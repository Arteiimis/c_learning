#include<stdio.h>

int main(){
    float a, b, temp;

    printf("请输入两个浮点数,以空格切割：\n");
    scanf("%f %f", &a, &b);
    printf("交换前, a=%f, b=%f。\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf("交换并保留三位小数后, a=%.3f, b=%.3f。\n", a, b);
}