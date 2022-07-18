#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//第一题
// int main()
// {
//     for(int i = 2000; i <= 2400; i++){
//         if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
//             printf("%d  ", i);
//         }
//     }
// }

//第二题
// int main()
// {
//     int n = 0, sum = 1;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//     {
//         sum *= i;
//     }
//     printf("%d! = %d", n, sum);
// }

//第三题
int main()
{
    int sigh = 1;
    int i, x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x == 1 || (x % 2 == 0 && x != 2))
    {
        sigh = 0;
    }
    for (i = 3; i <= sqrt(x); i += 2)
    {
        if (x % i == 0)
        {
            sigh = 0;
            break;
        }
    }

    if (sigh == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}