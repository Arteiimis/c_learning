#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp1 = fopen("12_15.c", "r");
    FILE *fp2 = fopen("new.cpp", "w");
    char buffer[256] = {0};
    size_t size = fread(buffer, sizeof(char), 256, fp1);

    while (size > 0)
    {/.,/.,/.,/.,/.,/.,/.,/.,/.,
        fwrite(buffer, sizeof(char), size, fp2);
        memset(buffer, 0, 256);
        size = fread(buffer, sizeof(char), 256, fp1);
    }

    return 0;
}