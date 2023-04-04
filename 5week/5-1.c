#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node* prev;
	char elem;
	struct node* next;
}node;

typedef struct list
{
	node* H;
	int pos; //노드의 순위
	node* T;
}list;

void init(list* A)
{
	node* ohead, * otail;
	ohead = (node*)malloc(sizeof(node));
	otail = (node*)malloc(sizeof(node));

	A->H = ohead;
	ohead->prev = NULL;
	ohead->next = otail;

	A->T = otail;
	otail->prev = ohead;
	otail->next = NULL;

	A ->pos = 1; //현재 위치를 나타내는ㄴ 변수
}

void add(list* A, int r, char e)
{
	if (r<1 || r>A->pos)
	{
		printf("invalid position\n");
		return;
	}
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->elem = e;


	node* p = A->H;
	for (int i = 1; i < r; i++)
		p = p->next;
	/*
	r=1 p = A->H

	*/
	
	newnode->prev = p;
	newnode->next = p->next;
	p->next->prev = newnode;
	p->next = newnode;
	
	A->pos++;
}

void del(list* A,int r)
{
	if (r<1 || r>A->pos-1)
	{
		printf("invalid position\n");
		return;
	}
	node* p = A->H->next;
	for (int i = 1; i < r; i++)
		p = p->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	A->pos--;
}


void get(list* A,int r)
{
	if (r<1 || r>A->pos-1)
	{
		printf("invalid position\n");
		return;
	}
	node* p = A->H;
	for (int i = 1; i <= r; i++)
		p = p->next;
	printf("%c\n", p->elem);
}

void print(list* A)
{
	node* p = A->H->next;
	while (p != A->T)
	{
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}


int main()
{
	list A;
	init(&A);
	int num, r;
	char oper, e;
	scanf("%d", &num);
	getchar();
	for(int i=0; i<num;i++)
	{
		
		scanf("%c", &oper);
		if (oper == 'A')
		{
			scanf("%d %c",&r,&e);
			getchar();
			add(&A, r, e);
		}
		else if (oper == 'D')
		{
			scanf("%d", &r);
			getchar();
			del(&A, r);

		}
		else if (oper == 'G')
		{
			scanf("%d", &r);
			getchar();
			get(&A, r);
		}
		else if (oper == 'P')
		{
			print(&A);
			getchar();
		}
	}
	free(A.H);
	free(A.T);
	return 0;
}
