#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int c;
    FILE *fp;
    int len = 1;
    fp = fopen("account.txt", "r");
    if(fp)
    {
        while((c = fgetc(fp)) != EOF)
        {
            if(c == '\n')
                len++;
        }
        printf("%d\n", len);
        fclose(fp);
    }
    char Number[20] = {0};
    len += 10000;
    itoa(len, Number, 10);
    printf("%s", Number);

    return 0;
}