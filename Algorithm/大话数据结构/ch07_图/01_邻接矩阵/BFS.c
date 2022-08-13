#include <stdio.h>
#include "MGraph.h"
#include "..\..\第04章_栈和队列\05_循环队列\SqQueue.h"


/* BFSTraverse: 整颗树的广度优先遍历 */
void BFSTraverse(MGraph G){
    int i, j, k;
    SqQueue *qp;
    int is_visited[MAXVEX];

    for (i = 0; i < G.numVertexes; i++)             /* 初始化访问状态 */
        is_visited[i] = 0;

    qp = InitQueue();                               /* 初始化队列 */

    for (i = 0; i < G.numVertexes; i++){            /* 循环顶点，如果未访问过，压入队列 */
        if (!is_visited[i]){
            is_visited[i] = 1;
            printf("%c\n", G.vexs[i]);
            EnQueue(qp, i);

            while (!QueueEmpty(*qp)){               /* 循环弹出顶点，直到队列为空 */
                DeQueue(qp, &j);
                for (k = 0; k < G.numVertexes; k++){        /* 循环出队顶点的邻接矩阵，将未访问顶点入队 */
                    if (is_visited[k] || G.arc[j][k] == INFINITY)
                        continue;
                    is_visited[k] = 1;
                    printf("%c\n", G.vexs[k]);
                    EnQueue(qp, k);
                }
            }
        }
    }
}