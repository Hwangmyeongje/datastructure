/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//반복문 이용
int ipower(int x, int n)
{
	int r = 1;
	for (int i = 1; i <= n; i++)
		r *= x;
	return r;
}

int rpower(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return rpower(x * x, n / 2);
	else
		return x * rpower(x * x, (n - 1) / 2);
}

int main()
{
	int x, n;
	scanf("%d %d", &x, &n);
	printf("%d\n", ipower(x, n));
	printf("%d", rpower(x, n));

	return 0;
}
*/