#include<stdio.h>
int main()
{
    int num;
    int g, s, b;

    scanf("%d", &num);

    b=num / 100;
    g=num % 10;
    s=num / 10 % 10;

    printf("%d", g*100 + s*10 + b);

    return 0;
}