#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int q_size;

typedef struct queue
{
	int * data;
	int front;
	int rear;
}queue;

void init(queue* q)
{
	q->front = 0;
	q->rear = 0;
	for (int i = 0; i < q_size; i++)
		q->data[i] = 0;
}

int isEmpty(queue* q)
{
	return q->front == q->rear;
}

int isFull(queue* q)
{
	return q->front == (q->rear + 1) % q_size;
}

void Print(queue* q)
{
	for (int i = 0; i < q_size; i++)
		printf(" %d", q->data[i]);
	printf("\n");
}

void enqueue(queue* q, int elem)
{
	if (isFull(q))
	{
		printf("overflow");
		Print(q);
		exit(0);
	}
	q->rear = (q->rear + 1) % q_size;
	q->data[q->rear] = elem;
}

void dequeue(queue* q)
{
	if (isEmpty(q))
	{
		printf("underflow");
		exit(0); //보통 에러가 없는 경우는 0으로 삭제
	}
	q->front = (q->front + 1) % q_size;
	q->data[q->front] = 0;
	
}



int main()
{
	int n, elem;
	scanf("%d", &q_size);
	queue q;
	q.data = (int*)malloc(sizeof(int) * q_size);
	init(&q);
	scanf("%d", &n);
	char oper;
	for (int i = 0; i < n; i++)
	{
		getchar();

		scanf("%c", &oper);
		if (oper == 'I')
		{
			scanf("%d", &elem);
			enqueue(&q, elem);
		}
		else if (oper == 'D')
		{
			dequeue(&q);
		}
		else if (oper == 'P')
		{
			Print(&q);
		}
		
	}
	free(q.data);
	return 0;
}
/*
6
10
I 10
I 20
P
I 30
I 40
D
P
I 50
I 60
I 70
*/