/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int n, x[100], m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	scanf("%d", &m);
	int idx;
	scanf("%d", &idx);
	int t1, t2;
	t1 = x[idx];
	for (int i = 0; i < m-1; i++)
	{
		scanf("%d", &idx);
		t2 = x[idx];
		x[idx] = t1;
		t1 = t2;
	}

	for (int i = 0; i < n; i++)
		printf(" %d", x[i]);
	return 0;
}
*/