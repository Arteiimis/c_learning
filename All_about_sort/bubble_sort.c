#include<stdio.h>
#define MAX_SIZE 100

void bubble_sort (int *arr);
void swap( int *a, int *b );
int listlen(int *arr);

// int main(){
//     int arr[MAX_SIZE] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
//     int sigh = 0;
    
//     bubble_sort(arr);
//     printf("%d\n", listlen(arr));
//     for( sigh=0; sigh<listlen(arr); sigh++ )
//         printf("%d ", arr[sigh]);
    
//     return 0;
// }

void bubble_sort (int *arr) {
    int i, j;    //i：遍历整个数组，j:作为前后比较的标志。
    int len = listlen(arr);
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

inline void swap( int *a, int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int listlen(int *arr) {
    int len = 0;
    while (arr[len] != 0)
        len++;
    return len;
}