#include<stdio.h>
void bubble_sort (double *arr, int len);

int main(){
    double arr[] = { 17.8539, 16.4071, 29.3914, 43.0397, 49.5214, 24.2737, 12.7248, 43.2850, 41.4641, 47.8636, 15.8771, 26.1498 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int sigh = 0;
    
    bubble_sort(arr, len);
    for( sigh=0; sigh<len; sigh++ )
        printf("%.4lf ", arr[sigh]);
    
    return 0;
}

void bubble_sort (double *arr, int len) {
    int i, j;     //i：遍历整个数组，j:作为前后比较的标志，temp：作为值的中转站。
    double temp;

    for ( i=0; i < len - 1; i++ ) {
        int flag = 0;       //优化标志，每次循环判断是否交换。
        for ( j=0; j < len - 1 - i; j++ ) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if ( flag == 0 )
            return;
    }
}