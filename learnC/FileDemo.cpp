#include<stdio.h>

void fileDemo()
{
	FILE* fp = NULL;
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "a+");
	fprintf(fp, "\nʹ��fprintfд���ļ�");
	fputs("\nʹ��fputsд���ļ�", fp);
	fclose(fp);
	return;
}