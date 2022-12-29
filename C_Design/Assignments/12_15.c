#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if(str[0] == '-')
    {
        sign = -1;
        i++;
    }

    for(; str[i] != '\0'; i++)
    {
        result = result * 10 + str[i] - '0';
    }

    return sign * result;
}

void itoa(int n, char *str)
{
    int i = 0, sign;

    if ((sign = n) < 0)
        n = -n;

    while (n != 0)
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    }

    if (sign < 0)
        str[i++] = '-';

    str[i] = '\0';

    reverse(str);
}

int main()
{
    char str[100];
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    itoa(n, str);
    printf("String: %s\t Number: %d\n", str, atoi(str));

    printf("Enter a string: ");
    scanf("%s", str);
    int num = atoi(str);
    printf("String: %s\t Number: %d\n", str, num);
}