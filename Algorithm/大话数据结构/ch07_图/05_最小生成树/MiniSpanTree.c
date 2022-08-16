#include <stdio.h>
#include "MiniSpanTree.h"


/* MiniSpanTree_Prim: 用Prim算法生成最小生成树 */
void MiniSpanTree_Prim(MGraph G){
    int is_visted[MAXVEX];      /* 保存顶点是否已被访问的状态 */
    int adjvex[MAXVEX];         /* 保存顶点的最小权重边对应的邻接点 */
    int edgeweight[MAXVEX];     /* 保存顶点的最小权重的边, 即(i, advvex[i])的边权重*/
    int i, j;
    int min_val, min_vex;

    is_visted[0] = 1;           /* 以下标0的顶点为起始点 */
    adjvex[0] = 0;
    edgeweight[0] = 0;

    for (i = 1; i < G.numVertexes; i++){    /* 初始化3个数组 */
        is_visted[i] = 0;
        adjvex[i] = 0;
        edgeweight[i] = G.arc[0][i];
    }

    for (i = 1; i < G.numVertexes; i++){    /* 循环n轮，每轮取最小的边，及组成改边的顶点 */
        min_val = INFINITY;
        min_vex = 0;
        for (j = 1; j < G.numVertexes; j++){        /* 找出当前这轮最小的边及顶点 */
            if (!is_visted[j] && edgeweight[j] < min_val){
                min_val = edgeweight[j];
                min_vex = j;
            }
        }

        is_visted[min_vex] = 1;
        printf("(%c, %c): %d\n", G.vexs[adjvex[min_vex]], G.vexs[min_vex], edgeweight[min_vex]);

        for (j = 1; j < G.numVertexes; j++){        /* 循环本轮最小边的顶点的邻接点，更新权重数组和邻接点数组 */
            if (!is_visted[j] && G.arc[min_vex][j] < edgeweight[j]){
                edgeweight[j] = G.arc[min_vex][j];
                adjvex[j] = min_vex;
            }
        }
    }
}





/* MiniSpanTree_Kruskal: 用Kruskal算法生成最小生成树 */
void MiniSpanTree_Kruskal(MGraph G){
    Edge edgelist[G.numEdges];
    int parent[G.numVertexes];
    int i, m, n;

    InitEdgeList(G, edgelist);                      /* 初始化边集数组 */
    QuickSortEdgeList(edgelist, 0, G.numEdges-1);     /* 对边集数组按边权重从小到大排列 */

    for (i = 0; i < G.numVertexes; i++)             /* 初始化边的尾部下标数组 */
        parent[i] = -1;

    for (i = 0; i < G.numEdges; i++){               /* 循环边集数组，依次取权重最小的边 */
        m = find(parent, edgelist[i].begin);        /* 判断当前取的边是否和已有边集构成环 */
        n = find(parent, edgelist[i].end);          
        //printf("round%d: m=%d, n=%d\n", i, m, n);
        if (m != n){                                /* 如果未构成环，加入已有边集 */
            parent[m] = n;
            printf("(%c, %c): %d\n", G.vexs[m], G.vexs[n], edgelist[i].weight);
        }
    }
}


/* InitEdgeList: 将邻接矩阵转为边集数组 */
void InitEdgeList(MGraph G, Edge edgelist[]){
    int i, j, k;

    k = 0;
    for (i = 0; i < G.numVertexes - 1; i++){
        for (j = i + 1; j < G.numVertexes; j++){
            if (G.arc[i][j] == INFINITY)
                continue;
            edgelist[k].begin = i;
            edgelist[k].end = j;
            edgelist[k].weight = G.arc[i][j];
            k++;
        }
    }


}


/* QuickSortEdgeList: 用快排算法对边集数组进行排序 */
void QuickSortEdgeList(Edge edgelist[], int left, int right){
    int i, j;
    Edge tmp;

    if (left >= right)
        return;

    for (i = 0, j = 0; i < right; i++){
        if (edgelist[i].weight < edgelist[right].weight){
            AssignEdge(&tmp, &edgelist[j]);
            AssignEdge(&edgelist[j], &edgelist[i]);
            AssignEdge(&edgelist[i], &tmp);
            j++;
        }
    }

    AssignEdge(&tmp, &edgelist[j]);
    AssignEdge(&edgelist[j], &edgelist[right]);
    AssignEdge(&edgelist[right], &tmp);

    QuickSortEdgeList(edgelist, left, j-1);
    QuickSortEdgeList(edgelist, j+1, right);
}


/* AssignEdge: 将边b的值赋给边a */
void AssignEdge(Edge *a, Edge *b){
    a->weight = b->weight;
    a->begin = b->begin;
    a->end = b->end;
}


/* find: 根据parent数组查找连续边的尾部下标 */
int find(int parent[], int i){
    while (parent[i] > -1)
        i = parent[i];
    
    return i;
}


/* PrintEdgeList: 打印边集数组 */
void PrintEdgeList(Edge edgelist[], int n){
    int i;

    for (i = 0; i < n; i++){
        printf("(%d, %d): %d\n", edgelist[i].begin, edgelist[i].end, edgelist[i].weight);
    }
    
}