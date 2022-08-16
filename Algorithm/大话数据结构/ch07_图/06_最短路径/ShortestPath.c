#include <stdio.h>
#include "ShortestPath.h"


/* ShortestPath_Dijkstra: 用Dijkstra算法计算顶点v到其他点的最短路径 */
void ShortestPath_Dijkstra(MGraph G, VertexType v, PathMatrix *mp, ShortWeight *sp){
    int is_visited[MAXVEX];         /* 保存顶点是否已被访问过 */
    int i, j, loc;
    int min_val, min_vex;

    loc = LocateVertex(G, v);
    for (i = 0; i < G.numVertexes; i++){    /* 初始化3个数组 */
        (*sp)[i] = G.arc[loc][i];           /* 初始化为源点v到其他顶点的距离 */
        (*mp)[i] = loc;                     /* 各顶点的前驱点初始化为v */
        is_visited[i] = 0;
    }

    (*sp)[loc] = 0;
    is_visited[loc] = 1;

    for (i = 1; i < G.numVertexes; i++){            /* 进行n-1轮循环，每轮找出距离v最近的点 */
        min_val = INFINITY;
        for (j = 0; j < G.numVertexes; j++){        /* 根据ShortWeight列表找最近的顶点 */
            if (!is_visited[j] && (*sp)[j] < min_val){
                min_val = (*sp)[j];
                min_vex = j;
            }
        }
        
        is_visited[min_vex] = 1;
        printf("(V%c, V%c): %d\n", G.vexs[(*mp)[min_vex]], G.vexs[min_vex], min_val);

        for (j = 0; j < G.numVertexes; j++){        /* 根据本轮找出的顶点更新ShortWeight列表 */
            if (!is_visited[j] && (min_val + G.arc[min_vex][j] < (*sp)[j])){   /* 如果以本轮顶点为中转点，到达目的点更近，则更新目标点的权值和 */
                (*sp)[j] = min_val + G.arc[min_vex][j];
                (*mp)[j] = min_vex;
            }
        }
    }
}




/* ShortestPath_Floyd: 用Floyd算法计算出每个顶点到每个顶点的最短路径 */
void ShortestPath_Floyd(MGraph G, PathMatrix2 *mp, ShortWeight2 *sp){
    int i, j, k;

    for (i = 0; i < G.numVertexes; i++){            /* 初始化2个矩阵 */
        for (j = 0; j < G.numVertexes; j++){
            (*sp)[i][j] =  G.arc[i][j];
            (*mp)[i][j] = j;
        }
    }

    for (i = 0; i < G.numVertexes; i++)             /* 对角线设为零 */
        (*sp)[i][i] = 0;

    for (i = 0; i < G.numVertexes; i++){            /* 进行三层嵌套 */
        for (j = 0; j < G.numVertexes; j++){
            for (k = 0; k < G.numVertexes; k++){
                if ((*sp)[i][k] + (*sp)[k][j] < (*sp)[i][j]){   /* 计算vi经过vk到vj的距离是否更短，如果更短，更新2个矩阵 */
                    (*sp)[i][j] = (*sp)[i][k] + (*sp)[k][j];
                    (*mp)[i][j] = (*mp)[i][k];
                }
            }
        }
    }
}


/* PrintPath_a_to_b: 打印v1到v2的最短路径 */
void PrintPath_a_to_b(MGraph G, VertexType v1, VertexType v2, PathMatrix2 mp){
    int i, j;
    int loc1, loc2;

    loc1 = LocateVertex(G, v1);
    loc2 = LocateVertex(G, v2);

    i = mp[loc1][loc2];
    printf("(V%c, V%c): %d\n", G.vexs[loc1], G.vexs[i], G.arc[loc1][i]);

    while (i != loc2){
        j = mp[i][loc2];
        printf("(V%c, V%c): %d\n", G.vexs[i], G.vexs[j], G.arc[i][j]);
        i = j;
    }
}


/* PrintPath_a_to_all: 打印v到所有顶点的最短路径 */
void PrintPath_a_to_all(MGraph G, VertexType v, PathMatrix2 mp, ShortWeight2 sp){
    int i, k, loc, tmp;

    loc = LocateVertex(G, v);

    for (i = 0; i < G.numVertexes; i++){                /* 循环打印到每个顶点的最短路径 */
        if (loc == i)
            continue;
        printf("V%c to V%c: ", G.vexs[loc], G.vexs[i]);

        k = mp[loc][i];
        printf("V%c--(%d)-->V%c", G.vexs[loc], G.arc[loc][k], G.vexs[k]);

        while (k != i){
            tmp = mp[k][i];
            printf("--(%d)-->V%c", G.arc[k][tmp], G.vexs[tmp]);
            k = tmp;
        }
        printf("    total: %d\n", sp[loc][i]);
    }
}



