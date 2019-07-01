#include<stdio.h>
#include<stdlib.h>
#define maxSize 500
typedef struct SqQueue
{
    int data[maxSize];
    int front;
    int rear;
}SqQueue; 

int initSqQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

int isEmpty(SqQueue Q)
{
    if(Q.front == Q.rear) return 1;//wherever they are,if Q.front coincides Q.rear,the Queue is empty
    else return 0;
}

int enQueue(SqQueue &Q, int x)
{
    if((Q.rear + 1) % maxSize == Q.front) return 0;//the Queue is full
    Q.rear = (Q.rear + 1) % maxSize;//move the point first
    Q.data[Q.rear] = x;
    return 1;
}

int deQueue(SqQueue &Q, int &e)
{
    if(isEmpty(Q) == 1) return -1;
    printf("front:%d\n",Q.front); 
//    e = Q.data[Q.front];
//here need to notice,
//初始化时，front=rear=0，先移动指针，再出栈，此时，这里的出栈其实没有真正出栈，而是只取了队首元素，当进行下一次出队时，上一次没用的元素才会出队
//另一种思想： front=rear=-1，先出栈，在移动指针，此时取其值，并将其出栈,
//这样还真不行，front=-1，后面就差开了 
    Q.front = (Q.front + 1) % maxSize;//move the point first
    e = Q.data[Q.front];
    return e;
}

void outQueue(SqQueue Q)
{
    if(isEmpty(Q) == 0){
        while(Q.front != Q.rear){
            printf("%d  ", Q.data[Q.front+1]);
            Q.front = (Q.front + 1) % maxSize;
        }
    }
}

int main()
{
    SqQueue Q;
    initSqQueue(Q);
    enQueue(Q, 0);
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    outQueue(Q);printf("\n");
    int e;
    deQueue(Q, e);
	outQueue(Q);printf("\n");
    printf("%d\n", e);
    
    int e1;
    deQueue(Q, e1);
	outQueue(Q);printf("\n");
    printf("%d\n", e1);
    
    int e2;
    deQueue(Q, e2);
	outQueue(Q);printf("\n");
    printf("%d\n", e2);
}
