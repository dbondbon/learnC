#include<stdio.h>
#include<stdlib.h>
#include "leetcode.h"

int main()
{
	int rec1[] = { 0,0,1,1 };
	int rec1Size = 4;
	int rec2[] = { 1,0,2,1 };
	int rec2Size = 4;

	bool res = isRectangleOverlap(rec1, rec1Size, rec2, rec2Size);

	return 0;
}