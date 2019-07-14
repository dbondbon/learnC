#include<stdio.h>

void getcharAndputchar()
{
	int c;
	printf("请输入一个值：");
	c = getchar();
	printf("%d", c);
	putchar(c);
	return;
}

void getsAndputs() {
	char str[50];
	printf("请输入字符串：");
	gets_s(str);
	printf("\n %s", str);
}