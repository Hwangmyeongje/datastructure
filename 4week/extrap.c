/*
//다항식 문제, 구조체로 하면 낭비되는 공간없이 할 수 있음
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define N 10

typedef struct
{
	int degree;
	int coef[N];
}Poly;

Poly addPoly(Poly A, Poly B)
{
	Poly C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degA = A.degree;
	int degB = B.degree;

	C.degree = (degA >= degB) ? degA : degB;
	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degA > degB)
		{
			C.coef[Cpos] = A.coef[Apos];
			Apos++; Cpos++; degA--;
		}
		else if (degA == degB)
		{
			C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
			Apos++; Bpos++; Cpos++; degA--; degB--;
		}
		else
		{
			C.coef[Cpos] = B.coef;
			Bpos++; Cpos++; degB--;
		}
	}
	return C;
}

void printPoly(Poly A)
{
	int i, j;
	for (i = 0, j = A.degree; i <= A.degree; i++,j--)
	{
		printf("%2dx^%d +", A.coef[i], j);
	}
	printf("\b\b  \n");
}



int main()
{
	Poly A, B, C;
	scanf("%d %d", &A.degree, &B.degree);
	for (int i = 0; i <= A.degree; i++)
		scanf("%d", &A.coef[i]);
	for (int i = 0; i <= B.degree; i++)
		scanf("%d", &B.coef[i]);
	
	printPoly(A);
	printPoly(B);

	C = addPoly(A, B);
	printf("=======================================\n");
	printPoly(C);
		
	return 0;
}
*/