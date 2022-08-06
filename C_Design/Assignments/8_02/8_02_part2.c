#include <stdlib.h>
#include <stdio.h>

void BubbleSort(int arr[10], int len)
{
    int tmp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i -1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void Show(int arr[10], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {4, 7, 9, 0, 2, 4, 78, 12, 5, 77};
    Show(arr, 10);
    BubbleSort(arr, 10);
    Show(arr, 10);
    return 0;
}