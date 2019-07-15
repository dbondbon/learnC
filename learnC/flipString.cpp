#include<stdio.h>

void FlipString()
{
	char c;
	scanf("%c", &c);
	if (c != '\n') {
		FlipString();
		printf("%c", c);
	}
	return;
}