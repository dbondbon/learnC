#include<stdio.h>
#include<stdlib.h>

void enumDemo() {
	enum color
	{
		red = 1, green, blue
	};
	enum color your_color;
	int a = 0;
	do
	{
		a = 0;
		printf("请输入你选择的颜色(1.red, 2.green, 3.blue):");
		scanf_s("%d", &your_color);
		switch (your_color)
		{
		case red:
			printf("你选择的颜色是红色");
			break;
		case green:
			printf("你选择的颜色是绿色");
			break;
		case blue:
			printf("你选择的颜色是蓝色");
			break;
		default:
			printf("请选择正确的颜色\n");
			a = 1;
			break;
		}
	} while (a == 1);
}