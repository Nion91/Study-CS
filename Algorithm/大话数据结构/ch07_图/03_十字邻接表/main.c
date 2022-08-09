#include <stdio.h>
#include <stdlib.h>
#include "GraphCrossAdj.h"


main(){
    GraphCrossAdj *cp;    
    /* 初始化图 */
    /* 输入：
    2, 1
    AB
    1, 0, 1
    */
    printf("==============================init_graph============================\n");
    cp = CreateCrossALGraph();


    /* 打印测试 */
    printf("\n==============================print_graph============================\n");
    PrintVertexes(*cp);
    printf("\n");
    PrintEdges(*cp);
    printf("\n");
    PrintCrossAdj(*cp);


    /* 插入顶点和边 */
    printf("\n==============================insert============================\n");
    InsertVex(cp, 'C');
    InsertVex(cp, 'D');
    InsertEdge(cp, 'B', 'C', 1);
    InsertEdge(cp, 'C', 'B', 1);
    InsertEdge(cp, 'A', 'D', 2);
    InsertEdge(cp, 'C', 'A', 3);

    PrintVertexes(*cp);
    printf("\n");
    PrintEdges(*cp);
    printf("\n");
    PrintCrossAdj(*cp);

    /* 删除顶点 */
    printf("\n==============================delete_vex============================\n");
    DeleteVex(cp, 'E');
    DeleteVex(cp, 'C');

    PrintVertexes(*cp);
    printf("\n");
    PrintEdges(*cp);
    printf("\n");
    PrintCrossAdj(*cp);

    /* 删除边 */
    printf("\n==============================delete_edge============================\n");
    DeleteEdge(cp, 'B', 'D');
    DeleteEdge(cp, 'A', 'D');

    PrintVertexes(*cp);
    printf("\n");
    PrintEdges(*cp);
    printf("\n");
    PrintCrossAdj(*cp);
}

