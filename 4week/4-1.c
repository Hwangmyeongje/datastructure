/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void reverse(int arr[], int a, int b)
{
	int cnt = 0;
	for (int i = 0; i <= (b-a)/2; i++)
	{
		int temp = arr[a+i];
		arr[a+i] = arr[b - i];
		arr[b - i] = temp;
		
	}
}


int main()
{
	int x[100];
	int n,rev,a,b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	scanf("%d", &rev);
	for (int i = 0; i < rev; i++)
	{
		scanf("%d %d", &a, &b);
		reverse(&x, a, b);
	}
	for (int i = 0; i < n; i++)
		printf(" %d", x[i]);
	return 0;
}
*/