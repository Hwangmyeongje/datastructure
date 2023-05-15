#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int t;

void push(int * stack, int elem)
{
	stack[++t] = elem;
}

int pop(int * stack)
{
	return stack[t--];
}


void calcul(char *str)
{
	int stack[100];
	int value, v1,v2;
	for (int i = 0; i < strlen(str); i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			value = str[i] - '0';
			push(&stack, value);
		}
		else
		{
			v2 = pop(&stack);
			v1 = pop(&stack);
			if (str[i] == '+')
				push(&stack, v1 + v2);
			else if (str[i] == '-')
				push(&stack, v1 - v2);
			else if (str[i] == '*')
				push(&stack, v1 * v2);
			else if (str[i] == '/')
				push(&stack, v1 / v2);

		}
	}
	printf("%d\n", pop(&stack));
}

int main()
{
	int n;
	scanf("%d", &n);
	char str[101];
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets(str);
		t = -1;
		calcul(str);
	}
	return 0;
}