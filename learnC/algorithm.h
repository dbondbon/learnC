#ifndef ALGORITHM_H
#define ALGORITHM_H

int binary_search(int arr[], int size, int key);
int majorityElement(int *nums, int numsSize);

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize);

#endif
