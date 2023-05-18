#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct deqNode
{
	int data;
	struct deqNode* next;
	struct deqNode* prev;
}deqNode;

typedef struct
{
	deqNode* front;
	deqNode* rear;
}deq;

void init(deq* d)
{
	d->front = d->rear = NULL;
}

int isEmpty(deq* d)
{
	return d->front == NULL;
}

void add_front(deq* d, int elem)
{
	deqNode* node = (deqNode*)malloc(sizeof(deqNode));
	node->data = elem;
	node->prev = node->next = NULL;
	if (isEmpty(d))
		d->front = d->rear = node;
	else
	{
		node->next = d->front;
		d->front->prev = node;
		d->front = node;
	}
}

void add_rear(deq* d, int elem)
{
	deqNode* node = (deqNode*)malloc(sizeof(deqNode));
	node->data = elem;
	node->prev = node->next = NULL;
	if (isEmpty(d))
		d->front = d->rear = node;
	else
	{
		node->prev = d->rear;
		d->rear->next = node;
		d->rear = node;
	}
}

int delete_front(deq* d)
{
	if (isEmpty(d))
	{
		printf("underflow");
		exit(0);
	}
	int delElem = d->front->data;

	deqNode* node = d->front;
	d->front = node->next;
	if (d->front == NULL)
		d->rear = NULL;
	else
		d->front->prev = NULL;
	free(node);
	return delElem;
}

int delete_rear(deq* d)
{
	if (isEmpty(d))
	{
		printf("underflow");
		exit(0);
	}
	int delElem = d->rear->data;

	deqNode* node = d->rear;
	d->rear = node->prev;
	if (d->rear != NULL)
		d->rear->next = NULL;
	if (d->rear == NULL)
		d->front = NULL;
	free(node);
	return delElem;
}

void print(deq* d)
{
	deqNode* node;
	if (!isEmpty(d))
	{
		for (node = d->front; node != NULL; node = node->next)
			printf(" %d", node->data);
		printf("\n");
	}
}

int main()
{
	deq d;
	init(&d);
	int n, elem;
	char oper[3];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%s", oper);
		if (strcmp(oper, "AF") == 0)
		{
			scanf("%d", &elem);
			add_front(&d, elem);
		}
		else if (strcmp(oper, "AR") == 0)
		{
			scanf("%d", &elem);
			add_rear(&d, elem);
		}
		else if (strcmp(oper, "DF") == 0)
		{
			delete_front(&d);
		
		}
		else if (strcmp(oper, "DR") == 0)
		{
			delete_rear(&d);
		}
		else if (strcmp(oper, "P") == 0)
		{
			print(&d);
		}
	}
	return 0;
}
/*
15
AF 10
AF 20
AF 30
AR 40
AR 50
P
DF
DF
DR
P
DF
DR
DR
*/