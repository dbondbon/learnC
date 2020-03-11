#include<stdio.h>
#include "algorithm.h"

int main()
{
	int nums[] = { 1, 8, 9, 9, 7, 6, 3, 9, 8, 7 };
	int numsSize = 10;

	int nums2[] = { 2, 3, 1, 1, 1, 3, 2 };
	int numsSize2 = 7;
	int res = majorityElement(nums, numsSize);

	return 0;
}