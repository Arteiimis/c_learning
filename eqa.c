#include<stdio.h>
#include<math.h>

int main() {
    int a, b, c;
    double X1, X2, p, q;
    
    scanf("%d %d %d", &a, &b, &c);
    if ( a == 0 )
        printf("非二次方程");
    else if ( pow(b, 2) - 4*a*c == 0) {
        X1 = -b / 2*a;
        printf( "X1 = X2 = %lf", X1);
    } 
    else if ( pow(b, 2) - 4*a*c > 0 ) {
        X1 = (-b + sqrt(pow(b, 2) - 4*a*c)) / 2*a;
        X2 = (-b - sqrt(pow(b, 2) - 4*a*c)) / 2*a;
        printf("X1 = %lf, X2 = %lf", X1, X2);
    } else {
        p = -b / 2 * a;
        q = sqrt( -(pow(b, 2) - 4*a*c) ) / 2*a;
        printf("X1 = %lf + %lfi, X2 = %lf - %lfi", p, q, p, q);
    }
}