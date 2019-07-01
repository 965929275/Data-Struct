#include<stdio.h>
#include<stdlib.h>
typedef struct LNode 
{
    int data;
    struct LNode *next;
}LNode;

int initList(LNode *&L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return 1;
}
 
void createLinkListR(LNode *&L, int a[], int n)
{   //Tail Insertion Method
    LNode *s, *r;
    int i;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    for (i = 0; i < n; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void createLinkListF(LNode *&L, int a[], int n)
{	//Head Insertion Method 
	LNode *s;
	int i;
	L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    for(i = 0; i < n; ++i){
    	s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		//the key operation
		s->next = L->next;
		L->next = s;
	}
}

int findAndDelete(LNode *L, int x)
{
	LNode *p, *q;
	p = L;
	while(p->next != NULL){
		if(p->next->data == x)
			break;
		p = p->next;
	}
	if(p->next == NULL)
		return 0;
	else{
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}
}

void mergeR(LNode *A, LNode *B, LNode *&C)
{
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *r;
	C = A;
	C->next = NULL;
	free(B);
	r = C;
	while(p != NULL && q != NULL){
		//Tail Insertion Method
		if(p->data <= q->data){
			r->next = p; p = p->next;
			r = r->next;
		}else{
			r->next = q; q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if(p != NULL) r->next = p;
	if(q != NULL) r->next = q;
}

void mergeF(LNode *A, LNode *B, LNode *&C)
{
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *s;
	C = A;
	C->next = NULL;
	free(B);
	while(p != NULL && q != NULL){
		//Head Insertion Method
		if(p->data <= q->data){
			s = p; p = p->next;
			s->next = C->next;
			C->next = s;
		}else{
			s = q; q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	while(p != NULL){
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while(q != NULL){
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
	
}

void OutList(LNode *L)
{
	LNode *p;
    p=L->next;
	while(p){
		printf("%3d ",p->data);
        p=p->next;
    }
}


int main()
{	
	LNode *L1;
    int a[5] = {0,1,2,3,4};
    createLinkListR(L1, a, 5);
    OutList(L1);printf("\n");
    LNode *L2;
    int b[5] = {5,6,7,8,9};
    createLinkListR(L2, b, 5);
//    findAndDelete(L2, 7);
	OutList(L2);printf("\n");
	LNode *L3;
	mergeF(L1, L2, L3);
	OutList(L3);printf("\n");
}

