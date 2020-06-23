#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include "learn_c.h"

void enum_demo() 
{
	enum color {
		RED = 1, GREEN, BLUE
	};
	enum color your_color;
	int a = 0;
	do {
		a = 0;
		printf("请输入你选择的颜色(1.red, 2.green, 3.blue):");
		scanf_s("%d", &your_color);
		switch (your_color) {
		case RED:
			printf("你选择的颜色是红色");
			break;
		case GREEN:
			printf("你选择的颜色是绿色");
			break;
		case BLUE:
			printf("你选择的颜色是蓝色");
			break;
		default:
			printf("请选择正确的颜色\n");
			a = 1;
			break;
		}
	} while (a == 1);
}

void writefile_demo()
{
	FILE* fp = NULL;
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "a+");
	fprintf(fp, "\n使用fprintf写入文件");
	fputs("\n使用fputs写入文件", fp);
	fclose(fp);
}

void readfile_demo()
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

int find_gcd(int n1, int n2)
{
	int gcd = 1;
	for (int i = 1; i <= n1 && i <= n2; i++) {
		if ((n1 % i == 0) && (n2 % i == 0)) {
			gcd = i;
		}
	}
	return gcd;
}

void flip_string()
{
	char c;
	(void)scanf("%c", &c);
	if (c != '\n') {
		flip_string();
		printf("%c", c);
	}
	return;
}

void getchar_and_putchar()
{
	int c;
	printf("请输入一个值：");
	c = getchar();
	printf("%d", c);
	putchar(c);
}

void gets_and_puts() {
	char str[50];
	printf("请输入字符串：");
	gets_s(str);
	printf("\n %s", str);
}

void print_multiplication_table()
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

int palindromic_number(int originalInteger)
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

void pointer_demo() {
	int  var[] = { 10, 100, 200 };
	int  i, * ptr;

	/* 指针中最后一个元素的地址 */
	ptr = &var[3 - 1];
	for (i = 3; i > 0; i--)
	{
		printf("存储地址：var[%d] = %p\n", i - 1, ptr);
		printf("存储值：var[%d] = %d\n", i - 1, *ptr);
		/* 移动到下一个位置 */
		ptr--;
	}
}

/* 求阶乘 */
double factorial(unsigned int i)
{
	if (i <= 1)
	{
		return 1;
	}
	return i * factorial(i - 1);
}

/* 斐波那契数列 */
int fibonaci(int i)
{
	if (i == 0)
	{
		return 0;
	}
	if (i == 1)
	{
		return 1;
	}
	return fibonaci(i - 1) + fibonaci(i - 2);
}

void bubble_sort(int arr[], int len)
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

void string_demo() {
	char str[] = { 'A', 'B', '\0' };
	printf("%s", str);
	printf("%d", (int)strlen(str));
}

void struct_demo()
{
	typedef struct book_s
	{
		char author[20];
		double price;
	}book_s;
	typedef struct stu_s
	{
		char name[20];
		int age;
	}stu_s;
	stu_s stu;
	stu.age = 21;
	strcpy_s(stu.name, "aaa");
	printf("%s的年龄为：%d", stu.name, stu.age);
	book_s book;
	strcpy_s(book.author, "莫言");
	book.price = 25.0;
	printf("%s的书要%f元", book.author, book.price);
	return;
}

/* C语言程序设计精髓 Demo */
void demo()
{
	// 避免相加数值溢出
	int low = 0;
	int high = 1;
	int mid = low + (high - low) / 2;

	// 随机数
	srand(time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;

	// 缓冲区溢出攻击示例
	char password[8] = "secret";
	char input[8];
	while (1) {
		printf("Please enter you password:");
		(void)scanf("%s", input);
		if (strcmp(password, input) == 0) {
			printf("Welcome!\n");
			break;
		} else {
			printf("Sorry!\n");
		}
	}
}

void guess_game()
{
	printf("**********独家定制猜数游戏！**********\n");
	while (true) {
		int min_number = -1;
		int max_number = -1;
		int total_times = -1;
		int key_number = -1;
		int try_number = -1;
		int flag = 0;
		printf("开始玩游戏吧，先确定猜数的范围！\n");
		printf("依次输入最小数和最大数，用空格隔开：");
		scanf("%d", &min_number);
		scanf("%d", &max_number);
		while (min_number < 0 || max_number < 0 || min_number > max_number) {
			printf("输入的有问题，重新输入一次试试：");
			scanf("%d", &min_number);
			scanf("%d", &max_number);
		}
		srand(time(NULL));
		key_number = rand() % (max_number - min_number + 1) + min_number;
		printf("猜数范围确定了，根据猜数范围已经生成了一个数，接下来确定一下猜的机会吧，输入一个机会数：");
		scanf("%d", &total_times);
		while (total_times <= 0) {
			printf("机会数都能输错，重新再输：");
			scanf("%d", &total_times);
		}
		printf("好了，参数范围[%d,%d]，总尝试次数%d，开始输入数字进行猜数吧!\n", min_number, max_number, total_times);
		printf("猜个数字：");
		while (key_number != try_number) {
			scanf("%d", &try_number);
			while (try_number <= 0) {
				printf("输的数字有问题，重新再输：");
				scanf("%d", &try_number);
			}
			if (try_number == 520) {
				printf("我也爱你呀！告诉你答案吧，数字是%d，算你猜对了！\n\n", key_number);
				break;
			}
			if (key_number != try_number) {
				if (total_times == 1) {
					printf("Game over，没机会啦，真笨！\n\n");
					break;
				} else {
					printf("输的不对，你还剩%d次机会，再试试：", --total_times);
				}
			} else {
				printf("恭喜你猜对了，运气真好，数字是%d！\n\n", key_number);
				break;
			}
		}
		printf("还想再玩一次么？再玩一次输入1，退出输入2:");
		scanf("%d", &flag);
		while (flag != 1 && flag != 2) {
			if (flag == 520) {
				printf("我也爱你呀！告诉你答案吧，数字是%d，算你猜对了！\n\n", key_number);
				flag = 2;
				break;
			}
			printf("只能输1和2，重新再输：");
			scanf("%d", &flag);
		}
		if (flag == 2) {
			exit(0);
		}
		printf("--------------------------------------\n");
	}
}