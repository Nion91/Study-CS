#include <stdio.h>
#include <stdlib.h>
#include "DiGraphAdjList.h"

/* 公共变量 */
int early_time[MAXVEX];     /* 保存顶点的最早开始时间 */
int late_time[MAXVEX];      /* 保存顶点的最晚开始时间 */
int stack2[MAXVEX];         /* 保存拓扑排序 */
int top2;                   /* stack2的栈指针 */

/* TopologicalSort_KeyPath: 用于搜索关键路径的拓扑排序 
   算法逻辑：
   1. 按拓扑排序的顺序计算所有顶点的最早时间
   2. 以拓扑排序的倒序顺序，即终点开始，倒推计算所有点的最晚时间
   3. 根据出度点的最早时间、入度点的最晚时间，计算边的最早、最晚时间
   4. 根据边的最早时间=最晚时间判断关键路径 
*/
int TopologicalSort_KeyPath(DiGraphAdjList *gl){
    int i, k, count;
    int *stack;
    int top;
    EdgeNode *ep, *kp;
    int in_count[gl->numVertexes];

    stack = (int *)malloc(gl->numVertexes * sizeof(int));       /* 初始化用于拓扑排序的栈 */
    top = 0;

    top2 = 0;
    count = 0;

    for (i = 0; i <gl->numVertexes; i++){                       
        early_time[i] = 0;                      /* 初始化顶点最早开始时间 */
        in_count[i] = gl->adjlist[i].in;        /* 搜索入度为0的顶点 */
        if (in_count[i] == 0)
            stack[top++] = i;
    }

    while (top > 0){                            /* 循环弹出入度为0的顶点 */
        k = stack[--top];
        count++;
        stack2[top2++] = k;                     /* 存储拓扑排序 */

        for (ep = gl->adjlist[k].firstedge; ep; ep = ep->next){         /* 循环出栈点的邻接点 */
            if (early_time[ep->adjvex] < early_time[k] + ep->weight)    /* 更新邻接点的最早开始时间 */
                early_time[ep->adjvex] = early_time[k] + ep->weight;
            
            if (--in_count[ep->adjvex] == 0)                            /* 更新邻接点的入度 */
                stack[top++] = ep->adjvex;
        }
    }

    return count == gl->numVertexes ? 1 : 0;
}


/* CriticalPath: 搜索无环AOV(有向带权重图)的关键路径 */
void CriticalPath(DiGraphAdjList G){
    int gettop, lt, i, max_et;
    int edge_et, edge_lt;       /* 边的最早、最晚时间 */
    EdgeNode *ep;

    if (!TopologicalSort_KeyPath(&G)){                  /* 执行一次拓扑排序，得到顶点的最早开始时间 */
        printf("Error: wrong topological sort\n");
        return;
    }

    max_et = early_time[0];                             /* 取所有顶点的最大最早发生时间 */
    for (i = 1; i < G.numVertexes; i++)
        if (max_et < early_time[i])
            max_et = early_time[i];

    while (top2 > 0){                                   /* 计算每个顶点的最晚发生时间 */
        gettop = stack2[--top2];
        lt = max_et;

        ep = G.adjlist[gettop].firstedge;
        while (ep){                                     /* 循环邻接点，根据邻接点和边权重，计算出度点的最晚时间 */
            if (late_time[ep->adjvex] - ep->weight < lt)
                lt = late_time[ep->adjvex] - ep->weight;
            ep = ep->next;
        }

        late_time[gettop] = lt;
    }

    for (i = 0; i < G.numVertexes; i++){                    /* 计算每条边的最早、最晚发生时间 */
        for (ep = G.adjlist[i].firstedge; ep; ep = ep->next){
            edge_et = early_time[i];                        /* 取出度点的最早时间为边的最早时间 */
            edge_lt = late_time[ep->adjvex] - ep->weight;   /* 取入度点的最晚时间，再减权重，为边的最晚时间 */
            if (edge_et == edge_lt){                        /* 如果边的最早时间等于最晚时间，则判为关键路径 */
                printf("(V%c, V%c, %d)\n", G.adjlist[i].data, G.adjlist[ep->adjvex].data, ep->weight);
            }
        }
    }
    
}

