#include<stdio.h>
#include<stdlib.h>
#include "leetcode.h"

int main()
{
	char w1[] = "acdtuyj";
	char w2[] = "tde";
	char w3[] = "agc";
	int wordsSize = 3;
	char** words = (char**)malloc(sizeof(char*) * wordsSize);
	char chars[] = "defgabc";
	words[0] = w1;
	words[1] = w2;
	words[2] = w3;

	int res = countCharacters(words, wordsSize, chars);

	free(words);

	return 0;
}