#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool IsPrimer(int n)
{
    if (n == 1 || (n % 2 == 0 && n != 2))
    {
        return false;
    }
    for (int i = 3; i <= sqrt(n) + 1; i += 2)
    {
        if (n % i == 0)
            return false;
        else
            return true;
    }
    return true;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        if (IsPrimer(i))
            printf("%d 是素数\t", i);
    }
    return 0;
}