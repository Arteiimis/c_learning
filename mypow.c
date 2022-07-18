#include <stdio.h>
#include <stdlib.h>

double mypow(long double num, int n)
{
    if (num == n && n == 0)
    {
        printf("error.\n");
        exit(1);
    }
    double result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= num;
    }
    return result;
}

void main()
{
    double num = 0;
    int n = 0;
    scanf("%lf %d", &num, &n);
    printf("%lf", mypow(num, n));
}