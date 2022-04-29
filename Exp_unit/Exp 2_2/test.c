/*输入一个字符，如果是大写字母改变为小写字母；如果是小写字母，则把它变为大写字母；若是其它字符则不变。*/
#include <stdio.h>
int main(){
    char c;
    
    scanf("%c", &c);
    if (c >= 'A' && c <= 'Z'){
        c += 32;
    }else if (c >= 'a' && c <= 'z'){
        c -= 32;
    }
    
    printf("%c", c);
    
    return 0;
}