//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//
//typedef struct List
//{
//	int size;
//	struct Node* Head;
//}List;
//
//
//void init(List *L)
//{
//	L->Head = NULL;
//	L->size = 0;
//}
//
//void insert(List* L, int elem)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->next = NULL;
//	newNode->data = elem;
//	Node* p = L->Head;
//	if (p == NULL)
//		L->Head = newNode;
//	else {
//		while (p->next != NULL)
//			p = p->next;
//		p->next = newNode;
//	}
//	L->size++;
//}
//
//void print(List *L)
//{
//	Node* p = L->Head;
//	while (p != NULL)
//	{
//		printf(" %d", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//void Union(List* L1, List* L2)
//{
//	Node* p = L1->Head;
//	Node* q = L2->Head;
//	List L3;
//	init(&L3);
//	while (p != NULL && q != NULL)
//	{
//		if (p->data == q->data)
//		{
//			insert(&L3, p->data);
//			p = p->next;
//			q = q->next;
//		}
//		else if (p->data > q->data)
//		{
//			insert(&L3, q->data);
//			q = q->next;
//		}
//		else
//		{
//			insert(&L3, p->data);
//			p = p->next;
//		}
//	}
//	while (p)
//	{
//		insert(&L3, p->data);
//		p = p->next;
//	}
//	while (q)
//	{
//		insert(&L3, q->data);
//		q = q->next;
//	}
//	print(&L3);
//}
//
//void Intersect(List* L1, List* L2)
//{
//	List L3;
//	init(&L3);
//	Node* p = L1->Head;
//	Node* q = L2->Head;
//	int cnt = 0;
//	while (p != NULL && q != NULL)
//	{
//		if (p->data == q->data)
//		{
//			insert(&L3, p->data);
//			cnt++;
//			p = p->next;
//			q = q->next;
//		}
//		else if (p->data > q->data)
//		{
//			q = q->next;
//		}
//		else
//			p = p->next;
//	}
//	if(cnt !=0)
//		print(&L3);
//	else
//		printf(" 0\n");
//}
//
//
//int main()
//{
//	List L1, L2;
//	init(&L1);
//	init(&L2);
//	int n1, n2, elem;
//	scanf("%d", &n1);
//	if (n1 != 0)
//	{
//		for (int i = 0; i < n1; i++)
//		{
//			scanf("%d", &elem);
//			insert(&L1, elem);
//		}
//	}
//
//	scanf("%d", &n2);
//	if (n2 != 0)
//	{
//		for (int i = 0; i < n2; i++)
//		{
//			scanf("%d", &elem);
//			insert(&L2, elem);
//		}
//	}
//
//	//print(&L1);
//	//print(&L2);
//	if (n1 ==0 && n2 == 0)
//		printf(" 0\n");
//	else
//		Union(&L1, &L2);
//	Intersect(&L1, &L2);
//	
//	
//	return 0;
//}
///*
//6
//3 7 45 88 99 101
//4
//7 10 15 45
//*/