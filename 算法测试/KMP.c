#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 50

typedef char String[MAXSIZE + 1];
void get_next(String T, int *next);
void StrAssign(String T, char *chars);
int StrLength(String S);
int KMP(String S, String T, int pos);

int main()
{
    int i;
    String ch, p;
    int *next = (int *)malloc((i + 1) * sizeof(int));

    StrAssign(ch, "shdjeubajsasad");
    StrAssign(p, "sasad");
    i = StrLength(p);
    get_next(p, next);

    printf("next数组为：\n");
    for (int i = 1; i <= StrLength(p); i++)
        printf("%d", next[i]);

    printf("\n主串和子串在第%d个字符处首次匹配", KMP(ch, p, 1));

    return 0;
}

void StrAssign(String T, char *chars)
{
    T[0] = strlen(chars);
    for (int i = 1; i <= T[0]; i++)
        T[i] = *(chars + i - 1);
}

int KMP(String S, String T, int pos)
{
    int i = pos, j = 1, next[255];
    get_next(T, next);
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

void get_next(String T, int *next)
{
    int i = 1, k = 0;
    next[1] = 0;
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

int StrLength(String S)
{
    return S[0];
}