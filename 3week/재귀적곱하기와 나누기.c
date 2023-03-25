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
		return a; //이때 a가 나머지
	else
		return rMod(a - b,b);
}

//곱하기 연산은 더하는거, 나누기 연산은 빼는거

int rDiv(int a, int b)
{
	if (a < b)
		return 0;
	else
		return 1+ rDiv(a - b, b);
}
//몫은 빼는 횟수를 더하면 됨
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