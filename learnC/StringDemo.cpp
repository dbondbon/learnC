#include<stdio.h>
#include<string.h>

void stringDemo() {
	char str[] = { 'A', 'B', '\0' };
	printf("%s", str);
	printf("%d", strlen(str));
	return;
}