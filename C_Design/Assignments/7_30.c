#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
//     int coin15, coin21, coin29, coin41, coin67;
//     for (coin15 = 0; coin15 <= 1608 / 15; coin15++)
//     {
//         if (coin15 * 15 > 1608)
//             continue;
//         for (coin21 = 0; coin21 <= 1608 / 21; coin21++)
//         {
//             if (coin15 * 15 + coin21 * 21 > 1608)
//                 continue;
//             for (coin29 = 0; coin29 <= 1608 / 29; coin29++)
//             {
//                 if (coin15 * 15 + coin21 * 21 + coin29 * 29 > 1608)
//                     continue;
//                 for (coin41 = 0; coin41 <= 1608 / 41; coin41++)
//                 {
//                     if (coin15 * 15 + coin21 * 21 + coin29 * 29 + coin41 * 41 > 1608)
//                         continue;
//                     for (coin67 = 0; coin67 <= 1608 / 67; coin67++)
//                     {
//                         if (coin15 * 15 + coin21 * 21 + coin29 * 29 + coin41 * 41 + coin67 * 67 > 1608)
//                             continue;
//                         else if (coin15 * 15 + coin21 * 21 + coin29 * 29 + coin41 * 41 + coin67 * 67 == 1608)
//                         {
//                             printf("%d %d %d %d %d %d\n", coin15, coin21, coin29, coin41, coin67, coin67);
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

/**
 * @brief 二分查找简单实现
 * 
 * @param arr 传入数组指针
 * @param len 数组长度
 * @param target 目标值
 * @return int 返回查找到的下标
 */
int Binsearch(int *arr, int len, int target)
{
    int left = 0, right = len - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {41, 29, 19, 5, 7, 48, 8, 33, 47, 21};
    int target = 19;
    int low = 0, high = 9;
    while (low <= high)
    {
        if (arr[low] == target || arr[high] == target)
        {
            if (arr[low] == target)
            {
                printf("target is %d, index is %d\n", target, low);
                return 0;
            }
            if (arr[high] == target)
            {
                printf("target is %d, index is %d\n", target, high);
                return 0;
            }
        }
        else
        {
            low++;
            high--;
        }
    }
    printf("%d did not find\n", target);

    return 0;
}