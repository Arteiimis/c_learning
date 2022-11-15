#include <stdio.h>

//斐波那契数列第n项值
int main()
{
    int n, i, a = 1, b = 1, c;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n == 1 || n == 2)
        printf("the %dth number is 1", n);
    else
    {
        for (i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        printf("the %dth number is %d", n, c);
    }
    return 0;
}

//查找字符数组某个字符出现次数
int time()
{
    char str[100];
    char ch;
    int i, count = 0;
    printf("Enter a string: ");
    gets(str);
    printf("Enter a character: ");
    scanf("%c", &ch);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            count++;
    }
    printf("the character %c appears %d times", ch, count);
    return 0;
}