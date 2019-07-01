#include<stdio.h>
#include<stdlib.h>
typedef struct QNode
{   
    int data;
    struct QNode *next;
}QNode;

typedef struct LiQueue
{
    QNode *front;
    QNode *rear;
}LiQueue;

int initLiQueue(LiQueue *&LQ)
{
    LQ = (LiQueue *)malloc(sizeof(LiQueue));
    LQ->front = LQ->rear = NULL;
}

int isEmpty(LiQueue *LQ)
{
    if(LQ->rear == NULL || LQ->front == NULL) return 1;
    else return 0;
}

int enLiQueue(LiQueue *LQ, int x)
{
    QNode *s;
    s = (QNode *)malloc(sizeof(QNode));
    s->data = x;
    s->next = NULL;
    if(LQ->rear == NULL){
        LQ->front = LQ->rear = s;
    }else{
        LQ->rear->next = s;
        LQ->rear = LQ->rear->next;//or s
    }
    return 1;
}

int deLiQueue(LiQueue *LQ, int &e)
{
    QNode *p;
    if(LQ->rear == NULL) return 0;//the queue is empty
    else p = LQ->front;
    if(LQ->front == LQ->rear)//only one node in the queue
        LQ->front = LQ->rear = NULL;
    else
        LQ->front = LQ->front->next;
    e = p->data;
    free(p);
    return 1;
}

int outLiQueue(LiQueue *LQ)
{
    if(isEmpty(LQ) == 1) return 0;
    while(LQ->front != LQ->rear){
        printf("%d  ",LQ->front->data);
        LQ->front = LQ->front->next;
    }
    return 1;
}
int main()
{
    LiQueue *LQ;
    initLiQueue(LQ);
    enLiQueue(LQ, 0);
    enLiQueue(LQ, 1);
    enLiQueue(LQ, 2);
    enLiQueue(LQ, 3);
    enLiQueue(LQ, 4);
//    outLiQueue(LQ);printf("\n");
//    printf("%d\n",LQ->front->data);
    
    int e;
    deLiQueue(LQ, e);
    printf("deLiqueue:%d\n",e);
    
    int e1;
    deLiQueue(LQ, e1);
    printf("deLiqueue:%d\n",e1);
    
    outLiQueue(LQ);printf("\n");
}
