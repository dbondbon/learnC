#include<stdio.h>
#include "algorithm.h"

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = 7;
	int key = 8;
	int res = binary_search(arr, size, key);

	return 0;
}