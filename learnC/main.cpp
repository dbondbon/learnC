#include<stdio.h>
#include "global.h"

int main()
{
	int originalInteger;
	scanf("%d", &originalInteger);
	int res = PalindromicNumber(originalInteger);
	if (res == 0) {
		printf("��%d�ǻ�����", originalInteger);
	} else {
		printf("��%d���ǻ�����", originalInteger);
	}
	return 0;
}