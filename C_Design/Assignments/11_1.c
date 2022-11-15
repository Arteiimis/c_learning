#include <stdio.h>

//二维数组实现杨辉三角
int main()
{
    int a[10][10] = {0}, i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = i; j >= 0; j--)
        {
            if (i == j || j == 0)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
        for (j = i; j >= 0; j--)
        {
            printf("%d   ", a[i][j]);
        }
        printf("\n");
    }
}