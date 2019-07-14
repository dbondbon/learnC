#include<stdio.h>

void fileDemo()
{
	FILE* fp = NULL;
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "a+");
	fprintf(fp, "\n使用fprintf写入文件");
	fputs("\n使用fputs写入文件", fp);
	fclose(fp);
	return;
}