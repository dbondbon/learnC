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
			int i_move = target_val - A[i];
			res = res + i_move;
		}
	}
	free(last_index);
	return res;
}

ListNode* middleNode(ListNode *head) 
{
	ListNode* cur_node = head;
	ListNode* next_node = head->next;
	int node_count = 1;
	while (next_node != NULL) {
		cur_node = next_node;
		next_node = cur_node->next;
		node_count++;
	}
	int target = 0;
	target = node_count / 2;
	ListNode* res = head;
	while (target != 0) {
		res = res->next;
		target--;
	}
	return res;
}

int massage(int *nums, int numsSize) 
{
	// dp(n) = max {nums[n] + dp(n - 2), dp(n - 1) }
	// dp(0) = nums[0]
	// dp(1) = max {nums[0], nums[1]}
	if (numsSize == 0) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0];
	}
	int *dp = (int*)malloc(sizeof(int) * numsSize);
	dp[0] = nums[0];
	if (nums[0] > nums[1]) {
		dp[1] = nums[0];
	} else {
		dp[1] = nums[1];
	}
	for (int i = 2; i < numsSize; i++) {
		if (nums[i] + dp[i - 2] > dp[i - 1]) {
			dp[i] = nums[i] + dp[i - 2];
		} else {
			dp[i] = dp[i - 1];
		}
	}
	int res = dp[numsSize - 1];
	free(dp);
	return res;
}

struct ListNode *reverseList(ListNode* head) 
{
	int count = 0;
	ListNode *cur = head;
	while (cur != NULL) {
		count++;
		cur = cur->next;
	}
	int *temp = (int*)malloc(sizeof(int) * count);
	cur = head;
	int i = 0;
	while (cur != NULL) {
		temp[i] = cur->val;
		cur = cur->next;
		i++;
	}
	cur = head;
	i = 0;
	while (cur != NULL) {
		cur->val = temp[count - i - 1];
		cur = cur->next;
		i++;
	}
	return head;
}

static void surfaceArea_find_more(int** grid, int gridSize, int* gridColSize, int i, int j, int* res)
{
	// up
	if (i != 0 && grid[i - 1][j] > 0) {
		if (grid[i - 1][j] > grid[i][j]) {
			*res = *res - grid[i][j]; 
		} else {
			*res = *res - grid[i - 1][j];
		}
	}
	// down
	if (i != 49 && i + 1 < gridSize && grid[i + 1][j] > 0) {
		if (grid[i + 1][j] > grid[i][j]) {
			*res = *res - grid[i][j];
		} else {
			*res = *res - grid[i + 1][j];
		}
	}
	// left
	if (j != 0 && grid[i][j - 1] > 0) {
		if (grid[i][j - 1] > grid[i][j]) {
			*res = *res - grid[i][j];
		}
		else {
			*res = *res - grid[i][j - 1];
		}
	}
	// right
	if (j != 49 && j + 1 < *gridColSize && grid[i][j + 1] > 0) {
		if (grid[i][j + 1] > grid[i][j]) {
			*res = *res - grid[i][j];
		}
		else {
			*res = *res - grid[i][j + 1];
		}
	}
}

int surfaceArea(int** grid, int gridSize, int* gridColSize) 
{
	int res = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] > 0) {
				res = res + grid[i][j] * 6 - (grid[i][j] - 1) * 2;
				surfaceArea_find_more(grid, gridSize, gridColSize, i, j, &res);
			}
		}
	}
	return res;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n) 
{
	for (int i = 0; i < n; i++) {
		A[m + i] = B[i];
	}
	int flag = 0;
	for (int i = 0; i < ASize - 1; i++) {
		for (int j = 0; j < ASize - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				flag = 1;
			}
		}
		if (!flag) {
			break;
		}
	}
}

int numRookCaptures(char** board, int boardSize, int* boardColSize) 
{
	int res = 0;
	// find R
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			if (board[i][j] == 'R') {
				int i_temp, j_temp;
				// up
				i_temp = i - 1;
				while (i_temp >= 0) {
					if (board[i_temp][j] == '.') {
						i_temp--;
					} else if (board[i_temp][j] == 'p') {
						res++;
						break;
					} else {
						break;
					}
				}
				// down
				i_temp = i + 1;
				while (i_temp < boardSize) {
					if (board[i_temp][j] == '.') {
						i_temp++;
					} else if (board[i_temp][j] == 'p') {
						res++;
						break;
					} else {
						break;
					}
				}
				// left
				j_temp = j - 1;
				while (j_temp >= 0) {
					if (board[i][j_temp] == '.') {
						j_temp--;
					} else if (board[i][j_temp] == 'p') {
						res++;
						break;
					} else {
						break;
					}
				}
				// right
				j_temp = j + 1;
				while (j_temp < *boardColSize) {
					if (board[i][j_temp] == '.') {
						j_temp++;
					} else if (board[i][j_temp] == 'p') {
						res++;
						break;
					} else {
						break;
					}
				}
				return res;
			}
		}
	}
	return res;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) 
{
	int k = 3;
	int res = 0;
	int flag = 0;
	while (flag == 0) {
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < *gridColSize; j++) {
				if (grid[i][j] == 1) {	
					if (i != 0 && grid[i - 1][j] > 1 && grid[i - 1][j] < k) {
						// up
						grid[i][j] = k;
						flag = 1;
					} else if (i < gridSize - 1 && grid[i + 1][j] > 1 && grid[i + 1][j] < k) {
						// down
						grid[i][j] = k;
						flag = 1;
					} else if (j != 0 && grid[i][j - 1] > 1 && grid[i][j - 1] < k) {
						// left
						grid[i][j] = k;
						flag = 1;
					} else if (j < *gridColSize - 1 && grid[i][j + 1] > 1 && grid[i][j + 1] < k) {
						// right
						grid[i][j] = k;
						flag = 1;
					}
				}
			}
		}
		if (flag) {
			k++;
			flag = 0;
		} else {
			break;
		}
	}
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1) {
				return -1;
			}
		}
	}
	res = k - 3;
	return res;
}

bool hasGroupsSizeX(int* deck, int deckSize) 
{
	int temp[10000] = { 0 };
	int index = 0;
	int x = 0;
	for (int i = 0; i < deckSize; i++) {
		index = deck[i];
		temp[index]++;
	}
	for (x = 10000; x >= 2; x--) {
		int flag = 1;
		for (int i = 0; i < 10000; i++) {
			if (temp[i] == 1) {
				return 0;
			} else if (temp[i] % x == 0) {
				continue;
			} else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	return 0;
}

int minimumLengthEncoding(char** words, int wordsSize) 
{
	int res = 0;
	int words_indexes[2000] = {0};
	words_indexes[0] = 1;
	int len = strlen(words[0]);
	res = len + 1;
	for (int i = 1; i < wordsSize; i++) {
		int flag = 0;
		int len1 = strlen(words[i]);
		for (int j = 0; j < i; j++) {
			if (words_indexes[j] == 1) {
				int len2 = strlen(words[j]);
				if (len1 > len2) {
					for (int k = len2 - 1; k >= 0; k--) {
						if (words[j][k] != words[i][k + len1 - len2]) {
							break;
						}
						if (k == 0) {
							flag = 1;
						}
					}
				} else {
					for (int k = len1 - 1; k >= 0; k--) {
						if (words[i][k] != words[j][k + len2 - len1]) {
							break;
						}
						if (k == 0) {
							flag = 1;
						}
					}
				}
				if (flag) {
					if (len1 > len2) {
						res = res - len2 + len1;
						words_indexes[i] = 1;
						words_indexes[j] = 0;	
					}
					break;
				}
			}
		}
		if (!flag) {
			res = res + len1 + 1;
			words_indexes[i] = 1;
		}
	}
	return res;
}

int* distributeCandies(int candies, int num_people, int* returnSize) 
{
	*returnSize = num_people;
	int* res = (int*)malloc(sizeof(int) * num_people);
	for (int i = 0; i < num_people; i++) {
		res[i] = 0;
	}
	int k_people = 0;
	int temp_candies = 1;
	while (candies >= temp_candies) {
		res[k_people % num_people] = res[k_people % num_people] + temp_candies;
		k_people++;
		candies = candies - temp_candies;
		temp_candies++;
	}
	res[k_people % num_people] = res[k_people % num_people] + candies;
	return res;
}

int maxDistance(int** grid, int gridSize, int* gridColSize) 
{
	int k = 2; // 填海代数
	int flag = 0;
	do {
		flag = 0;
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < *gridColSize; j++) {
				if (grid[i][j] == (k - 1)) {
					// 上
					if (i > 0 && grid[i - 1][j] == 0) {
						grid[i - 1][j] = k;
						flag = 1;
					}
					// 下
					if (i < gridSize - 1 && grid[i + 1][j] == 0) {
						grid[i + 1][j] = k;
						flag = 1;
					}
					// 左
					if (j > 0 && grid[i][j - 1] == 0) {
						grid[i][j - 1] = k;
						flag = 1;
					}
					// 右
					if (j < *gridColSize - 1 && grid[i][j + 1] == 0) {
						grid[i][j + 1] = k;
						flag = 1;
					}
				}
			}
		}
		if (flag) {
			k++;
		}
	} while (flag);
	return	k == 2 ? -1 : k - 2;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes) 
{
	*returnSize = 3;
	int **returnColumnSizes_2 = (int **)malloc(sizeof(int) * 6);
	int **res = (int**)malloc(sizeof(int) * 6);
	return res;
}

int lastRemaining(int n, int m) 
{
	int res = 0;
	for (int i = 2; i != n + 1; i++)
		res = (res + m) % i;
	return res;
}

static void quick_sort(int* nums,int i, int j)
{
	if (i < j) {
		int k = nums[i];
		int temp_i = i + 1;
		int temp_j = j;
		while (true) {
			while (temp_i <= j && nums[temp_i] < k) {
				temp_i++;
			}
			while (temp_j >= i && nums[temp_j] > k) {
				temp_j--;
			}
			if (temp_i < temp_j) {
				int temp = nums[temp_i];
				nums[temp_i] = nums[temp_j];
				nums[temp_j] = temp;
				temp_i++;
				temp_j--;
			} else {
				break;
			}
		}
		nums[i] = nums[temp_j];
		nums[temp_j] = k;
		quick_sort(nums, i, temp_j - 1);
		quick_sort(nums, temp_j + 1, j);
	}
}

static void sortArray_sort(int* nums, int numsSize)
{
	int temp[100001] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		int index = nums[i] + 50000;
		temp[index]++;
	}
	int index = 0;
	for (int i = 0; i < 100001; i++) {
		while (temp[i] > 0) {
			nums[index++] = i - 50000;
			temp[i]--;
		}
	}
}

int* sortArray(int* nums, int numsSize, int* returnSize) 
{
	*returnSize = numsSize;
	quick_sort(nums, 0, numsSize - 1);
	return nums;
}

int* maxDepthAfterSplit(char* seq, int* returnSize) 
{
	int len = strlen(seq);
	*returnSize = len;
	int *res = (int*)malloc(sizeof(int) * len);
	// 模拟派分 A序列对应a-0,B序列对应b-1   '(' +1, ')' -1
	int a = 0;
	int b = 0;
	for (int i = 0; i < len; i++) {
		if (seq[i] == '(') {
			// 按优先级排序
			if (a == 0) {
				a++;
				res[i] = 0;
			} else if (b == 0) {
				b++;
				res[i] = 1;
			} else if (a < b) {
				a++;
				res[i] = 0;
			} else if (a >= b) {
				b++;
				res[i] = 1;
			}
		} else {
			if (a > b) {
				a--;
				res[i] = 0;
			} else {
				b--;
				res[i] = 1;
			}
		}
	}
	return res;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) 
{
	// 规定状态 活->死 -1 活->活 1 死->活 2 死->死 0
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			// 计算周围活细胞数量
			int count = 0;
			if (i > 0 && (board[i - 1][j] == 1 || board[i - 1][j] == -1)) {
				count++;
			}
			if (i > 0 && j < *boardColSize - 1  && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -1)) {
				count++;
			}
			if (j < *boardColSize - 1 && (board[i][j + 1] == 1 || board[i][j + 1] == -1)) {
				count++;
			}
			if (i < boardSize - 1 && j < *boardColSize - 1 && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -1)) {
				count++;
			}
			if (i < boardSize - 1 && (board[i + 1][j] == 1 || board[i + 1][j] == -1)) {
				count++;
			}
			if (i < boardSize - 1 && j > 0 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -1)) {
				count++;
			}
			if (j > 0 && (board[i][j - 1] == 1 || board[i][j - 1] == -1)) {
				count++;
			}
			if (i > 0 && j > 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -1)) {
				count++;
			}
			if (board[i][j] == 1) {
				if (count < 2 || count > 3) {
					board[i][j] = -1;
				}
			} else {
				if (count == 3) {
					board[i][j] = 2;
				}
			}
		}
	}
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			if (board[i][j] == -1) {
				board[i][j] = 0;
			}
			if (board[i][j] == 2) {
				board[i][j] = 1;
			}
		}
	}
}

int myAtoi(char* str) 
{
	int res = 0;
	double temp_res = 0;
	int str_len = strlen(str);
	int i = 0;
	while (str[i] == ' ') {
		i++;
		if (i == str_len) {
			return res;
		}
	}
	if (str[i] == '+' || str[i] == '-') {
		for (int j = i + 1; j < str_len; j++) {
			if (str[j] >= '0' && str[j] <= '9') {
				temp_res = temp_res * 10 + str[j] - 48;
			} else {
				break;
			}
		}
		if (str[i] == '+') {
			res = temp_res <= INT_MAX ? temp_res : INT_MAX;
			
		} else {
			res = temp_res <= pow(2, 31) ? -1 * temp_res : INT_MIN;
		}
	} else if (str[i] >= '0' && str[i] <= '9') {
		for (int j = i; j < str_len; j++) {
			if (str[j] >= '0' && str[j] <= '9') {
				temp_res = temp_res * 10 + str[j] - 48;
			} else {
				break;
			}
		}
		res = temp_res <= INT_MAX ? temp_res : INT_MAX;
	}
	return res;
}

int trap(int* height, int heightSize) 
{
	int res = 0;
	if (heightSize == 0) {
		return 0;
	}
	int *left_max = (int*)malloc(sizeof(int) * heightSize);
	int *right_max = (int*)malloc(sizeof(int) * heightSize);
	left_max[0] = height[0];
	for (int i = 1; i < heightSize; i++) {
		left_max[i] = height[i] > left_max[i - 1] ? height[i] : left_max[i - 1];
	}
	right_max[heightSize - 1] = height[heightSize - 1];
	for (int i = heightSize - 2; i >= 0; i--) {
		right_max[i] = height[i] > right_max[i + 1] ? height[i] : right_max[i + 1];
	}
	for (int i = 1; i < heightSize - 1; i++) {
		int k = left_max[i] > right_max[i] ? right_max[i] : left_max[i];
		res = res + k - height[i];
	}
	free(left_max);
	free(right_max);
	return res;
}

LFUCache* lFUCacheCreate(int capacity) 
{
	LFUCache* head = (LFUCache*)malloc(sizeof(LFUCache));
	head->prev = NULL;
	head->next = NULL;
	head->key = -1;
	head->val = -1;
	head->freq = 0;
	head->total_size = capacity;
	head->cur_size = 0;
	return head;
}

static void lFUCacheInsert(LFUCache* obj, LFUCache* new_node)
{
	LFUCache *head = obj;
	LFUCache *cur_node = head->next;
	LFUCache *last_node = head;
	LFUCache *temp = NULL;
	cur_node = head->next;
	while (cur_node != NULL) {
		if (cur_node->freq <= new_node->freq) {
			last_node = cur_node->prev;
			break;
		}
		last_node = cur_node;
		cur_node = cur_node->next;
	}
	if (last_node->next == NULL) {
		if (head->cur_size < head->total_size) {
			head->cur_size = head->cur_size + 1;
			last_node->next = new_node;
			new_node->prev = last_node;
			new_node->next = NULL;
		} else {
			new_node->prev = last_node->prev;
			last_node->prev->next = new_node;
			new_node->next = NULL;
			free(last_node);
		}
	} else {
		new_node->prev = last_node;
		new_node->next = last_node->next;
		last_node->next->prev = new_node;
		last_node->next = new_node;
		if (head->cur_size < head->total_size) {
			head->cur_size = head->cur_size + 1;
		} else {
			temp = last_node;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->prev->next = NULL;
			free(temp);
		}
	}
}

int lFUCacheGet(LFUCache* obj, int key) 
{
	int val = -1;
	LFUCache *head = obj;
	LFUCache *cur_node = head->next;
	LFUCache *key_node = NULL;
	if (head->cur_size == 0) {
		return val;
	}
	while (cur_node != NULL) {
		if (cur_node->key == key) {
			val = cur_node->val;
			key_node = cur_node;
			break;
		}
		cur_node = cur_node->next;
	}
	if (key_node != NULL) {
		if (key_node->next == NULL) {
			key_node->prev->next = NULL;
		} else {
			key_node->prev->next = key_node->next;
			key_node->next->prev = key_node->prev;
		}
		key_node->freq = key_node->freq + 1;
		obj->cur_size = obj->cur_size - 1;
		lFUCacheInsert(obj, key_node);
	}
	return val;
}

void lFUCachePut(LFUCache* obj, int key, int value) 
{
	int flag_new = 1;
	LFUCache *head = obj;
	LFUCache *cur_node = head->next;
	LFUCache *key_node = NULL;
	while (cur_node != NULL) {
		if (cur_node->key == key) {
			cur_node->val = value;
			key_node = cur_node;
			flag_new = 0;
		}
		cur_node = cur_node->next;
	}
	if (flag_new) {
		if (head->total_size > 0) {
			LFUCache* new_node = (LFUCache*)malloc(sizeof(LFUCache));
			new_node->key = key;
			new_node->val = value;
			new_node->freq = 0;
			lFUCacheInsert(obj, new_node);
		}
	} else {
		key_node->prev->next = key_node->next;
		if (key_node->next != NULL) {
			key_node->next->prev = key_node->prev;
		}
		key_node->freq = key_node->freq + 1;
		obj->cur_size = obj->cur_size - 1;
		lFUCacheInsert(obj, key_node);
	}
}

void lFUCacheFree(LFUCache* obj) 
{
	LFUCache* cur = obj;
	LFUCache* next = NULL;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}