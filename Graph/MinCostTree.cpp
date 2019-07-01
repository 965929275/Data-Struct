#include<stdio.h>
#include<stdlib.h>
#define maxSize 500
#define INF 500

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

void Prim(MGraph g, int v0, int &sum)
{   /*
    v0: the beginning vertex
    sum: the right of the MinCostTree
    */
    int lowcost[maxSize], vset[maxSize], v;
    int i, j, k, min;
    v = v0;
    //将v0所有边存到lowcost数组中
    for(i = 0; i < g.n; ++i){
        lowcost[i] = g.edge[v0][i];
        vset[i] = 0;
    }
    vset[v0] = 1;                   //include the v0 into the tree
    sum = 0;
    for(i = 0; i < g.n - 1; ++i){
        min = INF;                  //bigger than all other edges
        //this for loop can find the min edge of the v0
        for(j = 0; j<g.n; ++j){
            if(vset[j] == 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
            vset[k] = 1;
            v = k;
            sum += min;
            for(j = 0; j < g.n; ++j){
                if(vset[j] == 0 && g.edge[v][j] < lowcost[j])
                    lowcost[j] = g.edge[v][j];
            }
        }
    }
}
int main()
{
    
}

