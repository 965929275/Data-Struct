#include<stdio.h>
#define maxSize 500

typedef struct
{
	int data[maxSize];
	int top;
}SqStack;

int initStack(SqStack &st)
{
	st.top = -1;
}

int isEmpty(SqStack st)
{
	if (st.top == -1) return 1;
	else return 0;
}

int push(SqStack &st, int x)
{
	if(st.top == maxSize-1) return 0;
	++(st.top);				//move the point first
	st.data[st.top] = x;	//push x into stack
	return 1;
}

int pop(SqStack &st, int &x)
{
	if (st.top == -1) return 0;
	x = st.data[st.top];	//get the top elem first
	--(st.top);				//move the point
	return 1;	
}

void outStack(SqStack st)
{
	int i=0;
	while (i <= st.top)
	{
		printf("%d  ",st.data[i]);
		++i; 
	}
	
}

int main()
{
	SqStack st;
	initStack(st);
	push(st, 0);
	push(st, 1);
	push(st, 2);
	push(st, 3);
	outStack(st);
	int e;
	pop(st, e);
	outStack(st);
	printf("%d",e);
}
