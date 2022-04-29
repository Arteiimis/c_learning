#include<stdio.h>
void bubble_sort (int *arr, int len);
void swap( int *a, int *b );

int main(){
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int sigh = 0;
    
    bubble_sort(arr, len);
    for( sigh=0; sigh<len; sigh++ )
        printf("%d ", arr[sigh]);
    
    return 0;
}

void bubble_sort (int *arr, int len) {
    int i, j;    //i：遍历整个数组，j:作为前后比较的标志。
    
    for ( i=0; i < len - 1; i++ ) {
        int flag = 0;       //优化标志，每次循环判断是否交换。
        for ( j=0; j < len - 1 - i; j++ ) {
            if (arr[j] > arr[j + 1]) {
                swap (&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if ( flag == 0 )
            return;
    }
}

void swap( int *a, int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}