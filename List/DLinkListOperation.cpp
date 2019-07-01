#include<stdio.h>
#include<stdlib.h>
typedef struct DLNode
{
	int data;
	struct DLNode *prior;
	struct DLNode *next;
}DLNode;

int initDLNode(DLNode *&L)
{
	L = (DLNode *)malloc(sizeof(DLNode));
	L->prior = NULL;
	L->next = NULL;
	return 1;
}

void createDLinkListR(DLNode *&L, int a[], int n)
{
	DLNode *s, *r;
	int i;
	L = (DLNode*)malloc(sizeof(DLNode));
	L->prior = NULL;
	L->next = NULL;
	r = L;
	for (i = 0; i < n; ++i)
	{
		s = (DLNode*)malloc(sizeof(DLNode));
		s->data = a[i];
		//different from LNode.createLinkListR
		r->next = s;
		s->prior = r;						//s->prior node is r					
		r = r->next;
	}
	r->next = NULL;

}

DLNode* findNode(DLNode *L, int x)
{	//find a node valued x
	DLNode *p = L->next;
	while (p != NULL)
	{
		if (p->data == x) break;
		p = p->next;
	}
	return p;
}

int insertNode(DLNode *L, int e1, int e2)
{	//insert node valued e2 behind node valued e1
	DLNode *s, *p;
	s = (DLNode *)malloc(sizeof(DLNode));
	s->data = e2;
//	p = L;
//	while(p != NULL){
//		if(p->data == e1){
//			s->next = p->next;
//			p->next->prior = s;
//			p->next = s;
//			s->prior = p;
//			
////code in book:
////			s->next = p->next;
////			s->prior = p;
////			p->next = s;
////			s->next->prior = s;
//		}
//		p = p->next;
//	}
	p = findNode(L, e1);
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;
	
	return 1;
}

int deleteNode(DLNode *L, int e)
{	//delete node valued e
	DLNode *p;
	p = findNode(L, e);
	p->prior->next = p->prior->next->next;
	p->next->prior = p->next->prior->prior;
	free(p);
	return 1;
}

void OutList(DLNode *L)
{
	DLNode *p;
    p=L->next;
	while(p){
		printf("%3d ",p->data);
        p=p->next;
    }
}

int main()
{
	int a[5] = {0,1,2,3,4};
	DLNode *DL;
	initDLNode(DL);
	createDLinkListR(DL, a, 5);
	OutList(DL); printf("\n");
	DLNode *p;
	p = findNode(DL, 3);
	printf("%d",p->data);
	insertNode(DL, p->data, 10);
	OutList(DL); printf("\n");
	deleteNode(DL, 10);
	OutList(DL); printf("\n");
} 
