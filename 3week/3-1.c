/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum(int n)
{
	if (n <= 0)
		return 0;
	return n + sum(n - 1);
	
}

int main()
{
	int n;
	scanf("%d", &n);
	int k = sum(n);
	printf("%d", k);
	return 0;
}
*/