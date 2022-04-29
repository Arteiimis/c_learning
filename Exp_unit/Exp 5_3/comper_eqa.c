//从键盘输入3个字符串，按由小到大排序（使用strcmp函数）。//
#include<stdio.h>
#include<string.h>
void sort(char *x[], int n);

int main() {
	char *s[3], st[3][100];
	
	printf("请输入3个字符：\n");
	for(int i = 0; i < 3; i++) {
		s[i] = st[i];
		gets(s[i]);
	}
	
	sort(s, 3);
	printf("排序后：\n");
	for(int i = 0; i < 3; i++) {
		puts(s[i]);
	}
}

void sort(char *x[], int n) {
	int i, j;
	char *t;
	
	for( i = 0; i < n; i++ ) {
		for( j = i + 1; j < n; j++ ) {
			if( strcmp(x[i], x[j]) > 0 ) {
				t = x[i];
				x[i] = x[j];
				x[j] = t;
			}
		}
	}
}