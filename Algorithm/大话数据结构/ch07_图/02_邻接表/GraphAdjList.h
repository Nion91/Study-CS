#define MAXVEX 100

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
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjlist;
    int numVertexes, numEdges;
} GraphAdjList;


/* 定义操作 */
GraphAdjList * CreateALGraph(void);
void DestroyGraph(GraphAdjList *ap);
int HasVex(GraphAdjList G, VertexType v);
int HasEdge(GraphAdjList G, VertexType v1, VertexType v2);
int LocateVex(GraphAdjList G, VertexType v);
int InsertVex(GraphAdjList *ap, VertexType v);
int InsertEdge(GraphAdjList *ap, VertexType v1, VertexType v2, EdgeType e);
int DeleteVex(GraphAdjList *ap, VertexType v);
int DeleteEdge(GraphAdjList *ap, VertexType v1, VertexType v2);
void MoveVex(GraphAdjList *ap, int from_loc, int to_loc);
void PrintVertexes(GraphAdjList G);
void PrintEdges(GraphAdjList G);
void PrintAdjList(GraphAdjList G);









