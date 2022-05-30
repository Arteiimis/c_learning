#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 50

typedef char String[MAXSIZE + 1];

int main()
{
    
}

void get_next(String T, int *next)
{
    int i = 1, k = 0;
    next[1] == 0;
    while (i < T[0])
    {
        if (k == 0 || T[i] == T[k])
        {
            ++i;
            ++k;
            next[i] = k;
        }
        else
            k = next[k];
    }
}