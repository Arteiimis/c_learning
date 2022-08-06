#include <stdio.h>
#include <stdlib.h>

void Mystrcat(char *des, char *src)
{
    while (*des != '\0')
        des++;
    while (*src != '\0')
        *des++ = *src++;
    *des = '\0';
}

int Mystrcmp(char *str1, char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str2 - *str1;
}

int Myatoi(const char *str)
{
    int num = 0;
    int flag = 1;
    if (*str == '-')
    {
        flag = -1;
        str++;
    }
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
            num = num * 10 + *str - '0';
        else
            return 0;
        str++;
    }
    return num * flag;
}

void StrReverse(char *str)
{
    char *end = str;
    while (*end != '\0')
        end++;
    end--;
    while (str < end)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main()
{
    // char des[100] = "Hello";
    // char src[100] = "World";
    // Mystrcat(des, src);
    // printf("%s\n", des);

    // char str1[100] = "Hello";
    // char str2[100] = "friend";
    // int result = Mystrcmp(str1, str2);
    // printf("%d\n", result);

    // char str[100] = "12345";
    // int num = Myatoi(str);
    // printf("%d\n", num);

    char str[100] = "12345";
    StrReverse(str);
    printf("%s\n", str);

    return 0;
}