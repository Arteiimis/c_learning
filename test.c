#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right)
{
    int i = left, j = mid, index = 0;
    int *temp = (int *)malloc((right - left) * sizeof(int));

    while (i < mid && j < right)
    {
        temp[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i < mid)
    {
        temp[index++] = arr[i++];
    }
    while (j < right)
    {
        temp[index++] = arr[j++];
    }
    for (int i = 0; i < index; i++)
    {
        arr[left + i] = temp[i];
    }
    free(temp);
}

void mergeSort(int *arr, int left, int right)
{
    if (right - left <= 1)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    //
    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}