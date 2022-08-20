#define MAXVEX 100

/* 有向图的邻接表结构 */
/* 定义数据结构 */
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct {
    VertexType data;
    EdgeNode *firstedge;
    int in;                         /* 增加对顶点的入度统计 */
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjlist;
    int numVertexes, numEdges;
} DiGraphAdjList;


/* 定义操作 */
DiGraphAdjList * CreateALGraph(void);
void DestroyGraph(DiGraphAdjList *ap);
int HasVex(DiGraphAdjList G, VertexType v);
int HasEdge(DiGraphAdjList G, VertexType v1, VertexType v2);
int LocateVex(DiGraphAdjList G, VertexType v);
int InsertVex(DiGraphAdjList *ap, VertexType v);
int InsertEdge(DiGraphAdjList *ap, VertexType v1, VertexType v2, EdgeType e);
int DeleteVex(DiGraphAdjList *ap, VertexType v);
int DeleteEdge(DiGraphAdjList *ap, VertexType v1, VertexType v2);
void MoveVex(DiGraphAdjList *ap, int from_loc, int to_loc);
void PrintVertexes(DiGraphAdjList G);
void PrintEdges(DiGraphAdjList G);
void PrintAdjList(DiGraphAdjList G);


/* 拓扑排序 */
int TopologicalSort(DiGraphAdjList *dp);
int TopologicalSort_2(DiGraphAdjList *gl);

/* 关键路径 */
int TopologicalSort_KeyPath(DiGraphAdjList *gl);
void CriticalPath(DiGraphAdjList G);


