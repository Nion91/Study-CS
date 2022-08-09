#define MAXVEX 100

/* 定义数据结构 */
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
    int tailvex, headvex;                   /* 记录边的尾部和头部的邻接点 */
    struct EdgeNode *taillink, *headlink;   /* 记录下一个相同尾部顶点、头部顶点的边指针 */
    EdgeType weight;
} EdgeNode;

typedef struct {
    VertexType data;
    EdgeNode *firstout, *firstin;           /* 记录第一个出度、入度的边的指针 */
} VertexNode, CrossAdjList[MAXVEX];

typedef struct {
    CrossAdjList crosslist;
    int numVertexes, numEdges;
} GraphCrossAdj;



/* 定义操作 */
GraphCrossAdj * CreateCrossALGraph(void);
void DestroyGraph(GraphCrossAdj *ap);
int HasVex(GraphCrossAdj G, VertexType v);
int HasEdge(GraphCrossAdj G, VertexType v1, VertexType v2);
int LocateVex(GraphCrossAdj G, VertexType v);
int InsertVex(GraphCrossAdj *ap, VertexType v);
void MoveVex(GraphCrossAdj *cp, int from_loc, int to_loc);
int InsertEdge(GraphCrossAdj *ap, VertexType v1, VertexType v2, EdgeType e);
int DeleteVex(GraphCrossAdj *ap, VertexType v);
int DeleteEdge(GraphCrossAdj *ap, VertexType v1, VertexType v2);
void PrintVertexes(GraphCrossAdj G);
void PrintEdges(GraphCrossAdj G);
void PrintCrossAdj(GraphCrossAdj G);



