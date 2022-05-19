//编写程序计算s=1+22+32+…+n2+…，直到s>10000为止
#include<stdio.h>
#include<math.h>

int main() {
    int n = 2, s = 0;
    
    for(int i = 1; s <= 10000; i++) {
        s += pow(i, n);
    }
    printf("%d\n", s);

    return 0;
}