#include<stdio.h>
#include "global.h"

int main()
{
	int n1;
	int n2;
	scanf("%d %d", &n1, &n2);
	int gcd = FindGcd(n1, n2);
	printf("%d��%d�����Լ��Ϊ%d", n1, n2, gcd);
	return 0;
}