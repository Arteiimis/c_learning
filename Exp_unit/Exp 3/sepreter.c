#include<stdio.h>

int main(){
    int n, a, b, c;

    printf("请输入一个三位数：\n");
    scanf("%d", &n);
    c = n / 100; n %= 100;
    b = n / 10 ; n %= 10;
    a = n;

    printf("该三位数个位，十位，百位，分别为：%d, %d, %d。", a, b, c);

    return 0;
}