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
extern void structDemo();
extern void getcharAndputchar();
extern void getsAndputs();

int main() {
	getsAndputs();
	return 0;
}
