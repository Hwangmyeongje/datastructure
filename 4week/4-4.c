/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int n, m,x[100][100];
	scanf("%d %d", &n, &m);
	int num = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j] = 0;
		}
	}
	int a = 0, b = 0,i=0,j=0;
	x[i][j] = 1;
	while (num <= n*m)
	{
		while (j + 1 < m && x[i][j+1] ==0)
		{
			j++;
			x[i][j] = num++;
		}
		while (i + 1 < n && x[i + 1][j] == 0)
		{
			i++;
			x[i][j] = num++;
		}
		while (j - 1 >= 0 && x[i][j - 1] == 0)
		{
			j--;
			x[i][j] = num++;
		}
		while(i-1>=0&&x[i-1][j]==0)
		{
			i--;
			x[i][j] = num++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	}

}
*/