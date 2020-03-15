#include <stdlib.h>
#include "leetcode.h"

static int maxAreaOfIsland_findAll(int **grid,int i, int j, int *temp, 
								   int gridSize, int gridColSize)
{
	// up
	if (i != 0 && grid[i - 1][j] == 1) {
		*temp = *temp + 1;
		grid[i - 1][j] = 0;
		maxAreaOfIsland_findAll(grid, i - 1, j, temp, gridSize, gridColSize);
	}
	// down
	if (i != gridSize - 1 && grid[i + 1][j] == 1) {
		*temp = *temp + 1;
		grid[i + 1][j] = 0;
		maxAreaOfIsland_findAll(grid, i + 1, j, temp, gridSize, gridColSize);
	}
	// left
	if (j != 0 && grid[i][j - 1] == 1) {
		*temp = *temp + 1;
		grid[i][j - 1] = 0;
		maxAreaOfIsland_findAll(grid, i, j - 1, temp, gridSize, gridColSize);
	}
	// right
	if (j != gridColSize - 1 && grid[i][j + 1] == 1) {
		*temp = *temp + 1;
		grid[i][j + 1] = 0;
		maxAreaOfIsland_findAll(grid, i, j + 1, temp, gridSize, gridColSize);
	}
	return *temp;
}
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
	int res = 0;
	int *temp = (int *)malloc(sizeof(int));
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			*temp = 0;
			if (grid[i][j] == 1) {
				*temp = 1;
				grid[i][j] = 0;
				maxAreaOfIsland_findAll(grid, i, j, temp, gridSize, *gridColSize);
			}
			if (*temp > res) {
				res = *temp;
			}
		}
	}
	free(temp);
	return res;
}