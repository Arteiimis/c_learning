//写两个函数，分别求两个正整数的最大公约数和最小公倍数，用主函数调用这两个函数并输出结果，两个整数由键盘输入。

#include <stdio.h>
#include <stdlib.h>

int Max_Common_Divisor(int a, int b);
int Min_Common_Multiple(int a, int b);

void main()
{
    int a, b;
    int a_max, b_min;
    scanf("%d %d", &a, &b);
    a_max = Max_Common_Divisor(a, b);
    b_min = Min_Common_Multiple(a, b);

    printf("最大公约数为：%d, 最小公倍数为：%d\n", a_max, b_min);

    return;
}

int Max_Common_Divisor(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int Min_Common_Multiple(int a, int b)
{
    return a * b / Max_Common_Divisor(a, b);
}