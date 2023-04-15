//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//typedef int element;
//
//typedef struct DListNode
//{
//    element data;
//    struct DListNode* prev;
//    struct DListNode* next;
//}DListNode;
//
//typedef struct
//{
//    DListNode* H;
//    DListNode* T;
//    int N; //집합의 카디널리티
//}SetType;
////내 코드로 치면 list 구조체
//
//DListNode* getNode()
//{
//    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
//    node->prev = node->next = NULL;
//    return node;
//}
//
//void init(SetType* S)
//{
//    S->H = getNode();
//    S->T = getNode();
//    S->H->next = S->T;
//    S->T->prev = S->H;
//    S->H->data = S->T->data = 0;
//
//    S->N = 0;
//}
//
//void addNode(SetType* S, DListNode* p, int e)
//{
//    DListNode* node = getNode();
//    node->data = e;
//
//    node->prev = p;
//    node->next = p->next;
//    p->next->prev = node;
//    p->next = node;
//    
//    S->N++;
//
//}
//
////정렬하면서 집어넣어야 함
//void add(SetType* S, element e)
//{
//    DListNode* p = S->H;
//    int status = 1;
//    if (p->next == S->T)
//        addNode(S, p, e);
//    else
//    {
//        while (e >= p->next->data && p->next->next != NULL)
//        {
//            if (e == p->next->data)
//            {
//                status = 0;
//                break;
//            }
//            p = p->next;
//        }
//        if (status == 1)
//        {
//            addNode(S, p, e);
//        }
//    }
//}
//void traverse(SetType* S)
//{
//    DListNode* p = S->H->next;
//    for (; p != S->T; p = p->next)
//    {
//        printf("[%d] ", p->data);
//    }
//    printf("\n");
//}
//
//void addLast(SetType* S, int e)
//{
//    DListNode* node = getNode();
//    node->data = e;
//    node->next = S->T;
//    node->prev = S->T->prev;
//    S->T->prev->next = node;
//    S->T->prev = node;
//    S->N++;
//}
//
//void unionSet(SetType* S1, SetType* S2)
//{
//    SetType S3;
//    init(&S3);
//
//    DListNode* p = S1->H->next;
//    DListNode* q = S2->H->next;
//    while (p != S1->T && q != S2->T)
//    {
//        if (p->data < q->data)
//        {
//            addLast(&S3, p->data);
//            p = p->next;
//        }
//        else if (p->data > q->data)
//        {
//            addLast(&S3, q->data);
//            q = q->next;
//        }
//        else
//        {
//            addLast(&S3, p->data);
//            p = p->next;
//            q = q -> next;
//        }
//
//    }
//    while (p != S1->T)
//    {
//        addLast(&S3, p->data);
//        p = p->next;
//    }
//    while (q != S2->T)
//    {
//        addLast(&S3, q->data);
//        q = q->next;
//    }
//    printf("union");
//    traverse(&S3);
//}
//
//void interSect(SetType *S1, SetType *S2)
//{
//    SetType S3;
//    init(&S3);
//    DListNode* p = S1->H->next;
//    DListNode* q = S2->H->next;
//    while (p != S1->T && q != S2->T)
//    {
//
//        if (p->data < q->data)
//        {
//            p = p->next;
//        }
//        else if (p->data > q->data)
//        {
//            q = q->next;
//        }
//        else
//        {
//            addLast(&S3, p->data);
//            p = p->next;
//            q = q->next;
//        }
//        
//    }
//   /* while (p != S1->T)
//        p = p->next;
//    while (q != S2->T)
//        q = q->next;*/
//    printf("intersect");
//    traverse(&S3);
//
//}
//
//
//void subTract(SetType* S1, SetType* S2)
//{
//    SetType S3;
//    init(&S3);
//    DListNode* p = S1->H->next;
//    DListNode* q = S2->H->next;
//    while (p != S1->T && q != S2->T)
//    {
//
//        if (p->data < q->data)
//        {
//            addLast(&S3, p->data);
//           p = p->next;
//        }
//        else if (p->data > q->data)
//        {
//            q = q->next;
//        }
//        else
//        {
//            p = p->next;
//            q = q->next;
//        }
//
//    }
//    while (p != S1->T)
//    {
//        addLast(&S3, p->data);
//        p = p->next;
//
//    }
//    while (q != S2->T)
//        q = q->next;
//    printf("subtract");
//    traverse(&S3);
//}
//
//int isMember(SetType* S, int e)
//{
//    DListNode* p = S->H->next;
//    int a;
//    while (1)
//    {
//        a = p->data;
//        if (a < e)
//        {
//            if (p->next == S->T)
//                return 0;
//            else
//                p = p->next;
//        }
//        else if (a > e)
//        {
//            return 0;
//        }
//        else
//            return 1;
//    }
//}
//
//int isSubSet(SetType* S1, SetType *S2)
//{
//    DListNode* p = S1->H->next;
//    while (1)
//    {
//        if (isMember(S2, p->data))
//            if (p->next == S1->T)
//                return 1;
//            else
//                p = p->next;
//        else
//            return 0;
//    }
//}
//
//int main()
//{
//    SetType S1, S2;
//
//    init(&S1), init(&S2);
//    srand(time(NULL));
//    element e;
//
//    for (int i = 1; i <= 10; i++)
//    {
//        e = rand() % 40 + 10; //중복은 저장 안할거임
//        add(&S1, e);
//    }
//    for (int i = 1; i <= 10; i++)
//    {
//        e = rand() % 40 + 10; //중복은 저장 안할거임
//        add(&S2, e);
//    }
//    printf("A : "); traverse(&S1);
//    printf("B : "); traverse(&S2);
//    printf("\n");
//
//    unionSet(&S1, &S2);
//    interSect(&S1, &S2);
//    subTract(&S1, &S2);
//    
//    scanf("%d", &e);
//    if (isMember(&S1, e) == 1)
//        printf("exist\n");
//    else
//        printf("No\n");
//
//    SetType S3, S4;
//    init(&S3);
//    init(&S4);
//
//    add(&S3, 3);
//    add(&S3, 8);
//    add(&S4, 2);
//    add(&S4, 3);
//    add(&S4, 5);
//    add(&S4, 8);
//
//    if (isSubSet(&S3, &S4) == 1)
//        printf("Subset\n");
//    else
//        printf("No Subset\n");
//        
//        
//    return 0;
//}//여기서 n 필요해?