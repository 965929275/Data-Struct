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

void preOrder(BTNode *BT)
{
    if(BT != NULL){
        visit(BT);
        preOrder(BT->lchild);
        preOrder(BT->rchild);
    }
}

void inOrder(BTNode *BT)
{
    if(BT != NULL){
        inOrder(BT->lchild);
        visit(BT);
        inOrder(BT->rchild);
    }
}

void postOrder(BTNode *BT)
{
    if(BT != NULL){
        postOrder(BT->lchild);
        postOrder(BT->rchild);
        visit(BT);
    }
}

void level(BTNode *BT)
{
    int front, rear;
    BTNode *que[maxSize];   //the cirqueue is used to visit node in the level
    front = rear = 0;
    BTNode *q;
    if(BT != NULL){
        rear = (rear + 1) % maxSize;    //the cirqueue moves the point
        que[rear] = BT;                  //the root enqueues
        while(front != rear){
            front = (front + 1) % maxSize;
            q = que[front];             //the front node dequeue
            visit(q);
            if(q->lchild != NULL){      //the lchild is not null,it enqueue
                rear = (rear + 1) % maxSize;
                que[rear] = q->lchild;
            }
            if(q->rchild != NULL){      //the rchild is not null,it enqueue
                rear = (rear + 1) % maxSize;
                que[rear] = q->rchild;
            }
        }
    }
}

// void enBTree(BTNode *BT, char loc, char x)
// {
//     BTNode *p;
//     p = (BTNode*)malloc(sizeof(BTNode));
//     p->data = x;
//     p->lchild = NULL;
//     p->rchild = NULL;
// //    printf("%c",loc);
//     if(loc == 'l'){
//         BT->lchild == p;
//     }
//     if(loc == 'r'){
//         BT->rchild == p;
//     }
// }

int main()
{
    BTNode *BT;

    
//    preOrder(BT);
//    inOrder(BT);
//    postOrder(BT);

}
