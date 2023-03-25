//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//void rHanoi(int n, char from, char tmp, char to)
//{
//	if (n == 1)
//		printf("Disk %d: Move from %c to %c. \n", n, from, to);
//	else
//	{
//		rHanoi(n - 1, from, to, tmp);
//		printf("Disk %d: Move from %c to %c. \n", n, from, to);
//		rHanoi(n - 1, tmp, from, to);
//	}
//}
//
//int main()
//{
//	rHanoi(4, 'A', 'B', 'C');
//	return 0;
//}