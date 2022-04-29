#include<stdio.h>
void insertion_sort( int *arr, int len );

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int sigh = 0;

    insertion_sort(arr, len);
    for( sigh; sigh < len; sigh++ )
        printf("%d ", arr[sigh]);

    return 0;
}

void insertion_sort( int *arr, int len ) {
    int i, j, key;
    for ( i = 1; i < len; i++ ) {
        key = arr[i];
        j = i - 1;
        while( (j >= 0) && (arr[j] > key) ) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}