#include <stdlib.h>
#include <stdio.h>

int main()
{
    char arr[] = "abcdefghijk";
    char brr[20];
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int lenbrr = sizeof(brr) / sizeof(brr[0]);

    for (int i = 0; i < lenarr; i++)
    {
        brr[i] = arr[i];
    }
    for (int i = 0; i < lenbrr; i++)
    {
        printf("%c", brr[i]);
    }


    return 0;
}