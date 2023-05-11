//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef char element;
//
//typedef struct StackNode
//{
//	element data;
//	struct StackNode* next;
//}StackNode;
//
//typedef struct
//{
//	StackNode* top;
//	int size;
//}StackType;
//
//void init(StackType* S)
//{
//	S->top = NULL;
//	S->size = 0;
//}
//
//int isEmpty(StackType *S)
//{
//	return S->top == NULL;
//}
//
//void push(StackType* S, element e)
//{
//	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
//	node->data = e;
//	node->next = S->top;
//	S->top = node;
//	S->size++;
//}
//
//element pop(StackType* S)
//{
//	if (isEmpty(S))
//	{
//		printf("Empty\n");
//		return -1;
//	}
//	StackNode* p = S->top;
//	element e = p->data;
//	S->top = p->next;
//	free(p);
//	S->size--;
//	return e;
//}
//
//element peek(StackType* S)
//{
//	if (isEmpty(S))
//	{
//		printf("Empty");
//		return -1;
//	}
//	return S->top->data;
//}
//
//void print(StackType* S)
//{
//	StackNode* p = S->top;
//	for (p = S->top; p != NULL; p= p->next)
//		printf("%c -> ", p->data);
//	printf("\n");
//		
//}
//
//int main()
//{
//	StackType S;
//	init(&S);
//	pop(&S);
//	push(&S, 's');
//	push(&S, 't');
//	push(&S, 'a');
//	push(&S, 'r');
//	print(&S);
//	printf("%c\n", pop(&S));
//	print(&S);
//
//	return 0;
//}
