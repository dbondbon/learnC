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