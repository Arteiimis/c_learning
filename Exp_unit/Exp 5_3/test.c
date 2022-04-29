#include<stdio.h>

void  main( )
{ 	int k,j;  char  s[40]= "x3=y1-z2", t[40];
	for( j=0,k=0 ; s[k]!= '\0' ; k++ )
	    if(s[k]>= '0' && s[k]<= '9') {  t[j]=s[k];  j++;   }
	t[j]= '\0';
	printf( "%s", t );
}