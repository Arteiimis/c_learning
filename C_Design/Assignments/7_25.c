#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//第一题
// int main()
// {
//     double a, b, c;
//     double x1 = 0, x2 = 0;
//     printf("请输入方程的三个常数：");
//     scanf("%lf %lf %lf", &a, &b, &c);
//     if (a == 0 && b == 0)
//     {
//         if (c == 0)
//         {
//             printf("方程无解\n");
//         }
//         else
//         {
//             printf("方程无解\n");
//         }
//     }
//     else if (a == 0)
//     {
//         x1 = -c / b;
//         printf("方程有一个解：x = %lf\n", x1);
//     }
//     else
//     {
//         double d = pow(b, 2) - 4 * a * c;
//         if (d < 0)
//         {
//             printf("方程无解\n");
//         }
//         else if (d == 0)
//         {
//             x1 = -b / (2 * a);
//             printf("方程有一个解：x = %lf\n", x1);
//         }
//         else
//         {
//             x1 = (-b + sqrt(d)) / (2 * a);
//             x2 = (-b - sqrt(d)) / (2 * a);
//             printf("方程有两个解：x1 = %lf, x2 = %lf\n", x1, x2);
//         }
//     }

//     return 0;
// }

//第二题
// int main()
// {
//     int n, a, sum = 0;
//     printf("请输入a的值与n的值：");
//     scanf("%d %d", &a, &n);
//     int temp = a;

//     for (int i = 1; i <= n; i++)
//     {
//         sum += a;
//         a *= 10;
//         a += temp;
//     }

//     printf("%d\n", sum);

//     return 0;
// }

//第三题
long long int factorial(int n)
{
    long long int result = 1;
    
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    int n;
    long long int sum = 0;
    printf("请输入n的值：");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }

    printf("%lld\n", sum);
}