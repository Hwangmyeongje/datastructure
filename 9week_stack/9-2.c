#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
	int top;
	char* data;
}stack;

void init(stack* s)
{
	s->top = -1;
}

void push(stack* s, char str)
{
	s->top++;
	s->data[s->top] = str;
	
}

void pop(stack* s)
{
	s->top--;
}

void check(stack* s, char* str)
{
	int cnt = 0, dist = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			push(s, str[i]);
			cnt++;
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			cnt++;
			char temp = '\n';
			if (s->data[s->top] == '(')
				temp = ')';
			else if (s->data[s->top] == '{')
				temp = '}';
			else if (s->data[s->top] == '[')
				temp = ']';

			if (temp == str[i])
			{
				pop(s);
			}
			else if (temp != str[i])
				dist = 1;
		}
	}
	if (dist == 0 && s->top == -1)
		printf("OK_%d", cnt);
	else if (dist == 1)
		printf("Wrong_%d", cnt);
	else if (dist == 0 && s->top != -1)
		printf("Wrong_%d", cnt);

}

void print(stack *s)
{
	for(int i = s->top; i >= 0; i--)
	{
		printf("%c", s->data[i]);
	}
	printf("\n");
}

int main()
{
	char str[1001];
	gets(str);
	stack S;
	S.data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	init(&S);
	check(&S, &str);


	
	//print(&S);
	
	return 0;
}