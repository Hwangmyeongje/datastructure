//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//
//int rmax2(int a[], int i)
//{
//	if (i == 0)
//		return a[0];
//	else
//	{
//		int prevMax = rmax2(a, i - 1);
//		return (prevMax > a[i]) ? prevMax : a[i];
//	}
//
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a[20];
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//
//	printf("%d",rmax2(a, n-1));
//	return 0;
//}