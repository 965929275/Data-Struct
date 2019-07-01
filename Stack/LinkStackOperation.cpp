#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

int initLinkStack(LNode *&lst)
{
    lst = (LNode *)malloc(sizeof(LNode));
    lst->next = NULL;
    return 1;
}

int isEmpty(LNode *lst)
{
    if(lst->next == NULL) return 1;
    else return 0;
}

int push(LNode *lst, int x)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));
    p->next = NULL;
    p->data = x;
    //Tail Insertion Method
    p->next = lst->next;
    lst->next = p;
}

int pop(LNode *lst, int &x)
{
    LNode *p;
    if(lst->next == NULL) return 0;
    p = lst->next;
    lst->next = lst->next->next;
    x = p->data;
    free(p);
    return 1;
}

void outLinkStack(LNode *lst)
{
//    if(lst->next == NULL) break;
    LNode *p;
    p = lst;
    while(p->next != NULL){
    	p = p->next;
        printf("%d  ",p->data);
//        p = p->next;
    }
}

int main()
{
	LNode *lst;
    initLinkStack(lst);
    push(lst, 0);
    push(lst, 1);
    push(lst, 2);
    push(lst, 3);
    outLinkStack(lst);printf("\n"); 
    int e;
    pop(lst, e);
    outLinkStack(lst);printf("\n"); 
    printf("%d", e);
}
