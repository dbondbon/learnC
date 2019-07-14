#include<stdio.h>
#include "global.h"

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

int main() {
	readfileDemo();
	printf("%s %s", __DATE__, __TIME__);
	return 0;
}
