#define MAXVEX 100
#define INFINITY 65535

/* 定义数据结构 */
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vexs[MAXVEX];        /* 顶点集 */
    EdgeType arc[MAXVEX][MAXVEX];   /* 邻接矩阵 */
    int numVertexes, numEdges;
} MGraph;



/* 定义操作 */
MGraph * CreateMGraph(void);
void DestroyGraph(MGraph *gp);
int HasVertex(MGraph G, VertexType v);
int HasEdge(MGraph G, VertexType v1, VertexType v2);
int LocateVertex(MGraph G, VertexType v);
void InsertVex(MGraph *gp, VertexType v);
void InsertEdge(MGraph *gp, VertexType v1, VertexType v2, EdgeType e);
int DeleteVex(MGraph *gp, VertexType v);
int DeleteEdge(MGraph *gp, VertexType v1, VertexType v2);
void PrintVertexes(MGraph G);
void PrintEdges(MGraph G);
void PrintMatrix(MGraph G);






