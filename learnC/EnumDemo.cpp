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
		printf("��������ѡ�����ɫ(1.red, 2.green, 3.blue):");
		scanf_s("%d", &your_color);
		switch (your_color)
		{
		case red:
			printf("��ѡ�����ɫ�Ǻ�ɫ");
			break;
		case green:
			printf("��ѡ�����ɫ����ɫ");
			break;
		case blue:
			printf("��ѡ�����ɫ����ɫ");
			break;
		default:
			printf("��ѡ����ȷ����ɫ\n");
			a = 1;
			break;
		}
	} while (a == 1);
}