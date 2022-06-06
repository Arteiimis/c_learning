#include <stdio.h>
void Shell_Sort(int *arr, int len);
void swap(int *a, int *b);

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(arr[0]);

    Shell_Sort(arr, len);
    for (int sign = 0; sign < len; sign++)
    {
        printf("%d ", arr[sign]);
    }
}

void Shell_Sort(int *arr, int len)
{
    int i, j, gap;
    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < len; i++)
        {
            for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
            {
                swap(&arr[j], &arr[j + gap]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}