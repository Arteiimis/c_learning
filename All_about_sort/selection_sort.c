#include<stdio.h>
void swap( int *a, int *b);
void selection_sort(int *arr, int len);

int main(){
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int sign;
    
    selection_sort(arr, len);
    for ( sign = 0; sign < len; sign++ ){
        printf("%d ", arr[sign]);
    }
}

inline void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int len){
    int i, j;
    for( i=0; i < len - 1; i++ ){
        int min = i;
        for ( j = i + 1; j < len; j++ )
            if (arr[j] < arr[min]) min = j;
            swap(&arr[min], &arr[i]);
        
    }
}