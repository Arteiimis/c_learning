#include <stdio.h>

// void  fun( int  x )
// {		x = x * x * x ;  }
// void  main( )
// {
// 		int  n = 3 ;
// 		fun ( n ) ;
// 		printf ( "%d" , n );
// }

// int fun(int n)
// {
//     int k;
//     for (k = 2; k <= n / 2; k++)
//         if (n % k == 0)
//             return 0;
//     return 1;
// }
// void main()
// {
//     int a = 20, b = 50, i, s = 0;
//     for (i = a; i <= b; i++)
//         if (fun(i) == 1)
//             s++;
//     printf("%d\n", s);
// }

long fun(long n)
{
    long t, s = 0;
    while (n)
    {
        t = n % 10;
        s = s * 10 + t;
        n = n / 10;
    }
    return s;
}
void main()
{
    long int a = 2345, b;
    b = fun(a);
    printf("%ld", b);
}
