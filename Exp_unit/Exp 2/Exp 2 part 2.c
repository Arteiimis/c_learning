#include <stdio.h>
void main()
{
    int a;
    float b;
    char c;
    double d;

    printf("请输入数据：\n");
    scanf("%d", &a);
    scanf("%f", &b);
    scanf("%lf", &d);
    scanf("%c", &c);
    printf("\n");
    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %c\n", c);
    printf("d = %f\n", d);
}