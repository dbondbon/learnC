#include<stdio.h>

int max() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

extern void enumDemo();
int main() {
	enumDemo();
	return 0;
}
