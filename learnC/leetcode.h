/**
 * LeetcodeÃ‚
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include "algorithm.h"

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize);
char *compressString(char *S);
int countCharacters(char **words, int wordsSize, char *chars);
int countCharacters_simplify(char **words, int wordsSize, char *chars);
bool isRectangleOverlap(int *rec1, int rec1Size, int *rec2, int rec2Size);
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);
int longestPalindrome(char *s);
int *getLeastNumbers(int *arr, int arrSize, int k, int *returnSize);
bool canMeasureWater(int x, int y, int z);
int minIncrementForUnique(int *A, int ASize);
int minIncrementForUnique_my(int* A, int ASize);
struct ListNode* middleNode(ListNode* head);
#endif
