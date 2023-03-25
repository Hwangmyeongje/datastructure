/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int n, m, x[100][100],i,j;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j] = 0;
		}
	}
	int num = 1;
	x[0][0] = 1;
	int point_j = 0, point_i = 0;
	
	while (point_j + 1 < m)
	{
		point_j++;
		num++;
		i = point_i;
		j = point_j;
		x[i][j] = num;
		while (i + 1 < n && j - 1 >= 0)
		{
			num++;
			x[i + 1][j - 1] = num;
			i++; j--;
		}
	}
	while (point_i + 1 < n)
	{
		point_i++; num++;
		i = point_i; j = point_j;
		x[i][j] = num;
		while (i + 1 < n && j - 1 >= 0)
		{
			num++;
			x[i + 1][j - 1] = num;
			i++; j--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	}

	return 0;
}
*/