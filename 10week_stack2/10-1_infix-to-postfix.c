//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int pm;
//
//typedef struct stack
//{
//	int top;
//	char data[100];
//}stack;
//
//void init(stack* s) { s->top = -1; }
//
//int isEmpty(stack* s) { return  s->top == -1; }
//
//int isFull(stack* s) { return s->top == 100; }
//
//void push(stack* s, char ch)
//{
//	s->top++;
//	s->data[s->top] = ch;
//}
//
//char pop(stack* s)
//{
//	return (s->data[s->top--]);
//}
//
//int beforeopercheck(char op)
//{
//	if (op == '(' || op == '|' || op == '&' || op == '>' || op == '<' || op == '*' || op == '/' || op == '!' || op == '+' || op == '-')
//		return 1;
//	else if (op == '?')
//		return 2;
//	else
//		return 3;
//}
//
//
//int prec(char op)
//{
//	if (op == '|')
//		return 1;
//	else if (op == '&')
//		return 2;
//	else if (op == '>' || op == '<') return 3;
//	else if (op == '*' || op == '/') return 5;
//	else if (op == '!') return 6;
//	else if (op == '+' || op == '-')
//	{
//		if (pm == 1)
//			return 6;
//		else
//			return 4;
//	}
//	else return -1;
//	
//}
//
//void infix_to_postfix(char *str)
//{
//	char c, t,k;
//	stack S;
//	init(&S);
//	char beforeoper = '?';
//	for (int i = 0; i < strlen(str); i++)
//	{
//		pm = 0;
//		if(i>0)
//			beforeoper = str[i - 1];
//		c = str[i];
//		if (c == '&' || c == '|')
//		{
//			c = str[i+1];
//			i++;
//		}switch (c)
//		{
//		case '(':
//			push(&S, c); break;
//		case ')':
//			t = pop(&S);
//			while (t != '(')
//			{
//				printf("%c", t);
//				t = pop(&S);
//			}
//			break;
//		case '!': case '*': case '/': case '+': case'-':case'>': case'<':case'&': case'|':
//			if (c == '+' || c == '-')
//			{
//				if (beforeopercheck(beforeoper) == 1 || i == 0)
//					pm = 1;
//			}
//			else
//			{
//				while (!isEmpty(&S) && prec(c) <= prec(S.data[S.top]))
//					printf("%c", pop(&S));
//			}
//			if (c == '&' || c == '|')
//				push(&S, c);
//			push(&S, c);
//
//			break;
//		default:
//			printf("%c", c);
//			break;
//		}
//	}
//	while (!isEmpty(&S))
//		printf("%c", pop(&S));
//	printf("\n");
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char str[101];
//	for (int i = 0; i < n; i++)
//	{
//		getchar();
//		scanf("%s", str);
//		infix_to_postfix(str);
//	}
//	return 0;
//}