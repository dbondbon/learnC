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
extern void pointerDemo();
extern void stringDemo();
int main() {
	stringDemo();
	return 0;
}
