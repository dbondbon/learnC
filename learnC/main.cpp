#include<stdio.h>
#include<stdlib.h>
#include "leetcode.h"

int main()
{
	int nums1[] = { 1, 2 };
	int nums1Size = 2;
	int nums2[] = { 3, 4 };
	int nums2Size = 2;

	double res = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

	return 0;
}