#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "leetcode2.h"

/** Initialize your data structure here. */
Twitter* twitterCreate() 
{
	Twitter* twitter = (Twitter *)malloc(sizeof(Twitter));
	twitter->twitter_tweet_size = 0;
	return twitter;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) 
{
	user* cur_user = NULL;
	int index = 0;
	if (obj->flag_user[userId] == 0) {
		obj->flag_user[userId] = 1;
		obj->users[userId] = *(user*)malloc(sizeof(user));
		obj->users[userId].user_friends_size = 0;
	}
	cur_user = &(obj->users[userId]);
	index = cur_user->user_friends_size;
	cur_user->user_tweets[index] = *(tweet*)malloc(sizeof(tweet));
	cur_user->user_tweets[index].tweet_id = tweetId;
	cur_user->user_tweets[index].post_time = obj->twitter_tweet_size;
	obj->twitter_tweet_size += 1;
	cur_user->user_tweets_size += 1;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) 
{
	return NULL;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) 
{

}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) 
{

}

void twitterFree(Twitter* obj) 
{
	for (int i = 0; i < 10000; i++) {
		if (obj->flag_user[i] == 1) {
			free(&obj->users[i]);
		}
	}
	free(obj);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	ListNode* res = NULL;
	ListNode* temp = NULL;
	int node1_size = 1;
	int node2_size = 1;
	temp = l1;
	while (temp->next != NULL) {
		node1_size++;
		temp = temp->next;
	}
	temp = l2;
	while (temp->next != NULL) {
		node2_size++;
		temp = temp->next;
	}
	int* list1 = (int*)malloc(sizeof(int) * node1_size);
	temp = l1;
	for (int i = node1_size - 1; i >= 0; i--) {
		list1[i] = temp->val;
		temp = temp->next;
	}
	int* list2 = (int*)malloc(sizeof(int) * node2_size);
	temp = l2;
	for (int i = node2_size - 1; i >= 0; i--) {
		list2[i] = temp->val;
		temp = temp->next;
	}
	int i = 0;
	int val = 0;
	int add = 0;
	while (i < node1_size && i < node2_size) {
		val = list1[i] + list2[i] + add;
		add = 0; 
		if (val > 9) {
			val = val - 10;
			add = 1;
		}
		ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
		new_node->val = val;
		new_node->next = res;
		res = new_node;
		i++;
	}
	if (i == node1_size) {
		while (i < node2_size) {
			val = list2[i] + add;
			add = 0;
			if (val > 9) {
				val = val - 10;
				add = 1;
			}
			ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
			new_node->val = val;
			new_node->next = res;
			res = new_node;
			i++;
		}
	} else {
		while (i < node1_size) {
			val = list1[i] + add;
			add = 0;
			if (val > 9) {
				val = val - 10;
				add = 1;
			}
			ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
			new_node->val = val;
			new_node->next = res;
			res = new_node;
			i++;
		}
	}
	if (add == 1) {
		val = add;
		ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
		new_node->val = val;
		new_node->next = res;
		res = new_node;
	}
	free(list1);
	free(list2);
	return res;
}

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) 
{
	*returnSize = matrixSize;
	*returnColumnSizes = (int*)malloc(sizeof(int) * matrixSize);
	for (int i = 0; i < matrixSize; i++) {
		(*returnColumnSizes)[i] = *matrixColSize;
	}
	int** res = (int**)malloc(sizeof(int*) * matrixSize);
	for (int i = 0; i < matrixSize; i++) {
		res[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
		memset(res[i], -1, sizeof(int) * (*matrixColSize));
	}
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < *matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				res[i][j] = matrix[i][j];
			}
		}
	}
	int k = 0;
	int flag;
	do {
		flag = 0;
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < *matrixColSize; j++) {
				if (res[i][j] == -1) {	
					if (i > 0 && res[i - 1][j] == k) {
						// 上
						res[i][j] = k + 1;
						flag = 1;
					} else if (i < matrixSize - 1 && res[i + 1][j] == k) {
						// 下
						res[i][j] = k + 1;
						flag = 1;
					} else if (j > 0 && res[i][j - 1] == k) {
						// 左
						res[i][j] = k + 1;
						flag = 1;
					} else if (j < *matrixColSize - 1 && res[i][j + 1] == k) {
						// 右
						res[i][j] = k + 1;
						flag = 1;
					}
				}
			}
		}
		k++;
	} while (flag);
	return res;
}

int** merge_next(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
	if (intervalsSize == 0) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}
	int temp[10000] = { 0 };
	int** res = (int**)malloc(sizeof(int*) * intervalsSize);
	for (int i = 0; i < intervalsSize; i++) {
		res[i] = (int*)malloc(sizeof(int) * (*intervalsColSize));
	}
	for (int i = 0; i < intervalsSize; i++) {
		int first = intervals[i][0];
		if (first == 1) {
			for (int j = first; j <= intervals[i][1]; j++) {
				temp[j] = 1;
			}
		}
		else {

		}
	}
	int index = 0;
	for (int i = 0; i < 10000; i++) {
		if (temp[i] == 1) {
			res[index][0] = i;
			i++;
			while (temp[i] == 1) {
				i++;
			}
			res[index][1] = i - 1;
			index++;
		}
	}
	*returnSize = index;
	for (int i = index; i < intervalsSize; i++) {
		free(res[i]);
	}
	*returnColumnSizes = (int*)malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		(*returnColumnSizes)[i] = *intervalsColSize;
	}
	return res;
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) 
{
	if (intervalsSize == 0) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}
	int** res = (int**)malloc(sizeof(int*) * intervalsSize);
	for (int i = 0; i < intervalsSize; i++) {
		res[i] = (int*)malloc(sizeof(int) * (*intervalsColSize));
	}
	// 按起点排序
	for (int i = 0; i < intervalsSize - 1; i++) {
		int flag = 1;
		for (int j = 0; j < intervalsSize - i - 1; j++) {
			if (intervals[j][0] > intervals[j + 1][0]) {
				int temp1 = intervals[j][0];
				int temp2 = intervals[j][1];
				intervals[j][0] = intervals[j + 1][0];
				intervals[j][1] = intervals[j + 1][1];
				intervals[j + 1][0] = temp1;
				intervals[j + 1][1] = temp2;
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
	int index = 0;
	res[index][0] = intervals[0][0];
	res[index][1] = intervals[0][1];
	int last_j = intervals[0][1];
	for (int i = 1; i < intervalsSize; i++) {
		if (intervals[i][0] > last_j) {
			index++;
			res[index][0] = intervals[i][0];
			res[index][1] = intervals[i][1];
			last_j = intervals[i][1];
		} else {
			if (intervals[i][1] > last_j) {
				res[index][1] = intervals[i][1];
				last_j = intervals[i][1];
			}
		}
	}
	for (int i = index + 1; i < intervalsSize; i++) {
		free(res[i]);
	}
	*returnSize = index + 1;
	*returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = *intervalsColSize;
	}
	return res;
}

static bool canJump_next(int* nums, int numsSize, int *temp)
{
	if (numsSize == 1) {
		return 1;
	}
	for (int i = numsSize - 2; i >= 0; i--) {
		if (nums[i] >= numsSize - i - 1) {
			if (i == 0) {
				return 1;
			} else {
				if (temp[i] == 1) {
					continue;
				} else {
					temp[i] = 1;
					if (canJump_next(nums, i + 1, temp)) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

bool canJump(int* nums, int numsSize) 
{
	// 辅助数组，判断是否重复检测
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	memset(temp, 0, sizeof(int) * numsSize);
	if (numsSize == 1) {
		return 1;
	}
	for (int i = numsSize - 2; i >= 0; i--) {
		if (nums[i] >= numsSize - i - 1) {
			if (i == 0) {
				free(temp);
				return 1;
			} else {
				if (temp[i] == 1) {
					continue;
				} else {
					temp[i] = 1;
					if (canJump_next(nums, i + 1, temp)) {
						free(temp);
						return 1;
					}
				}
			}
		}
	}
	free(temp);
	return 0;
}

int maxArea(int* height, int heightSize) 
{
	int res = 0;
	for (int i = 0; i < heightSize - 1; i++) {
		for (int j = i + 1; j < heightSize; j++) {
			int area = (j - i) * min(height[i], height[j]);
			res = max(area, res);
		}
	}
	return res;
}

int getMaxRepetitions(char* s1, int n1, char* s2, int n2) 
{
	int cnt = 0;
	int s1i, s2i;
	int l1 = strlen(s1), l2 = strlen(s2);
	int sign = -1;
	int n;
	s2i = 0;
	for (int i = 0; i < n1; ++i) {
		s1i = 0;
		while (s1i < l1) {
			if (s1[s1i] == s2[s2i]) {
				if (s2i == 0 && sign == -1) {
					sign = s1i;
				}
				else if (s2i == 0 && s1i == sign) {
					n = (n1 - 1) / i;
					cnt *= n;
					i *= n;
					sign = -1;
				}
				++s2i;
			}
			if (s2i == l2) {
				++cnt;
				s2i = 0;
			}
			++s1i;
		}
	}
	return cnt / n2;
}

static void numIslands_get_more(char** grid, int gridSize, int gridColSize, int i, int j)
{
	// up
	if (i > 0 && grid[i - 1][j] == '1') {
		grid[i - 1][j] = '2';
		numIslands_get_more(grid, gridSize, gridColSize, i - 1, j);
	}
	// right
	if (j < gridColSize - 1 && grid[i][j + 1] == '1') {
		grid[i][j + 1] = '2';
		numIslands_get_more(grid, gridSize, gridColSize, i, j + 1);
	}
	// down
	if (i < gridSize - 1 && grid[i + 1][j] == '1') {
		grid[i + 1][j] = '2';
		numIslands_get_more(grid, gridSize, gridColSize, i + 1, j);
	}
	// left
	if (j > 0 && grid[i][j - 1] == '1') {
		grid[i][j - 1] = '2';
		numIslands_get_more(grid, gridSize, gridColSize, i, j - 1);
	}
}

int numIslands(char** grid, int gridSize, int* gridColSize) 
{
	int res = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == '1') {
				res++;
				grid[i][j] = '2';
				numIslands_get_more(grid, gridSize, *gridColSize, i, j);
			}
		}
	}
	return res;
}

int numberOfSubarrays(int* nums, int numsSize, int k) 
{
	int res = 0;
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	int total = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 2 != 0) {
			temp[total] = i;
			total++;
		}
	}
	if (total < k) {
		return 0;
	}
	for (int i = 0; i + k <= total; i++) {
		if (i == 0) {
			if (i + k == total) {
				res += (temp[i] + 1) * (numsSize - temp[i + k - 1]);
			} else {
				res += (temp[i] + 1) * (temp[i + k] - temp[i + k - 1]);
			}
		} else if (i + k == total) {
			res += (temp[i] - temp[i - 1]) * (numsSize - temp[i + k - 1]);
		} else {
			res += (temp[i] - temp[i - 1]) * (temp[i + k] - temp[i + k - 1]);
		}
	}
	free(temp);
	return res;
}

static void rightSideView_get_val(TreeNode *root, int *dest, int* depth_flag, int depth, int *returnSize)
{
	if (root->right != NULL) {
		if (!depth_flag[depth]) {
			*returnSize += 1;
			depth_flag[depth] = 1;
			dest[depth] = root->right->val;	
		}
		rightSideView_get_val(root->right, dest, depth_flag, depth + 1, returnSize);
	} 
	if (root->left != NULL) {
		if (!depth_flag[depth]) {
			*returnSize += 1;
			depth_flag[depth] = 1;
			dest[depth] = root->left->val;	
		}
		rightSideView_get_val(root->left, dest, depth_flag, depth + 1, returnSize);
	}
}

int* rightSideView(TreeNode* root, int* returnSize) 
{
	int depth_flag[10000] = { 0 };
	int temp[10000] = { -1 };
	int depth = 0;
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	temp[depth++] = root->val;
	*returnSize = 1;
	rightSideView_get_val(root, temp, depth_flag, depth, returnSize);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; i++) {
		res[i] = temp[i];
	}
	return res;
}

int waysToChange2(int n) 
{
	int res = 1;
	int temp_n = n;
	int temp_res = 0;
	int a1 = n / 25;
	int a2 = 0;
	int a3 = 0;
	for (int i = 1; i <= a1; i++) {
		temp_n = n - 25 * i;
		int temp_n2 = 0;
 		a2 = temp_n / 10;
		for (int j = 0; j <= a2; j++) {
			temp_n2 = temp_n - 10 * j;
			a3 = temp_n2 / 5;
			temp_res = (temp_res + a3 + 1) % 1000000007;
		}
	}
	res = (res + temp_res) % 1000000007;
	temp_res = 0;
	temp_n = n;
	a1 = n / 10;
	for (int i = 1; i <= a1; i++) {
		temp_n = n - 10 * i;
		a2 = temp_n / 5;
		temp_res = (temp_res + a2 + 1) % 1000000007;
	}
	res = (res + temp_res) % 1000000007;
	a1 = n / 5;
	res = (res + a1) % 1000000007;
	return res;
}
#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int coins[4] = { 1, 5, 10, 25 };

//【算法思路】dp。
int waysToChange(int n) {
	int* dp = (int*)calloc(n + 1, sizeof(int));
	dp[0] = 1;
	for (int i = 0; i < 4; i++) {
		int coin = coins[i];

		for (int j = 1; j <= n; j++) {
			if (j - coin >= 0) {
				dp[j] = (dp[j] + dp[j - coin]) % 1000000007;
			}
		}
	}
	int res = dp[n];
	return res;
}

// 并函数
// tempArr 只在主函数申请一次的长度为numsSize的数组，防止递归过程中每次申请一个数组
// 将结果并到tempArr之后拷贝到原数组的相应部分
void Merge(int left, int center, int right, int* nums, int* tempArr, int* ret) {
	int tPos = left;
	int lPos = left;
	int rPos = center + 1;
	// 两个数组非空时，比较后合到一起
	while (lPos <= center && rPos <= right) {
		if (nums[lPos] <= nums[rPos]) {
			tempArr[tPos++] = nums[lPos++];
		}
		else {
			(*ret) = (*ret) + (center - lPos + 1);
			tempArr[tPos++] = nums[rPos++];
		}
	}
	// 其中一个数组用完之后，将另一个数组直接加到tempArr末尾
	while (lPos <= center) {
		tempArr[tPos++] = nums[lPos++];
	}
	while (rPos <= right) {
		tempArr[tPos++] = nums[rPos++];
	}
	//// 将结果并到tempArr之后拷贝到原数组的相应部分
	for (int i = left; i <= right; i++) {
		nums[i] = tempArr[i];
	}
}
// 分治法的函数
void Msort(int left, int right, int* nums, int* tempArr, int* ret) {
	// 递归的终止条件
	if (left >= right) { return; }
	else {
		int center = left + (right - left) / 2;
		Msort(left, center, nums, tempArr, ret);
		Msort(center + 1, right, nums, tempArr, ret);
		// 调用合函数
		Merge(left, center, right, nums, tempArr, ret);
	}
}

int reversePairs(int* nums, int numsSize) {
	int* ret = (int*)calloc(1, sizeof(int));
	int* tempArr = (int*)calloc(numsSize, sizeof(int));
	Msort(0, numsSize - 1, nums, tempArr, ret);
	return *ret;
}

int lengthOfLongestSubstring(char* s) 
{
	int res = 0;
	int len = strlen(s);
	if (len == 1) {
		return 1;
	}
	for (int i = 0; i < len - 1; i++) {
		int temp_res = 1;
		for (int j = i + 1; j < len; j++) {
			int flag = 0;
			for (int k = i; k <= j - 1; k++) {
				if (s[k] == s[j]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				temp_res++;
			} else {
				break;
			}
		}
		res = max(temp_res, res);
		if (len - i <= res) {
			break;
		}
	}
	return res;
}

int lengthOfLongestSubstring_simple(char* s)
{
	int* temp = (int *)malloc(sizeof(int) * 256);
	memset(temp, 0, sizeof(int) * 256);
	int res = 0;
	int len = strlen(s);
	if (len == 1) {
		return 1;
	}
	for (int i = 0; i < len - 1; i++) {
		int temp_res = 0;
		for (int j = i; j < len; j++) {
			if (temp[s[j]]) {
				break;
			} else {
				temp[s[j]]++;
				temp_res++;
			}
		}
		res = max(temp_res, res);
		memset(temp, 0, sizeof(int) * 256);
		if (len - i <= res) {
			break;
		}
	}
	free(temp);
	return res;
}

int mySqrt(int x) 
{
	int res = 0;
	long left = 1;
	long right = x;
	long mid = (left + right) / 2;
	while (left < right) {
		if (x > mid * mid) {
			left = mid + 1;
		} else if (x == mid * mid) {
			res = mid;
			return res;
		} else {
			right = mid - 1 ;
		}
		mid = (left + right) / 2;
	}
	res = mid * mid > x ? mid - 1 : mid;
	return res;
}