//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct Node
//{
//	int coef;
//	int exp;
//	struct Node* next;
//}Node;
//
//typedef struct List
//{
//	Node* head;
//}List;
//
//void init(List *L)
//{
//	L->head = NULL;
//}
//
//void insert(List *L,int exp,int coef)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->exp = exp;
//	newNode->coef = coef;
//	newNode->next = NULL;
//	Node* p = L->head;
//	if (p == NULL)
//		L->head = newNode;
//	 else
//	 {
//		while (p->next != NULL)
//			p = p->next;
//		p->next = newNode;
//	  }
//}
//
//void addPoly(List* x, List* y, List* z)
//{
//	Node* p = x->head;
//	Node* q = y->head;
//
//	while (p !=NULL && q !=NULL)
//	{
//		if (p->exp == q->exp) // ������ ���� ���
//		{
//			int sum = p->coef + q->coef;
//			if(sum !=0)
//				insert(z, p->exp, sum);
//			p = p->next;
//			q = q->next;
//		}
//		else if (p->exp > q->exp) // ù ��° ���׽��� ������ ū ���
//		{
//			insert(z, p->exp, p->coef);
//			p = p->next;
//		}
//		else // �� ��° ���׽��� ������ ū ���
//		{
//			insert(z, q->exp, q->coef);
//			q = q->next;
//		}
//	}
//	//�����׵��� �񱳴���� �����Ƿ� ������ �׵鵵 �߰� ����ߵ�
//	// 	
//	// ù ��° ���׽��� ������ �׵� �߰�
//	while (p)
//	{
//		insert(z, p->exp, p->coef);
//		p = p->next;
//	}
//
//	// �� ��° ���׽��� ������ �׵� �߰�
//	while (q)
//	{
//		insert(z, q->exp, q->coef);
//		q = q->next;
//	}
//}
//
//void print(List *L)
//{
//	Node* p = L->head;
//	while (p != NULL)
//	{
//		printf(" %d %d", p->coef, p->exp);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//int main()
//{
//	List* L1, * L2, * L3;
//	init(&L1); init(&L2); init(&L3);
//	int n1, n2;
//	scanf("%d", & n1);
//	for (int i = 0; i < n1; i++)
//	{
//		int coef = 0;
//		int exp = 0;
//		scanf("%d %d", &coef, &exp);
//		insert(&L1, exp, coef);
//	}
//	scanf("%d", &n2);
//	for (int i = 0; i < n2; i++)
//	{
//		int coef = 0;
//		int exp = 0;
//		scanf("%d %d", &coef, &exp);
//		insert(&L2, exp, coef);
//	}
//
//	//print(&L1);
//	//print(&L2);
//	addPoly(&L1, &L2, &L3);
//	print(&L3);
//	return 0;
//}
///*
//3
//5 3 3 2 3 1
//3
//2 6 2 3 1 0
//
//*/