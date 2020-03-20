#include<stdio.h>
#include<stdlib.h>
#include "leetcode.h"

int main()
{
	int arr[] = { 1 };
	int arrSize = 1;
	int k = 1;
	int returnSize = 0;

	int *res = getLeastNumbers(arr, arrSize, k, &returnSize);
	free(res);

	return 0;
}