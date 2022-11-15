#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int strAssign(char *s, char *t)
{
    int i;
    for (i = 0; t[i] != '\0'; i++)
        s[i] = t[i];
    s[i] = '\0';
    return 1;
}

int strLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *SubString(char *str, int start, int end)
{
    assert(start >= 0 && start <= end && end <= strLength(str));
    
    char *subStr = (char *)malloc(sizeof(char) * (end - start + 2));
    int i;
    for (i = start; i <= end; i++)
        subStr[i - start] = str[i];
    subStr[i - start] = '\0';

    return subStr;
}

int index(char *str, char *subStr)
{
    int i = 0, j = 0;
    while (str[i] != '\0' && subStr[j] != '\0')
    {
        if (str[i] == subStr[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (subStr[j] == '\0')
        return i - j;
    else
        return -1;
}


int Repalace(char *s, char *T, char *V)
{
    int i = 0, j = 0;
    int sLen = strLength(s);
    int tLen = strLength(T);
    int vLen = strLength(V);
    int count = 0;
    for (i = 0; i < sLen; i++)
    {
        if (s[i] == T[0])
        {
            for (j = 0; j < tLen; j++)
            {
                if (s[i + j] != T[j])
                    break;
            }
            if (j == tLen)
            {
                count++;
                char *temp = (char *)malloc(sizeof(char) * (sLen - tLen + 1));
                for (j = 0; j < i; j++)
                    temp[j] = s[j];
                for (j = 0; j < vLen; j++)
                    temp[i + j] = V[j];
                for (j = i + tLen; j < sLen; j++)
                    temp[i + vLen + j - tLen] = s[j];
                temp[i + vLen + j - tLen] = '\0';
                s = temp;
                sLen = strLength(s);
            }
        }
    }
    return count;
}

char *concat(char *str1, char *str2)
{
    int i = 0, j = 0;
    int str1Len = strLength(str1);
    int str2Len = strLength(str2);
    char *newStr = (char *)malloc(sizeof(char) * (str1Len + str2Len + 1));
    for (i = 0; i < str1Len; i++)
        newStr[i] = str1[i];
    for (j = 0; j < str2Len; j++)
        newStr[i + j] = str2[j];
    newStr[i + j] = '\0';

    return newStr;
}

int main()
{
    char *s = "I AM A STUDENT";
    char *t = "GOOD";
    char *q = "WORKER";

    printf("The length of string s is %d\n", strLength(s));
    printf("The length of string t is %d\n", strLength(t));
    printf("The Substing of s from 8 to 7 is %s\n", SubString(s, 8, 7));
    printf("The Substing of t from 2 to 1 is %s\n", SubString(s, 2, 1));
    printf("The Index of A in s is %d\n", index(s, "A"));
    printf("The Index of t in s is %d\n", index(s, t));
}