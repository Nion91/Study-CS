#include <stdio.h>
#include "GraphAdjList.h"
//#include "..\..\第04章_栈和队列\05_循环队列\SqQueue.h"
#include "SqQueue.h"

/* BFSTraverse: 整颗树的广度优先遍历 */
void BFSTraverse(GraphAdjList G){
    int i, j;
    EdgeNode *ep;
    SqQueue *qp;
    int is_visited[MAXVEX];

    qp = InitQueue();                           /* 初始化队列 */

    for (i = 0; i < G.numVertexes; i++)         /* 初始化化顶点访问状态 */
        is_visited[i] = 0;

    for (i = 0; i < G.numVertexes; i++){        /* 循环顶点，将未访问过的顶点入队 */
        if (is_visited[i])
            continue;
        
        is_visited[i] = 1;
        printf("%c\n", G.adjlist[i].data);
        EnQueue(qp, i);

        while (!QueueEmpty(*qp)){               /* 循环弹出顶点，直到队列为空 */
            DeQueue(qp, &j);
            for (ep = G.adjlist[j].firstedge; ep; ep = ep->next){   /* 循环出队顶点的邻接点 */
                if (is_visited[ep->adjvex])
                    continue;
                is_visited[ep->adjvex] = 1;
                printf("%c\n", G.adjlist[ep->adjvex].data);         /* 打印邻接点 */
                EnQueue(qp, ep->adjvex);                            /* 将邻接点入队 */
            }
        }
    }
}


