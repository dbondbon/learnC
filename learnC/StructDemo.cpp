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
	printf("%s������Ϊ��%d", stu.name, stu.age);
	Book book;
	strcpy_s(book.author, "Ī��");
	book.price = 25.0;
	printf("%s����Ҫ%fԪ", book.author, book.price);
	return;
}