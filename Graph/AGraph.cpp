//Adjacency table
//Chain storage structure
#include<stdio.h>
#include<stdlib.h>
#define maxSize 500
typedef struct ArcNode
{
    int adjvex;             //this arc points to the node
    struct ArcNode *nextarc; //point to the next arc
    int info;               //some info,eg:weight(not must)
}ArcNode;
typedef struct VNode
{
    char data;              //vertex info
    ArcNode *firstarc;      //point to the first arc
}VNode;
typedef struct AGraph
{
    VNode adjlist[maxSize]; //adjacency table
    int n,e;                //the number of the vertex and edge
}AGraph;

//visit[] is a global array, it is used to record the vertex whether was visited,
//beacuse the Graph is a circuit,we need to record what I said just now.
//Then,we can avoid to repeat to visit vertex.
int visit[maxSize];
void Visit(int v)
{
    ArcNode *p;
    p->adjvex = v;      //here are some questions.
    printf("%d",p->info);//
}
//connected  graph DFS:
//DFS is like the preOrderBinaryTree
void DFS(AGraph *G, int v)      //v is the starting num.(it means the first vertex that will be visited)
{
    ArcNode *p;
    visit[v] = 1;               //the vertex has been visited,so visit[v] = 1
    Visit(v);                   //what???visit a int num??how to ?
    p = G->adjlist[v].firstarc; //p point to v's the first arc
    while(p != NULL){
        if(visit[p->adjvex] == 0){//if vertex is not visit,we will recur to visit it.
            DFS(G, p->adjvex);  //yeah,here it is,the key one,like preOrderBinaryTree
            p = p->nextarc;     //okay,we can operate the next one
        }
    }
}

int main()
{
    
}