#include <stdio.h>
#include <stdlib.h>
#include "GraphCrossAdj.h"


/* GraphCrossAdj: 创建十字邻接表 */
GraphCrossAdj * CreateCrossALGraph(void){
    GraphCrossAdj *cp;
    EdgeNode *ep;
    int i, m, n, w;

    cp = (GraphCrossAdj *)malloc(sizeof(GraphCrossAdj));
    if (!cp)
        return NULL;

    printf("Enter number of vertex and edge:\n");           /* 输入顶点和边的数量 */
    scanf("%d, %d\n", &cp->numVertexes, &cp->numEdges);

    printf("Enter list of vertexes:\n");
    for (i = 0; i < cp->numVertexes; i++){                  /* 输入顶点信息 */
        scanf("%c", &cp->crosslist[i].data);
        cp->crosslist[i].firstin = NULL;
        cp->crosslist[i].firstout = NULL;
    }

    for (i = 0; i < cp->numEdges; i++){                     /* 输入边信息 */
        printf("Enter edge info:\n");
        scanf("%d, %d, %d", &m, &n, &w);

        ep = (EdgeNode *)malloc(sizeof(EdgeNode));
        if (ep){
            ep->tailvex = m;
            ep->headvex = n;
            ep->taillink = cp->crosslist[m].firstout;
            cp->crosslist[m].firstout = ep;
            ep->headlink = cp->crosslist[n].firstin;
            cp->crosslist[n].firstin = ep;
            ep->weight = w;
        }
    }

    return cp;
}


/* DestroyGraph: 销毁图 */
void DestroyGraph(GraphCrossAdj *cp){
    int i;
    EdgeNode *ep, *tp;

    for (i = 0; i < cp->numVertexes; i++){      /* 循环顶点 */
        ep = cp->crosslist[i].firstout;
        while (ep){                             /* 循环出度的邻接表 */
            tp = ep;
            ep = tp->taillink;
            free(tp);
        }
    }
    free(cp);
}


/* HasVex: 返回图G是否有顶点v */
int HasVex(GraphCrossAdj G, VertexType v){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        if (G.crosslist[i].data == v)
            return 1;
    return 0;
}


/* HasEdge: 返回图G是否有有向边(v1, v2) */
int HasEdge(GraphCrossAdj G, VertexType v1, VertexType v2){
    int loc1, loc2;
    EdgeNode *ep;

    loc1 = LocateVex(G, v1);
    loc2 = LocateVex(G, v2);
    if (loc1 == -1 || loc2 == -1){
        printf("Error: no vertex\n");
        return 0;
    }

    ep = G.crosslist[loc1].firstout;    /* 从尾部顶点v1的第一个出度开始循环 */
    while (ep){
        if (ep->headvex == loc2)        /* 找头部顶点为v2的边 */
            return 1;
        ep = ep->taillink;
    }
    return 0;
}


/* LocateVex: 返回顶点v的下标 */
int LocateVex(GraphCrossAdj G, VertexType v){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        if (G.crosslist[i].data == v)
            return i;
    return -1;
}


/* InsertVex: 在图中新增顶点v */
int InsertVex(GraphCrossAdj *cp, VertexType v){
    if (HasVex(*cp, v)){
        printf("Error: already has vertex %c\n", v);
        return 0;
    }

    cp->crosslist[cp->numVertexes].data = v;
    cp->crosslist[cp->numVertexes].firstin = NULL; 
    cp->crosslist[cp->numVertexes].firstout = NULL;
    cp->numVertexes++;
    return 1;
}


/* InsertEdge: 在图中新增有向边(v1, v2) */
int InsertEdge(GraphCrossAdj *cp, VertexType v1, VertexType v2, EdgeType e){
    int loc1, loc2;
    EdgeNode *ep;

    if ((loc1 = LocateVex(*cp, v1)) == -1 || (loc2 = LocateVex(*cp, v2)) == -1){
        printf("Error: no vertex\n");
        return 0;
    }

    if (HasEdge(*cp, v1, v2)){
        printf("Error: already has edge (%c, %c)\n", v1, v2);
        return 0;
    }

    ep = (EdgeNode *)malloc(sizeof(EdgeNode));
    if (ep){
        ep->tailvex = loc1;                             /* 记录尾部顶点 */
        ep->headvex = loc2;                             /* 记录头部顶点 */
        ep->taillink = cp->crosslist[loc1].firstout;    /* 插入到尾部顶点的出度邻接表 */
        cp->crosslist[loc1].firstout = ep;
        ep->headlink = cp->crosslist[loc2].firstin;     /* 插入到头部顶点的入度邻接表 */
        cp->crosslist[loc2].firstin = ep;
        ep->weight = e;
        return 1;
    }
    return 0;
}


/* DeleteVex: 删除图中的顶点v */
int DeleteVex(GraphCrossAdj *cp, VertexType v){
    EdgeNode *ep, *tp, *kp;
    int i;

    if ((i = LocateVex(*cp, v)) == -1){
        printf("Error: no vertex %c\n", v);
        return 0;
    }

    ep = cp->crosslist[i].firstout;             /* 循环顶点v的出度邻接表 */
    while (ep){
        tp = ep;
        ep = tp->taillink;

        kp = cp->crosslist[tp->headvex].firstin;    /* 循环邻接表中头部顶点的入度邻接表 */
        if (kp == tp){
            cp->crosslist[tp->headvex].firstin = tp->headlink;
        } else {
            while (kp->headlink != tp)
                kp = kp->headlink;
            kp->headlink = tp->headlink;
        }
        free(tp);
    }

    ep = cp->crosslist[i].firstin;              /* 循环顶点v的入度邻接表 */
    while (ep){
        tp = ep;
        ep = tp->headlink;

        kp = cp->crosslist[tp->tailvex].firstout;   /* 循环邻接表中尾部部顶点的出度邻接表 */
        if (kp == tp){
            cp->crosslist[tp->tailvex].firstout = tp->taillink;
        } else {
            while (kp->taillink != tp)
                kp = kp->taillink;
            kp->taillink = tp->taillink;
        }
        free(tp);
    }

    MoveVex(cp, cp->numVertexes-1, i);          /* 将顶点列表中的最后一个移动到待删顶点的位置，同时修改移动顶点的相关边信息 */
    cp->numVertexes--;
    return 1;
}


/* MoveVex: 将下标为from_loc的顶点移至下标为to_loc，同时修改相关邻接表中的下标信息 */
void MoveVex(GraphCrossAdj *cp, int from_loc, int to_loc){
    EdgeNode *ep;

    ep = cp->crosslist[from_loc].firstout;      /* 循环待移动顶点的出度邻接表 */
    while (ep){
        ep->tailvex = to_loc;
        ep = ep->taillink;
    }

    ep = cp->crosslist[from_loc].firstin;       /* 循环待移动顶点的入度邻接表 */
    while (ep){
        ep->headvex = to_loc;
        ep = ep->headlink;
    }

    cp->crosslist[to_loc].data = cp->crosslist[from_loc].data;          /* 将from_loc顶点移动到to_loc */
    cp->crosslist[to_loc].firstin = cp->crosslist[from_loc].firstin;
    cp->crosslist[to_loc].firstout = cp->crosslist[from_loc].firstout;
}


/* DeleteEdge: 删除图中有向边(v1, v2) */
int DeleteEdge(GraphCrossAdj *cp, VertexType v1, VertexType v2){
    int loc1, loc2;
    EdgeNode *ep, *tp;

    if ((loc1 = LocateVex(*cp, v1)) == -1 || (loc2 = LocateVex(*cp, v2)) == -1){
        printf("Error: no vertex\n");
        return 0;
    }

    if (!HasEdge(*cp, v1, v2)){
        printf("Error: no edge (%c, %c)\n", v1, v2);
        return 0;
    }

    ep = cp->crosslist[loc1].firstout;                  /* 循环顶点v1的出度邻接表，找到待删边，删除链接 */
    if (ep->headvex == loc2){
        cp->crosslist[loc1].firstout = ep->taillink;
        tp = ep;                                        /* 将待删边赋值给tp */
    } else {
        while (ep->taillink->headvex != loc2)
            ep = ep->taillink;
        tp = ep->taillink;
        ep->taillink = tp->taillink;
    }
    
    ep = cp->crosslist[loc2].firstin;                   /* 循环顶点v2的入度邻接表，找到待删边, 删除链接 */
    if (ep == tp){
        cp->crosslist[loc2].firstin = tp->headlink;
    } else {
        while (ep->headlink != tp)
            ep = ep->headlink;
        ep->headlink = tp->headlink;
    }

    free(tp);                                           
    return 1;
}


/* PrintVertexes: 打印所有顶点 */
void PrintVertexes(GraphCrossAdj G){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        printf("Vertex_%02d: %c\n", i+1, G.crosslist[i].data);
}


/* PrintEdges: 打印所有边 */
void PrintEdges(GraphCrossAdj G){
    int i, n;
    EdgeNode *ep;

    n = 0;
    for (i = 0; i < G.numVertexes; i++){    /* 循环顶点 */
        ep = G.crosslist[i].firstout;       /* 循环当前顶点的出度邻接表 */
        while (ep){
            printf("Edge_%2d: (%c, %c, %d)\n", ++n, G.crosslist[ep->tailvex].data, G.crosslist[ep->headvex].data, ep->weight);
            ep = ep->taillink;
        }
    }
}


/* PrintCrossAdj: 打印每个顶点的出度、入度邻接表 */
void PrintCrossAdj(GraphCrossAdj G){
    int i;
    EdgeNode *ep;

    for (i = 0; i < G.numVertexes; i++){
        printf("Vertex: %c\n", G.crosslist[i].data);

        printf("\tout: ");
        ep = G.crosslist[i].firstout;       /* 循环当前顶点的出度邻接表 */
        while (ep){
            printf("(%c, %c, %d) ", G.crosslist[ep->tailvex].data, G.crosslist[ep->headvex].data, ep->weight);
            ep = ep->taillink;
        }
        printf("\n");

        printf("\tin: ");
        ep = G.crosslist[i].firstin;       /* 循环当前顶点的入度邻接表 */
        while (ep){
            printf("(%c, %c, %d) ", G.crosslist[ep->tailvex].data, G.crosslist[ep->headvex].data, ep->weight);
            ep = ep->headlink;
        }
        printf("\n");
    }
}