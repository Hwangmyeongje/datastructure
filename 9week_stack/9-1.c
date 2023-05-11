#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct stack
{
	int top;
	char* data;
}stack;

void init(stack *s)
{
	s->top = -1;
}

int isEmpty(stack *s)
{
	return s->top == -1;
}


void push(stack* s, char elem)
{
	s->top++;
	s->data[s->top] = elem;
}

void pop(stack* s)
{
	if (isEmpty(s))
	{
		printf("Stack Empty\n");
	}
	else
		s->top--;
}

char peek(stack* s)
{
	if (isEmpty(s))
	{
		printf("Stack Empty\n");
		return -1;
	}
	return s->data[s->top];

}

void duplicate(stack* s)
{
	char elem = peek(s);
	if (elem != -1)
		push(s,elem);
}

void upRotate(stack* s, int n)
{
	int t = s->top;
	if (n <= t + 1)
	{
		char temp = s->data[t];
		for (int i = 0; i < n-1; i++)
		{
			s->data[t - i] = s->data[t-i - 1];
		}
		s->data[t - n + 1] = temp;
	}
}

void downRotate(stack* s, int n)
{
	int t = s->top;
	if (n <= t + 1)
	{
		char temp = s->data[t - n+1];
		for (int i = 0; i < n-1; i++)
		{
			s->data[t - n +i+1] = s->data[t -n+i+2];
		}
		s->data[s->top] = temp;
	}
}

void print(stack *s)
{
	for (int i = s->top; i >= 0; i--)
		printf("%c", s->data[i]);
	printf("\n");
}

int main() {
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	stack S;
	S.data = (char*)malloc(sizeof(char) * (N + 1));
	char oper[10], el;
	int rot;
	init(&S);
	for (int i = 0; i < M; i++)
	{
		scanf("%s", oper);
		getchar();
		if (strcmp(oper, "POP") == 0)
		{
			pop(&S);
		}
		else if (strcmp(oper, "PUSH") == 0)
		{
			scanf("%c", &el);
			if (S.top == N - 1)
				printf("Stack FULL\n");
			else
				push(&S, el);
		}
		else if (strcmp(oper, "PRINT") == 0)
			print(&S);
		else if (strcmp(oper, "PEEK") == 0)
			printf("%c\n", peek(&S));
		else if (strcmp(oper, "DUP") == 0)
		{
			if (S.top == N - 1)
				printf("Stack FULL\n");
			else
				duplicate(&S);
		}
		else if (strcmp(oper, "UpR") == 0)
		{
			scanf("%d", &rot);
			upRotate(&S, rot);
		}
		else if (strcmp(oper, "DownR") == 0)
		{
			scanf("%d", &rot);
			downRotate(&S, rot);
		}

		
	}
	
	return 0;
}
/*
4 
10 
POP 
PUSH s 
PUSH t 
PUSH a 
PUSH r 
PRINT 
UpR 3 
PRINT 
PUSH s 
PEEK 
*/
/*
5 
11
PUSH s 
PUSH r 
PUSH a
PUSH t
PUSH s 
PRINT 
DownR 4 
PRINT 
POP 
POP 
PRINT 
*/
/*
6
7
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
DownR 3
PRINT
*/