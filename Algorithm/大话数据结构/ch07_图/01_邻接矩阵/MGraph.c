#include <stdio.h>
#include <stdlib.h>
#include "MGraph.h"


/* CreateMGraph: 创建图的邻接矩阵 */
MGraph * CreateMGraph(void){
    MGraph *gp;
    int i, j, k, w;

    gp = (MGraph *)malloc(sizeof(MGraph));
    if (!gp)
        return NULL;

    printf("Enter number of vertexes and edges:\n");
    scanf("%d, %d\n", &gp->numVertexes, &gp->numEdges);
    //printf("get: %d, %d\n", gp->numVertexes, gp->numEdges);

    printf("Enter vertexes:\n");
    for (i = 0; i < gp->numVertexes; i++){
        scanf("%c",&gp->vexs[i]);
        //printf("get vex: %c\n", gp->vexs[i]);
    }
        

    for (i = 0; i < gp->numVertexes; i++)       /*初始化邻接矩阵 */
        for (j = 0; j < gp->numVertexes; j++)
            gp->arc[i][j] = INFINITY;

    for (k = 0; k < gp->numEdges; k++){
        printf("Enter edge info:\n");
        scanf("%d, %d, %d", &i, &j, &w);
        gp->arc[i][j] = w;
        gp->arc[j][i] = w;
    }

    return gp;
}


/* DestroyGraph: 销毁图 */
void DestroyGraph(MGraph *gp){
    free(gp);
    gp = NULL;
}


/* HasVeertex: 返回图G中是否有顶点v */
int HasVertex(MGraph G, VertexType v){
    int i;

    for (i = 0; i < G.numVertexes; i++){
        if (G.vexs[i] == v)
            return 1;
    }
    return 0;
}


/* HasEdge: 返回图G中是否有边(v1, v2) */
int HasEdge(MGraph G, VertexType v1, VertexType v2){
    int loc1, loc2;

    loc1 = LocateVertex(G, v1);
    loc2 = LocateVertex(G, v2);

    if (loc1 == -1 || loc2 == -1 || G.arc[loc1][loc2] == INFINITY)
        return 0;
    else 
        return 1;
}


/* LocateVertex: 返回顶点v在图G顶点列表中的下标位置 */
int LocateVertex(MGraph G, VertexType v){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        if (G.vexs[i] == v)
            return i;
    return -1;
}


/* InsertVex: 在图中新增顶点v */
void InsertVex(MGraph *gp, VertexType v){
    int i;
    
    if (HasVertex(*gp, v)){
        printf("Error: already has %c\n", v);
        return;
    }
    
    gp->vexs[gp->numVertexes] = v;
    gp->numVertexes++;

    for (i = 0; i < gp->numVertexes; i++){
        gp->arc[gp->numVertexes-1][i] = INFINITY;
        gp->arc[i][gp->numVertexes-1] = INFINITY;
    }
}


/* InsertEdge: 在图中新增边(v1, v2) */
void InsertEdge(MGraph *gp, VertexType v1, VertexType v2, EdgeType e){
    int loc1, loc2;

    loc1 = LocateVertex(*gp, v1);
    loc2 = LocateVertex(*gp, v2);

    if (loc1 == -1 || loc2 == -1){
        printf("Error: wrong vertexes\n");
        return;
    }

    gp->arc[loc1][loc2] = gp->arc[loc2][loc1] = e;
}


/* DeleteVes: 删除顶点v及相关边 */
int DeleteVex(MGraph *gp, VertexType v){
    int loc, i, j, n;

    loc = LocateVertex(*gp, v);
    if (loc == -1)
        return 0;

    for (i = loc; i < gp->numVertexes - 1; i++)          /* 删除顶点，将列表中后续顶点前移 */
        gp->vexs[i] = gp->vexs[i+1];

    for (i = 0, n = 0; i < gp->numVertexes; i++)    /* 统计与顶点v相关的边的数量 */
        if (gp->arc[loc][i] != INFINITY)
            n++;

    for (i = loc; i < gp->numVertexes - 1; i++)     /* 删除与顶点v相关的边，将邻接矩阵中后续的值前移 */
        for (j = 0; j < gp->numVertexes; j++)
            gp->arc[i][j] = gp->arc[i+1][j];

    for (i = loc; i < gp->numVertexes - 1; i++)
        for (j = 0; j < gp->numVertexes - 1; j++)   /* 由于已删除一行，因此当前只有numVertexes-1行 */
            gp->arc[j][i] = gp->arc[j][i+1];

    gp->numVertexes--;
    gp->numEdges -= n;
    return 1;
}


/* DeleteEdge: 删除边(v1, v2) */
int DeleteEdge(MGraph *gp, VertexType v1, VertexType v2){
    int loc1, loc2;

    loc1 = LocateVertex(*gp, v1);
    loc2 = LocateVertex(*gp, v2);

    if (loc1 == -1 || loc2 == -1){
        printf("Error: wrong vertexes\n");
        return 0;
    }

    if (gp->arc[loc1][loc2] == INFINITY){
        printf("Error: no edge (%c, %c)\n", v1, v2);
        return 0;
    }

    gp->arc[loc1][loc2] = gp->arc[loc2][loc1] = INFINITY;
    return 1;
}


/* PrintVertexes: 打印G中的所有顶点 */
void PrintVertexes(MGraph G){
    int i;
    for (i = 0; i < G.numVertexes; i++)
        printf("Vertex%d: %c\n", i+1, G.vexs[i]);
}


/* PrintEdges: 打印G中所有边 */
void PrintEdges(MGraph G){
    int i, j, n;

    n = 0;
    for (i = 0; i < G.numVertexes; i++){        /* 循环邻接矩阵的右上三角 */
        for (j = i+1; j < G.numVertexes; j++){
            if (G.arc[i][j] == INFINITY)
                continue;
            printf("Edge%d: (%c, %c, %d)\n", ++n, G.vexs[i], G.vexs[j], G.arc[i][j]);
        }
    }
}


/* PrintMatrix: 打印邻接矩阵 */
void PrintMatrix(MGraph G){
    int i, j, k;

    for (i = 0; i < G.numVertexes; i++){
        for (j = 0; j < G.numVertexes; j++){
            k = (G.arc[i][j] == INFINITY) ? 0 : G.arc[i][j];
            printf("%4d", k);
        }            
        printf("\n");
    }
}

