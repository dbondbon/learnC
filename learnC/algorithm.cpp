#include <math.h>
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