//从键盘输入3个字符串，按由小到大排序（使用strcmp函数）。//
#include<stdio.h>
#include<string.h>

int main() {
	char str1[20],str2[20],str3[20],temp[20];

	printf("请输入3个字符：\n");
    gets(str1); gets(str2); gets(str3);

	if(strcmp( str1, str2 )>0) {
		strcpy(temp,str1); 
		strcpy(str1,str2); 
		strcpy(str2,temp);
	} 
	if(strcmp( str2, str3 )>0) {
		strcpy(temp,str1); 
		strcpy(str1,str2); 
		strcpy(str2,temp);
	} 
	if(strcmp( str1, str3 )>0) {
		strcpy(temp,str1); 
		strcpy(str1,str3); 
		strcpy(str3,temp);
	} 
	
    printf("排序后：\n");
	puts(str1); puts(str2); puts(str3);
	return 0;
}