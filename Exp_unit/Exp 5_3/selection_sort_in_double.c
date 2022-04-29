#include<stdio.h>
void swap( double *a, double *b);
void selection_sort(double *arr, int len);

int main(){
    double arr[] = { 33.6216, 12.5363, 39.6193, 45.4526, 15.4249, 39.0851 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int sign;
    
    selection_sort(arr, len);
    for ( sign = 0; sign < len; sign++ ){
        printf("%.4lf ", arr[sign]);
    }
}

void swap( double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(double *arr, int len){
    int i, j;
    for( i=0; i < len - 1; i++ ){
        int min = i;
        for ( j = i + 1; j < len; j++ )
            if (arr[j] < arr[min]) min = j;
            swap(&arr[min], &arr[i]);
        
    }
}