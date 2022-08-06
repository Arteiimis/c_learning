#include <stdio.h>
#include <stdlib.h>

int NumberCutter(int num)
{
    if (num > 9)
    {
        NumberCutter(num / 10);
    }
    printf("%d", num % 10);
}

int GYS(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return GYS(b, a % b);
    }
}

/**
 * @brief 递归实现二分查找
 *
 * @param arr 有序数组指针
 * @param start 查找起始值, 每次进入递归时更新
 * @param end 查找结束值, 每次进入递归时更新
 * @param key 查找目标值
 * @return int 返回查找结果, -1表示查找失败
 */
int Binserch_recursion(int *arr, int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return Binserch_recursion(arr, start, mid - 1, key);
    }
    else
    {
        return Binserch_recursion(arr, mid + 1, end, key);
    }
}

int main()
{
    // NumberCutter(12345);
    // printf("%d", GYS(12, 3));

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d", Binserch_recursion(arr, 0, 9, 5));

    return 0;
}
