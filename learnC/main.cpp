#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "leetcode2.h"
#include "learn_c.h"



int main()
{
	int matrix1[] = { 1,  5,  9 };
	int matrix2[] = { 10, 11, 13 };
	int matrix3[] = { 12, 13, 15 };
	int matrixSize = 3;
	int matrixColSize = 3;
	int k = 8;
	int** matrix = (int**)malloc(sizeof(int*) * matrixSize);
	matrix[0] = matrix1;
	matrix[1] = matrix2;
	matrix[2] = matrix3;
	int res = kthSmallest(matrix, matrixSize, &matrixColSize, k);
	free(matrix);

	return 0;
}
