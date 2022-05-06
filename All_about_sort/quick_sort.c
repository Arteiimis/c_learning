#include<stdio.h>
int listlen( int *arr );
void Quick_Sort( int *arr );
void Quick_Sort_Recursive( int *arr, int START, int END );
void swap( int *a, int *b );

// int main() {
//     int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
//     int len = sizeof(arr) / sizeof(arr[0]);
//     Quick_Sort(arr, len - 1);
//     for (int sign = 0; sign < len; sign++) {
//         printf("%d ", arr[sign]);
//     }
// }\

void Quick_Sort( int *arr ){
    int len = listlen(arr);
    Quick_Sort_Recursive( arr, 0, len - 1 );
}

void Quick_Sort_Recursive( int *arr, int START, int END ){
    if ( START >= END )
        return;
    
    int MID = arr[END];
    int left = START, right = END - 1;

    while ( left < right ) {
        while ( arr[left] < MID && left < right )
            left++;
        while ( arr[right] > MID && left < right )
            right--;
        if ( left < right )
            swap( &arr[left], &arr[right] );
    }
    if ( arr[left] > MID )
        swap( &arr[left], &arr[END] );
    else
        left++;
    
    Quick_Sort_Recursive( arr, START, left - 1 );
    Quick_Sort_Recursive( arr, left + 1, END );
}

void swap( int *a, int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int listlen( int *arr ){
    int len = 0;
    while ( *arr++ )
        len++;
    return len;
}
