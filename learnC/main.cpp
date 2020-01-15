#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include "global.h"

int main()
{
	int a = 'c';
	int b = '3';
	int c = '\t';
	printf("%d\n", isalnum(a));
	printf("%d\n", isalnum(b));
	printf("%d", isalnum(c));
	return 0;
}