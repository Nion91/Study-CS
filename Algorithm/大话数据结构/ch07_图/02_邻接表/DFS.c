#include "GraphAdjList.h"
#include <stdio.h>

int is_visited[MAXVEX];     /* 存储顶点是否已被访问 */

/* DFS: 针对连通图的深度优先遍历 */
void DFS(GraphAdjList G, int loc){
    EdgeNode *ep;

    is_visited[loc] = 1;
    printf("%c\n", G.adjlist[loc].data);

    for (ep = G.adjlist[loc].firstedge; ep; ep = ep->next)
        if (!is_visited[ep->adjvex])
            DFS(G, ep->adjvex);
}

/* DFSTraverse: 整颗树的深度优先遍历 */
void DFSTraverse(GraphAdjList G){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        is_visited[i] = 0;

    for (i = 0; i < G.numVertexes; i++)
        if (!is_visited[i])
            DFS(G, i);
}

