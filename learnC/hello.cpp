#include<stdio.h>

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int main() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	int c = max(a, b);
	printf("���ֵΪ%d", c);
	return 0;
}
