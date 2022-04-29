//编程求解sn=a+aa+aaa+aaaa+a…..a其中a是1—9中的一个数，n是正整数，a和n都键盘输入。（例如a是8，n是4，sn=8+88+888+8888）//
#include<stdio.h>
#include<math.h>

int main() {
    int a, a_tmp, n, sum, i;

    scanf("%d %d", &a, &n);
    a_tmp = a;
    sum = a;
    
    for ( i=1; i<n; i++ ) {
        a_tmp += a*pow(10, i);
        sum += a_tmp;
    }
    printf("%d\n", sum);

    return 0;
}