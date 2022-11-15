#include <stdio.h>
#include <stdlib.h>

int isrun(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

int numcounter(int num)
{
    int counter = 0;
    while (num != 0)
    {
        num /= 10;
        counter++;
    }
    return counter;
}

int reversenum(int num)
{
    int revnum = 0;
    while (num != 0)
    {
        revnum = revnum * 10 + num % 10;
        num /= 10;
    }
    return revnum;
}

int main()
{
    int year, number;
    printf("Enter a year: ");
    scanf("%d", &year);
    if (isrun(year))
        printf("%d is a leap year.", year);
    else
        printf("%d is not a leap year.", year);

    printf("enter a number: ");
    scanf("%d", &number);
    printf("the number of digits is %d", numcounter(number));
    printf("the reverse of the number is %d", reversenum(number));
    return 0;
}