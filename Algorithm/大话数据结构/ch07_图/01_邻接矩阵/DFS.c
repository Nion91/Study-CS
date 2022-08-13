#include <stdio.h>
#include "MGraph.h"

int is_visited[MAXVEX];         /* 存储顶点是否已被访问过 */

/* DFS: 单个连通图的深度优先遍历 */
void DFS(MGraph G, int loc){
    int i;

    is_visited[loc] = 1;
    printf("%c\n", G.vexs[loc]);

    for (i = 0; i < G.numVertexes; i++)
        if (!is_visited[i] && G.arc[loc][i] != INFINITY)
            DFS(G, i);
}


/* DFSTraverse: 整颗树的深度优先遍历 */
void DFSTraverse(MGraph G){
    int i;

    for (i = 0; i < G.numVertexes; i++)
        is_visited[i] = 0;

    for (i = 0; i < G.numVertexes; i++)
        if (!is_visited[i])
            DFS(G, i);
}