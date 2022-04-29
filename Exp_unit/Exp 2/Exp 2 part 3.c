#include <stdio.h>
void main()
{
    int i;
    float x;
    long int m;

    i = 688;
    x = 12345.678;
    m = 1234567890;

    printf("%d,%8d,%08d,%-8d\n", i, i, i, i);
    printf("%f,%12.2f,%4.2f,%-12.2f\n", x, x, x, x);
    printf("%ld,%12ld,%.12d\n", m, m, m);
}