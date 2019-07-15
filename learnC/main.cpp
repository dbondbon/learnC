#include<stdio.h>
#include "global.h"

int main()
{
	int originalInteger;
	scanf("%d", &originalInteger);
	int res = PalindromicNumber(originalInteger);
	if (res == 0) {
		printf("数%d是回文数", originalInteger);
	} else {
		printf("数%d不是回文数", originalInteger);
	}
	return 0;
}