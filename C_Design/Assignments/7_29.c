#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

double average(int *arr, int len)
{
    int i, sum = 0;
    double avg;
    for (i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    avg = sum * 1.0 / len;

    return avg;
}

//第一题:
// int main()
// {
//     int arr[10] = {41, 29, 19, 5, 7, 48, 8, 33, 47, 21};
//     sort(arr, 10);
//     printf("十个数字平均值为: %lf\n", average(arr, 10));
//     printf("十个数字最大值为: %d\n", arr[9]);
//     printf("十个数字最小值为: %d\n", arr[0]);

//     return 0;
// }

//第二题:
int main()
{
    char teamA[3] = {'A', 'B', 'C'};
    char teamB[3] = {'X', 'Y', 'Z'};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(teamA[i] == 'A')
            {
                if(teamB[j] != 'X')
                {
                    printf("%c vs %c\n", teamA[i], teamB[j]);
                }
            }
            else if(teamA[i] == 'C')
            {
                if(teamB[j] != 'X' && teamB[j] != 'Z')
                {
                    printf("%c vs %c\n", teamA[i], teamB[j]);
                }
            }
            else
            {
                printf("%c vs %c\n", teamA[i], teamB[j]);
            }
        }
    }
}