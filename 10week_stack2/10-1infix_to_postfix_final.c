#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int top;

int isEmpty(char *stack)
{
	return top == -1;
}

void push(char* stack, char el)
{
	top++;
	stack[top] = el;
}

char pop(char* stack)
{
	if (stack[top] == 'p')
		stack[top] ='+';
	else if (stack[top] == 'm')
		stack[top] = '-';
	return (stack[top--]);
}

int prec(char op)
{
	if (op == '|')
		return 1;
	else if (op == '&')
		return 2;
	else if (op == '<' || op == '>')
		return 3;
	else if (op == '+' || op == '-')
	{
		return 4;
	}
	else if (op == '*' || op == '/')
		return 5;
	else if (op == '!' || op =='p' || op== 'm')
		return 6;
	else return 0;
}

void convert(char *str)
{
	char stack[101] = { NULL };
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
			push(stack, str[i]);
		else if (str[i] == ')')
		{
			while (stack[top] != '(')
				printf("%c", pop(stack));
			pop(stack);
		}
		else if (prec(str[i]) == 0)
			printf("%c", str[i]);
		else if (prec(str[i]) > 0)
		{
			if (str[i] == '+' || str[i] == '-')
				if (i == 0 || (prec(str[i - 1]) != 0))
					str[i] = (str[i] == '+') ? 'p' : 'm';
			while (!isEmpty(stack) && prec(str[i]) <= prec(stack[top]))
				printf("%c", pop(stack));
			if (str[i] == '&' || str[i] == '|')
			{
				push(stack, str[i]);
				i++;
			}
			push(stack, str[i]);
		}
	}
	while (!isEmpty(stack))
		printf("%c", pop(stack));
	printf("\n");
}

int main()
{	
	char str[101];
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		top = -1;
		gets(str);
		convert(str);
	}
	
	return 0;
}
/*
-A+-B+-C
*/
