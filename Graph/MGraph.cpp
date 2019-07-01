//this is the Adjacency matrix for graph.
//Sequential storage structure
#include<stdio.h>
#include<stdlib.h>
#define maxSize 500
typedef struct VertexType
{
    int no;
    char info;
}VertexType;

typedef struct MGraph
{
    int edge[maxSize][maxSize]; //if right map, int->float
    int n,e;                    //define the number of the vertex and edge
    VertexType vex[maxSize];    //vertex message
}MGraph;



