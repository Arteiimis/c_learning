#include <stdio.h>
#include "bucket_sort.c"
#include "quick_sort.c"

#define MAX_SIZE 20

int main() {
    int arr[MAX_SIZE] = {72, 67, 89, 24, 41, 25, 88, 42, 38, 39, 63, 76, 86, 80, 85, 71, 95, 83, 19, 55};
    Quick_Sort(arr, MAX_SIZE);
    printf("排序后数组为：\n");
    for (int sign = 0; sign < MAX_SIZE; sign++) {
        printf("%d ", arr[sign]);
    }
}