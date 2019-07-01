#include<stdio.h>
#include<stdlib.h>
#define maxSize 500

typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode; 

int initBTree(BTNode *&BT)
{
    BT = (BTNode*)malloc(sizeof(BTNode));
    BT->lchild == NULL;
    BT->rchild == NULL;
}

void visit(BTNode *p){
    printf("%c",p->data);
}

void preOrderNonRecursion(BTNode *BT)
{
    BTNode *Stack[maxSize];
    int top = -1;
    BTNode *p;
    Stack[++top] = BT;      //root push into the stack
    while(top != -1){
        p = Stack[top--];   //destack
        visit(p);
        //stack is FILO,so the preOrder push the rchild into the stack first
        if(p->rchild != NULL){
            Stack[++top] = p->rchild;
        }
        if(p->lchild != NULL){
            Stack[++top] = p->lchild;
        }
    }
}

void inOrderNonRecursion(BTNode *BT)
{
    if(BT != NULL){
        BTNode *Stack[maxSize];
        int top = -1;
        BTNode *p;
        p = BT;
        //the Stack may be empty in the process, 
        //so the condition that p != NULL can keep the loop continue
        while(top = -1 || p != NULL){
            while(p != NULL){
                Stack[++top] = p;
                p = p->lchild;
            }
            if(top != -1){
                p = Stack[top--];
                visit(p);
                p = p->rchild;
            }
        }
    }
}

void postOrderNonRecursion(BTNode *BT)
{
    if(BT != NULL){
        //postOrderNonRecursion need two stacks
        BTNode *Stack1[maxSize]; int top1 = -1;
        BTNode *Stack2[maxSize]; int top2 = -1;
        BTNode *p = NULL;
        Stack1[++top1] = BT;
        while(top1 != -1){
            p = Stack1[top1--];
            Stack2[++top2] = p;
            if(p->lchild != NULL){
                Stack1[++top1] = p->lchild;
            }
            if(p->rchild != NULL){
                Stack1[++top2] = p->rchild;
            }
        }
        //the stack2 push is the postOrderNonRecursion
        while(top2 != -1){
            p = Stack2[top2--];
            visit(p);
        }
    }
}

int main()
{
    
}
