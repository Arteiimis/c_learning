#include<stdio.h>
#include<math.h>

void  main ( )
{
int n = 20 , f = 0 , a;
while ( f == 0){
    a = 2 ; f = 1 ;
    while ( f == 1 && a <= sqrt(n) ){	
        if ( n % a == 0 ) f = 0 ;
        else a = a + 1 ;
    }
    if ( f == 0 ) n = n + 1 ;
}
printf ( "%d" , n ) ;
}
