#include<stdio.h>
#include "global.h"

void writefileDemo()
{
	FILE *fp = NULL;
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "a+");
	fprintf(fp, "\nʹ��fprintfд���ļ�");
	fputs("\nʹ��fputsд���ļ�", fp);
	fclose(fp);
	return;
}

void readfileDemo()
{
	FILE *fp = NULL;
	char buffer[255];
	fp = fopen("G:/C-C++/learnC/fileTest.txt", "r");

	fscanf(fp, "%s", buffer);
	printf("1:%s\n", buffer);

	fgets(buffer, 255, fp);
	printf("2:%s\n", buffer);

	fgets(buffer, 255, fp);
	printf("3:%s\n", buffer);

	fclose(fp);
}