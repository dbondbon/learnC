#include<stdio.h>
#include<string.h>

void structDemo() 
{
	struct Stu
	{
		char name[20];
		int age;
	}stu;	
	stu.age = 21;
	strcpy_s(stu.name, "zhangsan");
	printf("%sµÄÄêÁäÎª£º%d", stu.name, stu.age);
	return;
}