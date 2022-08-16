#include "MGraph.h"

/* Prim算法 */
void MiniSpanTree_Prim(MGraph G);



/* Kruskal算法 */
/* 定义边集数据结构 */
typedef struct {
    EdgeType weight;
    int begin;
    int end;
} Edge;

void MiniSpanTree_Kruskal(MGraph G);
void InitEdgeList(MGraph G, Edge edgelist[]);
void QuickSortEdgeList(Edge edgelist[], int left, int right);
void AssignEdge(Edge *a, Edge *b);
int find(int parent[], int i);
void PrintEdgeList(Edge edgelist[], int n);



