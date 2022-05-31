//用递归的方法求n!

#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

void main()
{
    int n, n_out;
    scanf("%d", &n);
    n_out = factorial(n);

    printf("%d\n", n_out);

    return;
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}