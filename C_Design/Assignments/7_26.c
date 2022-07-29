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
// int main()
// {
//     double hight = 100, sum = 0;
//     int count = 10;
//     for (int i = 1; i <= count; i++)
//     {
//         sum += hight;
//         hight /= 2;
//         sum += hight;
//     }
//     printf("%lf, %lf\n", hight, sum);

//     return 0;
// }

//第四题
int main()
{
    int i, j, k, sum;
    for (i = 1; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (k = 0; k <= 9; k++)
            {
                sum = i * 100 + j * 10 + k;
                if (sum == i * i * i + j * j * j + k * k * k)
                    printf("%d\n", sum);
            }
        }
    }
}