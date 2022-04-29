//从键盘输入一个字符串，输出这个字符串的长度（不能使用strlen）。//
#include<stdio.h>
int count_str(char *str);

int main() {
    char str[] = "";
    scanf("%s", str);

    printf("%d\n", count_str(str));
}

int count_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}