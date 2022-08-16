#include "MGraph.h"


/* Dijkstra算法 */
typedef int PathMatrix[MAXVEX];     /* 保存最短路径下每个顶点的前驱顶点的下标 */
typedef int ShortWeight[MAXVEX];    /* 保存到源点到其他各顶点的最短路径的weight之和 */

void ShortestPath_Dijkstra(MGraph G, VertexType v, PathMatrix *mp, ShortWeight *sp);


/* Floyd算法 */
typedef int ShortWeight2[MAXVEX][MAXVEX];   /* 保存顶点到顶点的最短路径权值 */
typedef int PathMatrix2[MAXVEX][MAXVEX];    /* 保存对应顶点的最小路径的前驱矩阵 */

void ShortestPath_Floyd(MGraph G, PathMatrix2 *mp, ShortWeight2 *sp);
void PrintPath_a_to_b(MGraph G, VertexType v1, VertexType v2, PathMatrix2 mp);
void PrintPath_a_to_all(MGraph G, VertexType v, PathMatrix2 mp, ShortWeight2 sp);
