#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GraphAdjList.h"


/* CreateALGraph: 创建图的邻接表 */
GraphAdjList * CreateALGraph(void){
    GraphAdjList *ap;
    int i, m, n, w;
    EdgeNode *ep;

    ap = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    if (!ap)
        return NULL;

    printf("Enter number of vertex and edge:\n");           /* 输入顶点和边的数量 */
    scanf("%d, %d\n", &ap->numVertexes, &ap->numEdges);

    printf("Enter list of vertexes:\n");
    for (i = 0; i < ap->numVertexes; i++){                  /* 输入顶点信息 */
        scanf("%c", &ap->adjlist[i].data);
        ap->adjlist[i].firstedge = NULL;
    }

    for (i = 0; i < ap->numEdges; i++){                     /* 输入边信息 */
        printf("Enter edge info:\n");
        scanf("%d, %d, %d", &m, &n, &w);
        ep = (EdgeNode *)malloc(sizeof(EdgeNode));          /* 对顶点m，添加邻接点n */
        if (ep){
            ep->adjvex = n;
            ep->weight = w;
            ep->next = ap->adjlist[m].firstedge;
            ap->adjlist[m].firstedge = ep;
        }

        ep = (EdgeNode *)malloc(sizeof(EdgeNode));          /* 对顶点n，添加邻接点m */
        if (ep){
            ep->adjvex = m;
            ep->weight = w;
            ep->next = ap->adjlist[n].firstedge;
            ap->adjlist[n].firstedge = ep;
        }
    }

    return ap;
}


/* DestroyGraph: 销毁图 */
void DestroyGraph(GraphAdjList *ap){
    EdgeNode *ep, *tp;
    int i;

    for (i = 0; i < ap->numVertexes; i++){
        ep = ap->adjlist[i].firstedge;
        while (ep){
            tp = ep;
            ep = tp->next;
            free(tp);
        }
    }
    free(ap);
}


/* HasVex: 返回是否存在顶点v */
int HasVex(GraphAdjList G, VertexType v){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        if (G.adjlist[i].data == v)
            return 1;
    return 0;
}


/* HasEdge: 返回图G是否有边(v1, v2) */
int HasEdge(GraphAdjList G, VertexType v1, VertexType v2){
    EdgeNode *ep;
    int loc1, loc2;

    loc1 = LocateVex(G, v1);
    loc2 = LocateVex(G, v2);
    if (loc1 == -1 || loc2 == -1){
        return 0;
    }

    ep = G.adjlist[loc1].firstedge;
    while (ep){
        if (ep->adjvex == loc2)
            return 1;
        ep = ep->next;
    }
    return 0;
}


/* LocateVex: 返回顶点v在图G的顶点列表下标 */
int LocateVex(GraphAdjList G, VertexType v){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        if (G.adjlist[i].data == v)
            return i;
    return -1;
}


/* InsertVex: 在图中新增顶点v */
int InsertVex(GraphAdjList *ap, VertexType v){
    if (HasVex(*ap, v)){
        printf("Error: already has vertex %c\n", v);
        return 0;
    }

    ap->adjlist[ap->numVertexes].data = v;
    ap->adjlist[ap->numVertexes].firstedge = NULL;
    ap->numVertexes++;

    return 1;
}


/* InsertEdge: 在图中新增边(v1, v2, e) */
int InsertEdge(GraphAdjList *ap, VertexType v1, VertexType v2, EdgeType e){
    EdgeNode *ep;
    int loc1, loc2;

    loc1 = LocateVex(*ap, v1);
    loc2 = LocateVex(*ap, v2);
    if (loc1 == -1 || loc2 == -1){
        printf("Error: wrong vertex\n");
        return 0;
    }

    if (HasEdge(*ap, v1, v2)){
        printf("Error: already has edge (%c, %c)\n", v1, v2);
        return 0;
    }

    ep = (EdgeNode *)malloc(sizeof(EdgeNode));      /* 增加顶点v1的邻接点v2 */
    if (ep){
        ep->adjvex = loc2;
        ep->weight = e;
        ep->next = ap->adjlist[loc1].firstedge;
        ap->adjlist[loc1].firstedge = ep;
    }

    ep = (EdgeNode *)malloc(sizeof(EdgeNode));      /* 增加顶点v2的邻接点v1 */
    if (ep){
        ep->adjvex = loc1;
        ep->weight = e;
        ep->next = ap->adjlist[loc2].firstedge;
        ap->adjlist[loc2].firstedge = ep;
    }

    ap->numEdges++;
    return 1;
}


/* DeleteVex: 删除图中顶点v, 及与v相关的边 */
int DeleteVex(GraphAdjList *ap, VertexType v){
    int i, j;
    EdgeNode *ep1, *tp1, *ep2, *tp2;

    if ((i = LocateVex(*ap, v)) == -1){
        printf("Error: no vertex %c\n", v);
        return 0;
    }

    ep1 = ap->adjlist[i].firstedge;
    while (ep1){                                        /* 依次找v的邻接点 */
        tp1 = ep1;
        ep1 = tp1->next;

        j = tp1->adjvex;                                /* 删除邻接点的邻接表中与v相关的边 */
        ep2 = ap->adjlist[j].firstedge;
        if (ep2->adjvex == i){
            ap->adjlist[j].firstedge = ep2->next;
            free(ep2);
        } else {
            while (ep2->next->adjvex != i){
                ep2 = ep2->next;
            }
            tp2 = ep2->next;
            ep2->next = tp2->next;
            free(tp2);
        }

        free(tp1);                                      /* 删除v的邻接表中的边 */
        ap->numEdges--;                                 
    }
    free(ap->adjlist[i].firstedge);

    MoveVex(ap, ap->numVertexes-1, i);                  /* 将顶点数组末尾的顶点移动到待删顶点的位置 */

    ap->numVertexes--;
    return 1;
}


/* DeleteEdge: 删除边(v1, v2) */
int DeleteEdge(GraphAdjList *ap, VertexType v1, VertexType v2){
    EdgeNode *ep, *tp;
    int loc1, loc2;

    if (!HasEdge(*ap, v1, v2)){
        printf("Error: no edge (%c, %c)\n", v1, v2);
        return 0;
    }

    loc1 = LocateVex(*ap, v1);
    loc2 = LocateVex(*ap, v2);

    ep = ap->adjlist[loc1].firstedge;               /* 删除顶点v1的邻接点v2 */
    if (ep->adjvex == loc2){
        ap->adjlist[loc1].firstedge = ep->next;
        free(ep);
    } else {
        while (ep->next->adjvex != loc2)
            ep = ep->next;
        tp = ep->next;
        ep->next = tp->next;
        free(tp);
    }

    ep = ap->adjlist[loc2].firstedge;               /* 删除顶点v2的邻接点v1 */
    if (ep->adjvex == loc1){
        ap->adjlist[loc2].firstedge = ep->next;
        free(ep);
    } else {
        while (ep->next->adjvex != loc1)
            ep = ep->next;
        tp = ep->next;
        ep->next = tp->next;
        free(tp);
    }

    ap->numEdges--;
    return 1;
}


/* MoveVex: 将在from_loc的顶点移动到to_loc位置，同时修改与之相关的边的信息 */
void MoveVex(GraphAdjList *ap, int from_loc, int to_loc){
    EdgeNode *ep, *kp;
    int i;

    if (from_loc < 0 || from_loc >= ap->numVertexes || to_loc < 0 || to_loc >= ap->numVertexes){
        printf("Error: out of range\n");
        return;
    }

    ep = ap->adjlist[from_loc].firstedge;           /* 依次取待移动顶点的邻接点 */
    while (ep){                                     /* 循环邻接点的邻接表，找打待移动顶点，修改adjvex */
        kp = ap->adjlist[ep->adjvex].firstedge;     
        while (kp){
            if (kp->adjvex == from_loc){
                kp->adjvex = to_loc;
                break;
            }
            kp = kp->next;
        }
        ep = ep->next;
    }

    ap->adjlist[to_loc].data = ap->adjlist[from_loc].data;
    ap->adjlist[to_loc].firstedge = ap->adjlist[from_loc].firstedge;
}


/* PrintVertexes: 打印顶点 */
void PrintVertexes(GraphAdjList G){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        printf("Vertex_%02d: %c\n", i+1, G.adjlist[i].data);
}


/* PrintEdges: 打印边 */
void PrintEdges(GraphAdjList G){
    int record[MAXVEX][MAXVEX];
    int i, n;
    EdgeNode *ep;

    n = 0;
    for (i = 0; i < G.numVertexes; i++){        /* 循环每个顶点 */
        ep = G.adjlist[i].firstedge;
        while (ep){                             /* 循环当前顶点的邻接表 */
            if (record[ep->adjvex][i] != 1){    /* 判断是否已打印 */
                printf("Edge_%02d: (%c, %c, %d)\n", ++n, G.adjlist[i].data, G.adjlist[ep->adjvex].data, ep->weight);
                record[i][ep->adjvex] = 1;
            }
            ep = ep->next;
        }
    }
}


/* PrintAdjList: 依次打印每个顶点的邻接表 */
void PrintAdjList(GraphAdjList G){
    int i;
    EdgeNode *ep;

    for (i = 0; i < G.numVertexes; i++){
        printf("Vertex_%c: ", G.adjlist[i].data);
        ep = G.adjlist[i].firstedge;
        while (ep){
            printf("(%c, %c, %d) ", G.adjlist[i].data, G.adjlist[ep->adjvex].data, ep->weight);
            ep = ep->next;
        }
        printf("\n");
    }
}
















