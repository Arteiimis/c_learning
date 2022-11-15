#include <stdio.h>
#include <stdlib.h>

// 作业1
// int main()
// {
//     int a, n, s = 0, temp;
//     scanf("%d %d", &a, &n);
//     temp = a;
//     for (int i = 1; i <= n; i++)
//     {
//         s += a;
//         a = a * 10 + temp;
//     }
//     printf("%d", s);

//     return 0;
// }

int main()
{
    int num, i, j, k;
    for (num = 100; num < 1000; num++)
    {
        i = num / 100;
        j = num / 10 % 10;
        k = num % 10;
        if (num == i * i * i + j * j * j + k * k * k)
        {
            printf("%d ", num);
        }
    }
}