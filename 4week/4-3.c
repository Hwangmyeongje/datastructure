/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int x[100][100];
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < n; j++)
			{
				x[i][j] = cnt++;
			}
		else
			for (int j = n-1; j >= 0; j--)
				x[i][j] = cnt++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	}

	return 0;


}
*/