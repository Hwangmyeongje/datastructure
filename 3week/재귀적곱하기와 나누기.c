/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int rProd(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a + rProd(a, b - 1);
}

int rMod(int a, int b)
{
	if (a < b)
		return a; //�̶� a�� ������
	else
		return rMod(a - b,b);
}

//���ϱ� ������ ���ϴ°�, ������ ������ ���°�

int rDiv(int a, int b)
{
	if (a < b)
		return 0;
	else
		return 1+ rDiv(a - b, b);
}
//���� ���� Ƚ���� ���ϸ� ��
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("rProd = %d\n", rProd(a, b));
	printf("rMod = %d\n", rMod(a, b));
	printf("rDiv = %d", rDiv(a, b));
	return 0;
}
*/