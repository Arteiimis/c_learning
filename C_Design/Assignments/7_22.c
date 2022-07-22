#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//第一题
// int fibo(int n)
// {
//     long long int num1 = 1, num2 = 1, tmp = 0, i = 0;
//     if(n < 3)
//     {
//         return num1;
//     }
//     else
//     {
//         for(i = 0; i <= n - 3; i++)
//         {
//             tmp = num1;
//             num1 = num2;
//             num2 = tmp + num2;
//         }
//         return num2;
//     }
// }

// int main()
// {
//     int n;
//     for(n = 0; n < 50; n++)
//     {
//         printf("%lld\n", fibo(n));
//     }

//     return 0;
// }

//第二题
// int main()
// {
//     int n;
//     printf("请输入一个整数：");
//     scanf("%d", &n);
//     if(n == 0)
//     {
//         printf("该数位数为：1\n");
//     }
//     else if(n > 0)
//     {
//         int i = 0, count = 0;
//         while(n != 0)
//         {
//             n = n / 10;
//             count++;
//         }
//         printf("该数位数为：%d\n", count);
//     }
//     else
//     {
//         n = -n;
//         int i = 0, count = 0;
//         while(n != 0)
//         {
//             n = n / 10;
//             count++;
//         }
//         printf("该数位数为：%d\n", count);
//     }

//     return 0;
// }

//第三题
int main()
{ 
    int sum = 0;
    for(int n = 1; n <= 1000; n++)
    {
        for(int i = 1; i < n; i++)
        {
            if(n % i == 0)
            {
                sum += i;
            }
        }
        if(sum == n)
        {
            printf("%d ", n);
        }
        sum = 0;
    }

    return 0;
}