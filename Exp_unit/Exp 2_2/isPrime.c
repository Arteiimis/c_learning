#include<stdio.h>
#include<math.h>

int isPrime(int x);

int main(){
  int x;
  
  scanf("%d", &x);
  if ( isPrime(x) ) {printf("YES");}
  else{printf("NO");}
  
  return 0;
}

int isPrime( int x ){
  int sigh = 1;
  int i;
  
  if (x == 1 || (x%2 == 0 && x!=2)){sigh = 0;}
  for (i=3; i<sqrt(x); i+=2){
    if (x%i == 0){
      sigh = 0;
      break;
    }
  }
  
  return sigh;
}