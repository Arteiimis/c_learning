#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1 = 1, num2 = 1, tmp = 0, i = 0, n;
    scanf("%d", &n);
    if(n < 3)
    {
        printf("%d\n", num1);
    }
    else
    {
        for(i = 0; i <= n - 3; i++)
        {
            tmp = num1;
            num1 = num2;
            num2 = tmp + num2;
        }
        printf("%d\n", num2);
    }
}