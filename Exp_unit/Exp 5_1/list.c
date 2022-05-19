//输出序列1，2，5，14，41，…的前20项（即从第2项开始，每一项为其前1项的值乘3后减1），要求分4行输出，每行5个。
#include<stdio.h>

int main() {
    int num[20];
    num[0] = 1;
    for(int i = 1; i <= 20; i++) {
        num[i] = num[i - 1] * 3 - 1;
    }
    for(int i = 1; i <= 20; i++) {
        printf("%-10d", num[i - 1]);
        if(i % 5 == 0)
            printf("\n");
    }
}