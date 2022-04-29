//输入一行字符，统计其中有多少个单词，单词之间用空格分隔开。//
//"Let life be beautiful like summer flowers And Death like autumn leaves."//
#include<stdio.h>
#include<string.h>
#define SIZE 100

int main() {
    char str[SIZE] = {"\0"}; 
    gets(str);
    int count = 0, len = strlen(str);
    
    for( int i = 0; i < len; i++ ) {
        if( str[i] == ' ' )
            count++;
    }
    printf("%d\n", count + 1);
}

