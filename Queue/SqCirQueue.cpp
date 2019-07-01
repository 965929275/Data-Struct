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
//��ʼ��ʱ��front=rear=0�����ƶ�ָ�룬�ٳ�ջ����ʱ������ĳ�ջ��ʵû��������ջ������ֻȡ�˶���Ԫ�أ���������һ�γ���ʱ����һ��û�õ�Ԫ�زŻ����
//��һ��˼�룺 front=rear=-1���ȳ�ջ�����ƶ�ָ�룬��ʱȡ��ֵ���������ջ,
//�������治�У�front=-1������Ͳ�� 
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
