#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//第一题
// int main()
// {
//     int n = 1, day = 9;
//     for (day; day > 0; day--)
//     {
//         n += 1;
//         n *= 2;
//     }
//     printf("%d\n", n);

//     return 0;
// }
//

//第二题
int main()
{
    double a, b, c;
    double x1 = 0, x2 = 0;
    printf("请输入方程的三个常数：");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a == 0)
    {
        if(b == 0)
        {
            if(c == 0)
            {
                printf("方程无解\n");
            }
            else
            {
                printf("方程无解\n");
            }
        }
        else
        {
            x1 = -c / b;
            printf("方程有一个解：x = %lf\n", x1);
        }
    }
    else
    {
        double d = pow(b, 2) - 4 * a * c;
        if(d < 0)
        {
            printf("方程无解\n");
        }
        else if(d == 0)
        {
            x1 = -b / (2 * a);
            printf("方程有一个解：x = %lf\n", x1);
        }
        else
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("方程有两个解：x1 = %lf, x2 = %lf\n", x1, x2);
        }
    }
}