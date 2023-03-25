//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int rcntch(char str[], char c,int i)
//{
//	int  cnt = (str[i] == c) ? 1 : 0;
//	if (i == 0)
//		return;
//	else
//		return cnt +rcntch(str, c, i - 1);
//}
//
//int main()
//{
//	char str[100], c;
//	scanf("%s", str);
//	getchar();
//	scanf("%c", &c);
//
//	printf("%d", rcntch(str, c, strlen(str)-1));
//
//}