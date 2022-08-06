#include <stdlib.h>
#include <stdio.h>

int SearchBin(int arr[10], int len, int key)
{
    int low = 0;
    int high = len;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; //查找失败
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 15; i++)
        {
            int index = SearchBin(arr, 10, i);
            printf("%d  ", index); //查看下标是否正确
        }
    return 0;
}