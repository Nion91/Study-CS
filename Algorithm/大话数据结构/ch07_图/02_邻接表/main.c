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
}




