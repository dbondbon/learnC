#include <math.h>
#include <stdlib.h>
#include "algorithm.h"
#include "data_structure_c.h"

int binary_search(int arr[], int size, int key)
{
	int m = 0;
	int n = size - 1;
	int k = floor((m + n) / 2);

	while (m != n) {
		if (arr[k] == key) {
			return k;
		} else if (arr[k] > key) {
			n = k - 1;
		} else {
			m = k + 1;
		}
		k = floor((m + n) / 2);
	}
	if (arr[m] == key) {
		return m;
	}

	return RES_FAIL;
}

typedef struct imp {
	int val = 0;
	int num = 0;
	struct imp *next;
}imp;

int majorityElement(int *nums, int numsSize) 
{
	int k = floor(numsSize / 2);
	imp first = {nums[0], 1, NULL};
	int imp_size = 1;
	int flag = 0;
	for (int i = 1; i < numsSize; i++) {
		int val = nums[i];
		imp* test = &first;
		for (int j = 0; j < imp_size; j++) {
			if (test->val == val) {
				test->num++;
				flag = 1;
				break;
			}
			if (j < imp_size - 1) {
				test = test->next;
			}
		}
		if (!flag) {
			imp* new_imp = (imp *)malloc(sizeof(imp));
			new_imp->val = val;
			new_imp->num = 1;
			new_imp->next = NULL;
			test->next = new_imp;
			imp_size++;
		}
		flag = 0;
	}
	imp* test = &first;
	int res = test->val;
	int max = test->num;
	if (imp_size == 1) {
		return res;
	}
	for (int i = 1; i < imp_size; i++) {
		test = test->next;
		if (max < test->num) {
			res = test->val;
			max = test->num;
		}
	}

	imp*  next_imp = &first;
	imp* free_space = next_imp->next;
	for (int i = 1; i < imp_size; i++) {
		next_imp = free_space->next;
		free(free_space);
		free_space = next_imp;
	}

	return res;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	ListNode* res = NULL;
	ListNode* left = l1;
	ListNode* right = l2;
	if (left == NULL) {
		return right;
	}
	if (right == NULL) {
		return left;
	}
	if (left->val <= right->val) {
		res = left;
		left = left->next;
	} else {
		res = right;
		right = right->next;
	}
	ListNode* current_res = res;
	while (left != NULL && right != NULL) {
		if (left->val <= right->val) {
			current_res->next = left;
			current_res = current_res->next;
			left = left->next;
		} else {
			current_res->next = right;
			current_res = current_res->next;
			right = right->next;
		}
	}
	if (left != NULL) {
		current_res->next = left;
	}
	if (right != NULL) {
		current_res->next = right;
	}
	return res;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) 
{
	int *res = (int *)malloc(sizeof(int) * k);
	int min_val, temp;

	for (int i = 0; i < k; i++) {
		min_val = arr[0];
		for (int j = 0; j < arrSize - i - 1; j++) {
			if (arr[j + 1] > min_val) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			} else {
				min_val = arr[j + 1];
			}
		}
		res[i] = min_val;
	}
	*returnSize = k;
	return res;
}