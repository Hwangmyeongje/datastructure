#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode
{
    struct stackNode * next;
    char data;
}stackNode;

typedef struct linkStack
{
    stackNode * top;
}linkStack;


void push(linkStack *s,char data)
{
    stackNode * temp = (stackNode*)malloc(sizeof(stackNode));
    temp -> data =data;
    temp -> next = s->top;
    s->top = temp;
}

void pop(linkStack *s)
{
    stackNode * temp = s->top;
    s->top = s->top ->next;
    free(temp);
}

void sortPush(linkStack *s,char data)
{
    linkStack temp; //임시로 저장할 스택
    temp.top =NULL;
    while(s->top !=NULL && s->top->data <data)
    {
        push(&temp, s->top->data);
        pop(s);
    }
    push(s,data);
    while(temp.top != NULL)
    {
        push(s,temp.top->data);
        pop(&temp);
    }
}

void dup_del(linkStack *s)
{
    stackNode * temp = s->top;
    while(temp)
    {
        stackNode * p = temp;
        while(p->next)
        {
            if(p->next->data == temp->data)
            {
                stackNode * p2 = p->next;
                p->next = p2->next;
                free(p2);
            }
            else
                p = p->next;
        }
        temp = temp->next;
    }

}

void print(linkStack *s)
{
    stackNode * p = s->top;
    while(p)
    {
        printf(" [%c]",p->data);
        p=p->next;
    }


}
int main()
{
    linkStack s;
    linkStack sortStack;
    sortStack.top =NULL;
    s.top = NULL;
    char str[100];
    scanf("%s",str);
    for(int i=0; i<strlen(str); i++)
    {
        push(&s,str[i]);
        sortPush(&sortStack,str[i]);
    }
    print(&s);
    printf("\n");
    dup_del(&s);
    print(&s);
    printf("\n");
    print(&sortStack);
    printf("\n");
    dup_del(&sortStack);
    print(&sortStack);
    return 0;
}