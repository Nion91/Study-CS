#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjList.h"


main(){
     GraphAdjList *ap;    
    /* 初始化图 */
    /* 输入：
    2, 1
    AB
    0, 1, 1
    */
    printf("==============================init_graph============================\n");
    ap = CreateALGraph();

    /* 打印测试 */
    printf("\n==============================print_graph============================\n");
    PrintVertexes(*ap);
    printf("\n");
    PrintEdges(*ap);
    printf("\n");
    PrintAdjList(*ap);

    /* 插入顶点和边 */
    printf("\n==============================insert============================\n");
    InsertVex(ap, 'C');
    InsertVex(ap, 'D');
    InsertEdge(ap, 'C', 'D', 1);
    InsertEdge(ap, 'A', 'C', 1);
    InsertEdge(ap, 'A', 'D', 2);
    InsertEdge(ap, 'B', 'C', 3);

    PrintVertexes(*ap);
    printf("\n");
    PrintEdges(*ap);
    printf("\n");
    PrintAdjList(*ap);

    /* 删除顶点 */
    printf("\n==============================delete_vex============================\n");
    DeleteVex(ap, 'E');
    DeleteVex(ap, 'C');
    

    PrintVertexes(*ap);
    printf("\n");
    PrintEdges(*ap);
    printf("\n");
    PrintAdjList(*ap);

    /* 删除边 */
    printf("\n==============================delete_edge============================\n");
    DeleteEdge(ap, 'B', 'D');
    DeleteEdge(ap, 'A', 'D');

    PrintVertexes(*ap);
    printf("\n");
    PrintEdges(*ap);
    printf("\n");
    PrintAdjList(*ap);

    /* 深度遍历 */
    printf("\n==============================DFS============================\n");
    char *ch;
    int k;
    
    ch = "CDEFGHI";
    for (k = 0; k < 7; k++)
        InsertVex(ap, *(ch + k));
    
    InsertEdge(ap, 'B', 'C', 1);
    InsertEdge(ap, 'B', 'I', 1);
    InsertEdge(ap, 'C', 'I', 1);
    InsertEdge(ap, 'D', 'C', 1);
    InsertEdge(ap, 'D', 'I', 1);
    InsertEdge(ap, 'D', 'G', 1);
    InsertEdge(ap, 'D', 'H', 1);
    InsertEdge(ap, 'D', 'E', 1);
    InsertEdge(ap, 'G', 'H', 1);
    InsertEdge(ap, 'A', 'F', 1);
    InsertEdge(ap, 'F', 'G', 1);
    InsertEdge(ap, 'B', 'G', 1);
    InsertEdge(ap, 'H', 'E', 1);
    InsertEdge(ap, 'F', 'E', 1);

    DFSTraverse(*ap);
}




