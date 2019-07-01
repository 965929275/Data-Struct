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

//connected  graph DFS:
int visit[maxSize];
void Visit(int v)
{
    printf("");
}
void DFS(AGraph *G, int v)
{
    ArcNode *p;
    visit[v] = 1;
    Visit(v);
    p = G->adjlist[v].firstarc; //p point to v's the first arc
    while(p != NULL){
        if(visit[p->adjvex] == 0){
            DFS(G, p->adjvex);
            p = p->nextarc; 
        }
    }
}