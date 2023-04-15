//#define _CRT_SECURE_NO_WARNINGS
//
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
//	Node* Head;
//	int N;
//}List;
//
//void init(List * A)
//{
//	A->Head = NULL;
//	A->N = 0;
//}
//
//void insert(List *L, int data)
//{
//	Node* p = L->Head;
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = NULL;
//	if (p == NULL)
//		L->Head = newNode;
//	else
//	{
//		while (p->next != NULL)
//			p = p->next;
//		p->next = newNode;
//	}
//	L->N++;
//}
//
//void subset(List *L1,List *L2)
//{
//	Node* p = L1->Head;
//	Node* q = L2->Head;
//	int cnt = 0;
//	while (p != NULL && q != NULL)
//	{
//		if (p->data == q->data)
//		{
//			cnt++;
//			p = p->next;
//			q = q->next;
//		}
//		else if (p->data > q->data)
//		{
//			q = q->next;
//		}
//		else
//			break;
//	}
//	if (cnt == L1->N)
//	{
//		printf("0");
//	}
//	else
//	{
//		printf("%d", p->data);
//	}
//}
//
//void print(List* L)
//{
//	Node* p = L->Head;
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//int main()
//{
//	List L1, L2;
//	init(&L1); init(&L2);
//	int n1, n2,elem;
//	scanf("%d", &n1);
//	if (n1 != 0)
//	{
//		for (int i = 0; i < n1; i++)
//		{
//			scanf("%d", &elem);
//			insert(&L1, elem);
//		}
//	}
//	scanf("%d", &n2);
//	if (n2 != 0)
//	{
//		for (int i = 0; i < n2; i++)
//		{
//			scanf("%d", &elem);
//			insert(&L2, elem);
//		}
//	}
//	//print(&L1);
//	//print(&L2);
//	if (n1 == 0)
//		printf("0");
//	else
//	{
//		subset(&L1, &L2);
//	}
//	return 0;
//}
///*
//4
//7 10 53 67
//5
//7 10 15 45 55
//*/