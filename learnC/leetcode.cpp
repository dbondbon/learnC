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

int countCharacters_simplify(char** words, int wordsSize, char* chars)
{
	int res = 0;
	int cmp[26] = {0};
	int temp[26];
	int chars_len = strlen(chars);
	for (int i = 0; i < chars_len; i++) {
		int index = chars[i] - 'a';
		cmp[index]++;
	}
	for (int i = 0; i < 26; i++) {
		temp[i] = cmp[i];
	}
	for (int i = 0; i < wordsSize; i++) {
		int flag = 1;
		int word_len = strlen(words[i]);
		if (word_len <= chars_len) {
			for (int j = 0; j < word_len; j++) {
				int index = words[i][j] - 'a';
				if (temp[index] == 0) {
					flag = 0;
					break;
				}
				temp[index]--;
			}
			if (flag) {
				res = res + word_len;
			}
			for (int i = 0; i < 26; i++) {
				temp[i] = cmp[i];
			}
		}
	}
	return res;
}

bool isRectangleOverlap(int *rec1, int rec1Size, int *rec2, int rec2Size) 
{
	// 找出所有不重叠的情况
	// 右
	if (rec2[0] >= rec1[2]) {
		return 0;
	}
	// 上 
	if (rec2[1] >= rec1[3]) {
		return 0;
	}
	// 左
	if (rec2[2] <= rec1[0]) {
		return 0;
	}
	// 下
	if (rec2[3] <= rec1[1]) {
		return 0;
	}
	return 1;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) 
{
	double res;
	int *temp = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
	int i = 0;
	int j = 0;
	int index = 0;
	while (i < nums1Size  && j < nums2Size) {
		if (nums1[i] < nums2[j]) {
			temp[index] = nums1[i];
			i++;
			index++;
		} else {
			temp[index] = nums2[j];
			j++;
			index++;
		}
	}
	if (i != nums1Size) {
		for (int m = i; m < nums1Size; m++) {
			temp[index] = nums1[m];
			index++;
		}
	}
	if (j != nums2Size) {
		for (int m = j; m < nums2Size; m++) {
			temp[index] = nums2[m];
			index++;
		}
	}
	int k = (nums1Size + nums2Size) / 2;
	if ((nums1Size + nums2Size) % 2 != 0) {
		res = temp[k];
	} else {
		double t = temp[k];
		res = (temp[k - 1] + t) / 2;
	}
	free(temp);
	return res;
}

int longestPalindrome(char *s) 
{
	int res = 0;
	int len = strlen(s);
	if (len == 0) {
		return 0;
	}
	if (len == 1) {
		return 1;
	}
	int temp1[26] = { 0 }; // A - Z
	int temp2[26] = { 0 }; // a - z
	for (int i = 0; i < len; i++) {
		if (s[i] < 97) {
			int index = s[i] - 65;
			temp1[index]++;
		} else {
			int index = s[i] - 97;
			temp2[index]++;
		}
	}
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (temp1[i] % 2 == 0) {
			res = res + temp1[i];
		} else {
			if (temp1[i] > 1) {
				res = res + temp1[i] - 1;
			}
			flag = 1;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (temp2[i] % 2 == 0) {
			res = res + temp2[i];
		}
		else {
			if (temp2[i] > 1) {
				res = res + temp2[i] - 1;
			}
			flag = 1;
		}
	}
	if (flag) {
		res++;
	}
	return res;
}

int *getLeastNumbers(int *arr, int arrSize, int k, int *returnSize) 
{
	*returnSize = k;
	int *res = (int*)malloc(sizeof(int) * k);
	int i = 0;
	for (i = 0; i < k; i++) {
		int  flag = 0;
		for (int j = arrSize - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = 1;
			}
		}
		res[i] = arr[i];
		if (!flag) {
			break;
		}
	}
	for (int m = i; m < k; m++) {
		res[m] = arr[m];
	}
	return res;
}

bool canMeasureWater(int x, int y, int z) 
{
	if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}
	if (x + y < z) {
		return 0;
	} 
	if (x == 0 || y == 0) {
		return z == 0 || x + y == z;
	}
	int m = x;
	int n = y;
	int r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	return z % n == 0;
}

int minIncrementForUnique(int *A, int ASize) 
{
	unsigned int res = 0;
	int max = 40000;
	int exist[40000] = { 0 };
	for (int i = 0; i < ASize; i++) {
		int index = A[i];
		exist[index] = exist[index] + 1;
	}
	for (int i = 0; i < 40000; i++) {
		int j = i + 1;
		if (exist[i] > 1) {
			if (i == 39999) {
				while (exist[i] > 1) {
					res = res + max - i;
					exist[i] = exist[i] - 1;
					max = max + 1;
				}
			} else {
				while (exist[i] > 1) {
					if (j < 40000 && !exist[j]) {
						res = res + j - i;
						exist[j] = 1;
						exist[i] = exist[i] - 1;
					} else if (j >= 40000) {
						res = res + max - i;
						exist[i] = exist[i] - 1;
						max = max + 1;
					}
					j++;
				}
			}
		}
	}
	return res;
}

static int get_target_val(int* A, int ASize, int index, int* last_index, int last_target)
{
	int temp_index = *last_index;
	int target_val = last_target + 1;
	while (target_val < A[index] || target_val <= A[temp_index] || (temp_index < ASize - 1 && target_val >= A[temp_index + 1])) {
		if (target_val <= A[temp_index]) {
			target_val++;
		}
		else {
			temp_index++;
		}
	}
	*last_index = temp_index;
	return target_val;
}

int minIncrementForUnique_my(int* A, int ASize) {
	int res = 0;
	// 1. 排序（冒泡）
	for (int i = 0; i < ASize - 1; i++) {
		for (int j = 0; j < ASize - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
	// 2. 遍历寻找重复值，计算每个重复值的 i_move
	int target_val = 0;
	int* last_index = (int*)malloc(sizeof(int));
	*last_index = 0;
	for (int i = 1; i < ASize; i++) {
		if (A[i] == A[i - 1]) {
			target_val = get_target_val(A, ASize, i, last_index, target_val);
			int i_move = 0;
			if (target_val > A[i]) {
				i_move = target_val - A[i];
			}
			else {
				i_move = A[i] - target_val;
			}
			res = res + i_move;
		}
	}
	free(last_index);
	return res;
}