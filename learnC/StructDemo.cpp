#include<stdio.h>
#include<string.h>

void structDemo() 
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
	printf("%s的年龄为：%d", stu.name, stu.age);
	Book book;
	strcpy_s(book.author, "莫言");
	book.price = 25.0;
	printf("%s的书要%f元", book.author, book.price);
	return;
}