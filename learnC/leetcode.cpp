#include <stdlib.h>
#include <string.h>
#include <math.h>
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

char *compressString(char *S)
{
	int len = strlen(S);
	int S_index = 0;
	int res_index = 0;
	char cmp; 
	int count;
	char *res = (char*)malloc(sizeof(char) * len * 2 + 1);
	while (S[S_index] != '\0') {
		cmp = S[S_index];
		res[res_index] = S[S_index];
		res_index++;
		count = 1;
		int i = S_index + 1;
		while (cmp == S[i]) {
			count++;
			S_index++;
			i = S_index + 1;
		}
		// 处理数字转字符
		if (count <= 9) {
			res[res_index] = count + 48;
			res_index++;
		} else if (count == 10) {
			res[res_index] = '1';
			res[res_index + 1] = '0';
			res_index = res_index + 2;
		} else {
			int number = 1;
			for (number = 1; number <= 4; number++) {
				if (count / pow(10, number) < 10) {
					break;
				}
			}
			for (int i = 0; i < number; i++) {
				int k = count % 10;
				count = count / 10;
				res[res_index + number - i] = k + 48;
			}
			res[res_index] = count + 48;
			res_index = res_index + number  + 1;
		}
		S_index++;
	}
	res[res_index] = S[S_index];
	int res_len = strlen(res);
	if (res_len >= len) {
		free(res);
		return S;
	}
	return res;
}

int countCharacters(char **words, int wordsSize, char *chars) 
{
	// 给chars排序(冒泡)
	int chars_len = strlen(chars);
	int temp = 0;
	for (int i = 0; i < chars_len - 1; i++) {
		for (int j = 0; j < chars_len - i - 1; j++) {
			if (chars[j] > chars[j + 1]) {
				temp = chars[j + 1];
				chars[j + 1] = chars[j];
				chars[j] = temp;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < wordsSize; i++) {
		int word_len = strlen(words[i]);
		if (word_len > chars_len) {
			continue;
		}
		// 给word[i]排序(冒泡)
		for (int m = 0; m < word_len - 1; m++) {
			for (int n = 0; n < word_len - m - 1; n++) {
				if (words[i][n] > words[i][n + 1]) {
					temp = words[i][n + 1];
					words[i][n + 1] = words[i][n];
					words[i][n] = temp;
				}
			}
		}
		// 比对
		int w_index = 0;
		int c_index = 0;
		int contain_flag = 1;
		for (w_index = 0; w_index < word_len; w_index++) {
			int find_flag = 0;
			if (words[i][w_index] == chars[c_index]) {
				c_index++;
			} else {
				while (words[i][w_index] > chars[c_index]) {
					c_index++;
					if (c_index >= chars_len) {
						break;
					}
					if (words[i][w_index] == chars[c_index]) {
						c_index++;
						find_flag = 1;
						break;
					}
				}
				if (!find_flag) {
					contain_flag = 0;
					break;
				}
			}
		}
		if (contain_flag) {
			res = res + word_len;
		}
	}
	return res;
}