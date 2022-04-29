#include<stdio.h>

void main() {
    int i, t1 = 1, t2 = 1, nextTerm;

    printf("%d\t%d\t", t1, t2);
    for( i = 3; i <= 20; i++ ) {
        nextTerm = t1 + t2;
        printf("%d\t", nextTerm);
        
        if( i % 5 == 0 )
            printf("\n");
            t1 = t2;
            t2 = nextTerm;
    }
}
