#include<stdio.h>
#include<math.h>

int isPrime( int x );

int main() {
    int count = 0;
    int num[10];
    for(int i = 1; i <= 10; i++) 
        scanf("%d", &num[i - 1]);

    for(int i = 1; i <= 10; i++) 
    {
        if(isPrime(num[i - 1])) 
            count++;
    }
    printf("质数的个数为：");
    printf("%d\n", count);
}

int isPrime( int x )
{
    int sigh = 1;
    int i;
    
    if (x == 1 || (x%2 == 0 && x!=2)){sigh = 0;}
    for (i=3; i<sqrt(x); i+=2)
    {
        if (x%i == 0){
        sigh = 0;
        break;
        }
    }
    return sigh;
}