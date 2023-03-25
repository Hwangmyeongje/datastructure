//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//int count; //피보나치 함수 몇번 불리는지
//int count2;
//int rFib(int n)
//{
//	count++;
//	if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else
//		return rFib(n - 1) + rFib(n - 2);
//}
//
//int iFib(int n)
//{
//	count2++;
//	if (n == 0) return 0;
//	if (n == 1) return 1;
//	
//	int pp = 0;
//	int p = 1;
//	int result = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		result = p + pp;
//		pp = p;
//		p = result;
//	}
//	return result;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d %d\n",count, rFib(n));
//	printf("%d %d", count2, iFib(n));
//
//	return 0;
//}