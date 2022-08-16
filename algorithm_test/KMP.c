#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

/**
 * @brief 获取next数组
 * 
 * @param p 字符串指针
 * @param len 字符串长度
 * @param next next数组指针
 * @return int 
 */
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

int get_nextval(char *p, int len, int *next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len - 1)
    {
        if (j == -1 or p[i] == p[j])
        {
            ++i;
            ++j;
            if (p[i] != p[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
    printf("next: ");
    for (i = 0; i < len; ++i)
        printf("%d ", next[i]);
    printf("\n");

    return 0;
}

/**
 * @brief KMP算法主体
 * 
 * @param t txt主串
 * @param p pat模式串
 * @return int 
 */
int kmp(char *t, char *p)
{
    int i = 0, j = 0;
    int tlen = strlen(t);
    int plen = strlen(p);
    int *next = (int *)malloc(sizeof(int) * plen);
    get_nextval(p, plen, next);

    while (i < tlen and j < plen)
    {
        if (t[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
            if (j == -1)
            {
                j = 0;
                ++i;
            }
        }
    }

    return i >= plen ? i - plen : -1;
}

int main()
{
    char s[] = "ababbbabaab";
    char p[] = "abaab";
    int ret = kmp(s, p);
    printf("%d\n", ret);

    return 0;
}