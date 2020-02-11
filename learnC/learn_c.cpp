#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "learn_c.h"

void EnumDemo() 
{
	enum color {
		RED = 1, GREEN, BLUE
	};
	enum color your_color;
	int a = 0;
	do {
		a = 0;
		printf("��������ѡ�����ɫ(1.red, 2.green, 3.blue):");
		scanf_s("%d", &your_color);
		switch (your_color) {
		case RED:
			printf("��ѡ�����ɫ�Ǻ�ɫ");
			break;
		case GREEN:
			printf("��ѡ�����ɫ����ɫ");
			break;
		case BLUE:
			printf("��ѡ�����ɫ����ɫ");
			break;
		default:
			printf("��ѡ����ȷ����ɫ\n");
			a = 1;
			break;
		}
	} while (a == 1);
}

void WritefileDemo()
{
	FILE* fp = NULL;
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "a+");
	fprintf(fp, "\nʹ��fprintfд���ļ�");
	fputs("\nʹ��fputsд���ļ�", fp);
	fclose(fp);
}

void ReadfileDemo()
{
	FILE* fp = NULL;
	char buffer[255];
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "r");

	int res = fscanf(fp, "%s", buffer);
	printf("1:%s\n", buffer);

	fgets(buffer, 255, fp);
	printf("2:%s\n", buffer);

	fgets(buffer, 255, fp);
	printf("3:%s\n", buffer);

	fclose(fp);
}

int FindGcd(int n1, int n2)
{
	int gcd = 1;
	for (int i = 1; i <= n1 && i <= n2; i++) {
		if ((n1 % i == 0) && (n2 % i == 0)) {
			gcd = i;
		}
	}
	return gcd;
}

void FlipString()
{
	char c;
	(void)scanf("%c", &c);
	if (c != '\n') {
		FlipString();
		printf("%c", c);
	}
	return;
}

void GetcharAndputchar()
{
	int c;
	printf("������һ��ֵ��");
	c = getchar();
	printf("%d", c);
	putchar(c);
}

void GetsAndputs() {
	char str[50];
	printf("�������ַ�����");
	gets_s(str);
	printf("\n %s", str);
}

void PrintMultiplicationTable()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d * %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}
}

int PalindromicNumber(int originalInteger)
{
	int remainde;
	int reversedInteger = 0;
	int n = originalInteger;
	while (n != 0) {
		remainde = n % 10;
		reversedInteger = reversedInteger * 10 + remainde;
		n /= 10;
	}
	if (originalInteger == reversedInteger) {
		return 0;
	}
	else {
		return 1;
	}
}

void PointerDemo() {
	int  var[] = { 10, 100, 200 };
	int  i, * ptr;

	/* ָ�������һ��Ԫ�صĵ�ַ */
	ptr = &var[3 - 1];
	for (i = 3; i > 0; i--)
	{
		printf("�洢��ַ��var[%d] = %p\n", i - 1, ptr);
		printf("�洢ֵ��var[%d] = %d\n", i - 1, *ptr);
		/* �ƶ�����һ��λ�� */
		ptr--;
	}
}

/*��׳�*/
double Factorial(unsigned int i)
{
	if (i <= 1)
	{
		return 1;
	}
	return i * Factorial(i - 1);
}

/*쳲���������*/
int Fibonaci(int i)
{
	if (i == 0)
	{
		return 0;
	}
	if (i == 1)
	{
		return 1;
	}
	return Fibonaci(i - 1) + Fibonaci(i - 2);
}

void BubbleSort(int arr[], int len)
{
	if (arr[0] != NULL)
	{
		int i, j, temp;
		for (i = 0; i < len - 1; i++)
		{
			for (j = 0; j < len - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}

void StringDemo() {
	char str[] = { 'A', 'B', '\0' };
	printf("%s", str);
	printf("%d", strlen(str));
}

void StructDemo()
{
	typedef struct Book
	{
		char author[20];
		double price;
	}Book;
	typedef struct Stu
	{
		char name[20];
		int age;
	}Stu;
	Stu stu;
	stu.age = 21;
	strcpy_s(stu.name, "aaa");
	printf("%s������Ϊ��%d", stu.name, stu.age);
	Book book;
	strcpy_s(book.author, "Ī��");
	book.price = 25.0;
	printf("%s����Ҫ%fԪ", book.author, book.price);
	return;
}