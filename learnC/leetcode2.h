#ifndef LEETCODE2_H
#define LEETCODE2_H

#include "algorithm.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

typedef struct _tweet {
	int tweet_id;
	int post_time;
}tweet;
typedef struct _user {
	int user_tweets_size;
	tweet user_tweets[10000];
	int user_friends_size;
	int user_friends[10000];
}user; 
typedef struct {
	long twitter_tweet_size;
	int flag_user[10000] = { 0 };
	user users[10000];
} Twitter;

typedef struct _TreeNode {
	int val;
	struct _TreeNode* left;
	struct _TreeNode* right;
}TreeNode;

Twitter* twitterCreate();
void twitterPostTweet(Twitter* obj, int userId, int tweetId);
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize);
void twitterFollow(Twitter* obj, int followerId, int followeeId);
void twitterUnfollow(Twitter* obj, int followerId, int followeeId);
void twitterFree(Twitter* obj);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes);
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
bool canJump(int* nums, int numsSize);
int maxArea(int* height, int heightSize);
int getMaxRepetitions(char* s1, int n1, char* s2, int n2);
int numIslands(char** grid, int gridSize, int* gridColSize);
int numberOfSubarrays(int* nums, int numsSize, int k);
int* rightSideView(TreeNode* root, int* returnSize);
int waysToChange(int n);
int reversePairs(int* nums, int numsSize);
int lengthOfLongestSubstring(char* s);
int lengthOfLongestSubstring_simple(char* s);
int mySqrt(int x);
bool validPalindrome(char* s);
int findTheLongestSubstring(char* s);
int findTheLongestSubstring_simple(char* s);
TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize); // Ã‚∫≈ 105


void free_tree(TreeNode *tree_root);

int findDuplicate(int* nums, int numsSize);
int *spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
bool isValid(char* s);
int climbStairs(int n);
char* longestCommonPrefix(char** strs, int strsSize);
bool patternMatching(char* pattern, char* value);
char* addBinary(char* a, char* b);
ListNode* removeDuplicateNodes(ListNode* head);

#endif
