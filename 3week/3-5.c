#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int rHanoi(int n,char from , char temp, char to)
{
	if (n == 1)
		printf("%c %c\n", from, to);
	else
	{
		rHanoi(n - 1, from, to, temp); //tmp·Î º¸³»
		printf("%c %c\n", from, to);
		rHanoi(n - 1, temp, from, to);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	rHanoi(n, 'A', 'B', 'C');
	return 0;
}