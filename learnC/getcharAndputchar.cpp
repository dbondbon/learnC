#include<stdio.h>

void getcharAndputchar()
{
	int c;
	printf("������һ��ֵ��");
	c = getchar();
	printf("%d", c);
	putchar(c);
	return;
}

void getsAndputs() {
	char str[50];
	printf("�������ַ�����");
	gets_s(str);
	printf("\n %s", str);
}