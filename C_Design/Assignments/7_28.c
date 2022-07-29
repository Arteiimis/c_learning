#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//第一题
bool isPalidrome(int x)
{
    int temp = x;
    int reverse = 0;
    while (temp != 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return reverse == x;
}

//第二题
void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//第三题
int height(double hight, int count)
{
    double sum = 0;
    for (int i = 1; i <= count; i++)
    {
        sum += hight;
        hight /= 2;
        sum += hight;
    }
    printf("%lf, %lf\n", hight, sum);

    return 0;
}

//第四题
bool isComnum(int n)
{
    int i, j, k;
    k = n % 10;
    n /= 10;
    j = n % 10;
    n /= 10;
    i = n % 10;
    n /= 10;
    return i * i * i + j * j * j + k * k * k == n;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (isComnum(n))
            printf("%d\n", n);
    }

    return 0;
}