#include<stdio.h>
#include<stdlib.h>
#include "leetcode.h"

int main()
{
	int gridSize = 3;
	int gridColSize = 5;
	int **grid = (int **)malloc(sizeof(int *) * gridSize);
	for (int i = 0; i < gridSize; i++) {
		grid[i] = (int *)malloc(sizeof(int) * gridColSize);
	}
	grid[0][0] = 1;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize; j++) {	
			if ((i == 1 && j > 2) || (i == 2 && j > 3)) {
				grid[i][j] = 1;
			} else {
				grid[i][j] = 0;
			}
		}
	}

	int res = maxAreaOfIsland(grid, gridSize, &gridColSize);

	for (int i = 0; i < gridSize; i++) {
		free(grid[i]);
	}
	free(grid);

	return 0;
}