#include<stdio.h>
#define MAX_SIZE 10000

void swap( int *a, int *b );
int listlen( int *arr );
void Qsort(int *arr, int low, int high);
void Quick_Sort(int *arr);
int Partition(int *arr, int low, int high);

int listlen( int *arr ){
    int len = 0;
    while ( *arr++ )
        len++;
    return len;
}

void Quick_Sort(int *arr) {
    Qsort(arr, 0, listlen(arr) - 1);
}

void Qsort(int *arr, int low, int high) {
    int pivot;
    if(low < high){
        pivot = Partition(arr, low, high);
        Qsort(arr, low, pivot - 1);
        Qsort(arr, pivot + 1, high);
    }
}

int Partition(int *arr, int low, int high) {
    int pivotkey;

    //三数取中，避免无意义交换
    int mid = low + (high - low) / 2;
    if(arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if(arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);
    if(arr[mid] > arr[low])
        swap(&arr[mid], &arr[low]);

    pivotkey = arr[low];
    while(low < high){
        while(low < high && arr[high] >= pivotkey)
            high--;
        swap(&arr[low], &arr[high]);
        while(low < high && arr[low] <= pivotkey)
            low++;
        swap(&arr[low], &arr[high]);
        
    }
    return low;
}

void swap( int *a, int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}