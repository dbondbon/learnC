#include<stdio.h>

/*��׳�*/
double factorial(unsigned int i)
{
	if (i <= 1)
	{
		return 1;
	}
	return i * factorial(i - 1);
}

/*쳲���������*/
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
