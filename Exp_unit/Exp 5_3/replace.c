//输入一个字符串，将其中的数字字符替换'*'字符。//
#include<stdio.h>
#include<string.h>
#define SIZE 20

int main() {
    char str[SIZE] = {"\0"};
    gets(str);
    
    for( int i = 0; i < strlen(str); i++ ) {
        if( str[i] >= '0' && str[i] <= '9' )
            str[i] = '*';
    }
    printf("%s\n", str);

    return 0;
}