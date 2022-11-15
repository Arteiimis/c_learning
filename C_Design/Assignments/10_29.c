#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//实现strlen
int My_strlen(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;

    return i;
}

//实现strcpy
char *My_strcpy(char *str1, char *str2)
{
    int i;
    for (i = 0; str2[i] != '\0'; i++)
        str1[i] = str2[i];
    str1[i] = '\0';

    return str1;
}

//KMP字符串匹配
int get_next(char *p, int len, int *next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }

    return 0;
}

int KMP(char *str, char *p)
{
    int i = 0, j = 0;
    int len1 = My_strlen(str);
    int len2 = My_strlen(p);
    int *next = (int *)malloc(sizeof(int) * len2);
    get_next(p, len2, next);

    while (i < len1 && j < len2)
    {
        if (j == -1 || str[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == len2)
        return i - j;
    else
        return -1;
}

int main()
{
    char str[] = "ababbbabaab";
    char pat[] = "abaab";
    int ret = KMP(str, pat);

    printf("%d\n",ret);

    return 0;
}