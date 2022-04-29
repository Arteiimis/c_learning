#include<stdio.h>
void Merge_Sort( int *arr, int L, int R);
void Merge_Devide( int *arr, int L, int mid, int R);

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int L = 0, R = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序之前的数列：");
    for (int sign = 0; sign < R; sign++) {
        printf("%d ", arr[sign]);
    }
    printf("\n");
    Merge_Sort(arr, L, R);
    
    printf("排序之后的数列：");
    for (int sign = 0; sign < R; sign++) {
        printf("%d ", arr[sign]);
    }
}

void Merge_Sort( int *arr, int L, int R ){
    if ( L == R) {
        return;
    }else{
        int M = (L + R) / 2;
        Merge_Sort(arr, L, M);
        Merge_Sort(arr, M + 1, R);
        Merge_Devide(arr, L, M + 1, R);
    }
}

void Merge_Devide( int *arr, int L, int M, int R ) {
    int LEFT_SIZE = M - L, RIGHT_SIZE = R - M + 1;
    int left[LEFT_SIZE], right[RIGHT_SIZE];
    int i, j, k;

    for ( i = L; i < M; i++ )
        {left[i - L] = arr[i];}
    for ( i = M; i <= R; i++ )
        {right[i - M] = arr[i];}
    i = 0, j = 0, k = L;

    while ( i < LEFT_SIZE && j < RIGHT_SIZE ) {
        if ( left[i] < right[j] ) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while ( i < LEFT_SIZE ) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while ( j < RIGHT_SIZE ) {
        arr[k] = right[j];
        j++;
        k++;
    }
}