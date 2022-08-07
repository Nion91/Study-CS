#include <stdio.h>
#include <string.h>
#include "MGraph.h"


main(){
    MGraph *gp;    
    /* 初始化图 */
    /* 输入：
    2, 1
    AB
    0, 1, 1
    */
    printf("==============================init_graph============================\n");
    gp = CreateMGraph();

    /* 打印测试 */
    printf("\n==============================print_graph============================\n");
    PrintVertexes(*gp);
    PrintEdges(*gp);
    PrintMatrix(*gp);

    /* 插入顶点和边 */
    printf("\n==============================insert============================\n");
    InsertVex(gp, 'C');
    InsertVex(gp, 'D');
    InsertEdge(gp, 'C', 'D', 1);
    InsertEdge(gp, 'A', 'C', 1);
    InsertEdge(gp, 'A', 'D', 2);
    InsertEdge(gp, 'B', 'C', 3);

    PrintVertexes(*gp);
    PrintEdges(*gp);
    PrintMatrix(*gp);

    /* 删除顶点 */
    printf("\n==============================delete_vex============================\n");
    DeleteVex(gp, 'C');

    PrintVertexes(*gp);
    PrintEdges(*gp);
    PrintMatrix(*gp);

    /* 删除边 */
    printf("\n==============================delete_edge============================\n");
    DeleteEdge(gp, 'B', 'D');
    DeleteEdge(gp, 'A', 'D');

    PrintVertexes(*gp);
    PrintEdges(*gp);
    PrintMatrix(*gp);
}


