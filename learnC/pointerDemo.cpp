#include<stdio.h>

void pointerDemo() {
	int  var[] = { 10, 100, 200 };
	int  i, * ptr;

	/* ָ�������һ��Ԫ�صĵ�ַ */
	ptr = &var[3 - 1];
	for (i = 3; i > 0; i--)
	{
		printf("�洢��ַ��var[%d] = %x\n", i - 1, ptr);
		printf("�洢ֵ��var[%d] = %d\n", i - 1, *ptr);
		/* �ƶ�����һ��λ�� */
		ptr--;
	}
	return ;
}

