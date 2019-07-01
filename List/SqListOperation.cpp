#include<stdio.h>
#define maxSize 500

typedef struct
{
	int data[maxSize];
	int length;
}SqList;//sq : sequence

void initList(SqList &L)
{
	L.length = 0;
}
int insertElem(SqList &L, int p, int e)
{	//insert e from L at p
    int i;
    if (p<0 || p>L.length || L.length==maxSize)
    	return 0;
    for(i=L.length-1;i>=p;--i)
    	L.data[i+1] = L.data[i]; 
    L.data[p] = e;
    ++(L.length);
    return 1;
}

int deleElem(SqList &L, int p, int e)
{	//delete e from L at p
	int i;
	if (p<0 || p>L.length-1)
		return 0;
	e = L.data[p];
	for (i = p; i < L.length - 1; ++i)
		L.data[i] == L.data[i+1];
	--(L.length);
	return 1;
}

int findElem(SqList L, int e)
{	//find e from L
	//return location
	for (int i = 0; i < L.length; ++i)
	{
		if (L.data[i] == e)
			return i;
		else
			return 0;
	}
}

int getElem(SqList L, int p, int &e)
{	//get e from L at p
	if (p < 0 || p > L.length)
		return 0;
	e = L.data[p];
	return 1;
}


int main()
{
	SqList L;
	int data;
	initList(L);
	printf("insert:\n");
	insertElem(L, 0, 0001);
	printf("%d\n",L.data[0]);
	printf("length: %d\n",L.length);
	insertElem(L, 1, 111);
	printf("length: %d\n",L.length);
	insertElem(L, 2, 222);
	printf("length: %d\n",L.length);
//	printf("%d\n",L.data[0]);
//	printf("%d\n",L.data[1]);
//	printf("%d\n",L.data[2]);
	
	printf("length: %d\n",L.length);
	deleElem(L, 1, 111);
	printf("length: %d\n",L.length);
	int index;
	index = findElem(L, 222);
	printf("index: %d",index);
	
	printf("%d\n",L.data[0]);
	printf("%d\n",L.data[1]);
	printf("%d\n",L.data[2]);
	
	int e;
	getElem(L, 1, e);
	printf("%d",e);
}
