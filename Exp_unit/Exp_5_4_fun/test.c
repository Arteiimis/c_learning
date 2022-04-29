#include<stdio.h>
void  fun( int  x );

void  main( ){
    int  n = 3 ;
    
    fun ( n ) ;
    printf ( "%d" , n );
}

void  fun( int  x ){		
    x = x * x * x ;  
}
