#include <stdio.h>
#include <stdlib.h>
#include "DiGraphAdjList.h"

/* TopologicalSort: 用拓扑排序算法检查图是否为不存在回路的AOV网，即有向带权图 */
int TopologicalSort(DiGraphAdjList *dp){
    int i, j;
    EdgeNode *ep;
    int is_visited[dp->numVertexes];        /* 保存顶点是否访问过 */
    int in_count[dp->numVertexes];          /* 保存顶点的入度 */

    for (i = 0; i < dp->numVertexes; i++){
        is_visited[i] = 0;
        in_count[i] = dp->adjlist[i].in;
    }

    for (i = 0; i < dp->numVertexes; i++){                  /* 循环n轮，每轮找出一个入度为0的顶点 */
        for (j = 0; j < dp->numVertexes; j++){
            if (!is_visited[j] && in_count[j] == 0)         /* 循环n个顶点，每轮没有访问且入度为0的顶点 */
                break;
        }

        if (j == dp->numVertexes)                           /* 如果循环完还未找到入度为0的顶点，说明图中有环，返回失败 */
            return 0;

        is_visited[j] = 1;
        printf("%c\n", dp->adjlist[j].data);
        ep = dp->adjlist[j].firstedge;
        while (ep){                                         /* 查找入度为0的顶点的邻接点，修改这些点的入度值 */
            in_count[ep->adjvex]--;
            ep = ep->next;
        }
    }

    return 1;
}

/* TopologicalSort_2: 用栈实现拓扑排序 */
int TopologicalSort_2(DiGraphAdjList *gl){
    int i, count, k;
    int *stack, top;
    int in_count[gl->numVertexes];
    EdgeNode *ep;

    stack = (int *)malloc(gl->numVertexes * sizeof(int));   /* 构造栈 */
    top = 0;                                                /* 栈指针 */

    count = 0;
    for (i = 0; i < gl->numVertexes; i++){
        in_count[i] = gl->adjlist[i].in;
        if (in_count[i] == 0){
            stack[top++] = i;               /* 如果入度为0，压入栈 */
            count++;
        }
    }

    while (top > 0){                        /* 循环弹出栈顶 */
        k = stack[--top];
        printf("%c\n", gl->adjlist[k].data);
        
        for (ep = gl->adjlist[k].firstedge; ep; ep = ep->next){     /* 搜索弹出顶点的出度邻接点 */
            in_count[ep->adjvex]--;
            if (in_count[ep->adjvex] == 0){
                stack[top++] = ep->adjvex;
                count++;
            }
        }
    }

    return count == gl->numVertexes ? 1 : 0;
}
