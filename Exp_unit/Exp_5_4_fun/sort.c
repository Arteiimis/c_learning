#include <stdio.h>
#include <stdlib.h>

void bubble_sort(double *arr);
void selection_sort(double *arr);
void swap(double *a, double *b);

void main()
{
    double arr_for_bubble[12] = {18.162, 14.768, 33.753, 15.505, 20.760, 42.689, 14.613, 27.689, 41.093, 18.226, 47.030, 45.833};
    double arr_for_selection[12] = {24.065, 14.714, 22.152, 15.514, 27.514, 44.246, 12.275, 14.546, 40.377, 29.989, 27.609, 36.268};

    printf("冒泡排序前数组：\n");
    for (int i = 0; i < 12; i++)
        printf("%.3f  ", arr_for_bubble[i]);
    printf("\n冒泡排序后的数组：\n");
    bubble_sort(arr_for_bubble);
    for (int i = 0; i < 12; i++)
        printf("%.3f  ", arr_for_bubble[i]);

    printf("\n\n选择排序前数组：\n");
    for (int i = 0; i < 12; i++)
        printf("%.3f  ", arr_for_selection[i]);
    printf("\n选择排序后的数组：\n");
    selection_sort(arr_for_selection);
    for (int i = 0; i < 12; i++)
        printf("%.3f  ", arr_for_selection[i]);

    return;
}

void bubble_sort(double *arr)
{
    int i, j;
    int len = 12;
    for (i = 0; i < len - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

void selection_sort(double *arr)
{
    int i, j, len = 12;
    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}

inline void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}