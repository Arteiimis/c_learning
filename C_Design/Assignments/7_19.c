#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(a, b) {int t = a; a = b; b = t;}

//第一题
// int main()
// {
//     int a, b, tmp;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);

//     while(1)
//     {
//         tmp = (a > b) ? b : a;
//         while((a % tmp) != 0 || (b % tmp) != 0)
//         {
//             tmp--;
//         }
//         break;
//     }
//     printf("最大公约数为：%d", tmp);
// }

//第二题
// int main()
// {
//     int a, b, tmp;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);

//     while (1)
//     {
//         tmp = (a > b) ? a : b;
//         while ((tmp % a != 0) || (tmp % b != 0))
//         {
//             tmp++;
//         }
//         break;
//     }
//     printf("最大公倍数为：%d", tmp);
// }

//第三题
// int main()
// {
//     int num[3];
//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &num[0], &num[1], &num[2]);

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3 - i - 1; j++)
//         {
//             if (num[j] > num[j + 1])
//             {
//                 SWAP(num[j], num[j + 1]);
//             }
//         }
//     }
//     printf("%d %d %d", num[0], num[1], num[2]);
// }

int main()
{
    int year = 10;
    double p, r = 0.07;
    p = pow(1 + r, year);

    printf("增长倍率为：%lf", p);
    return 0;
}