#include <stdio.h>
#include <stdlib.h>
#include "GraphMultiAdj.h"


main(){
    GraphMultiAdj *mp;    
    /* 初始化图 */
    /* 输入：
    2, 1
    AB
    1, 0, 1
    */
    printf("==============================init_graph============================\n");
    mp = CreateMultiALGraph();


    /* 打印测试 */
    printf("\n==============================print_graph============================\n");
    PrintVertexes(*mp);
    printf("\n");
    PrintEdges(*mp);
    printf("\n");
    PrintMultiAdj(*mp);

    /* 插入顶点和边 */
    printf("\n==============================insert============================\n");
    InsertVex(mp, 'C');
    InsertVex(mp, 'D');
    InsertEdge(mp, 'B', 'C', 1);
    InsertEdge(mp, 'C', 'B', 1);
    InsertEdge(mp, 'A', 'D', 2);
    InsertEdge(mp, 'C', 'A', 3);

    PrintVertexes(*mp);
    printf("\n");
    PrintEdges(*mp);
    printf("\n");
    PrintMultiAdj(*mp);

    /* 删除顶点 */
    printf("\n==============================delete_vex============================\n");
    DeleteVex(mp, 'E');
    DeleteVex(mp, 'C');

    PrintVertexes(*mp);
    printf("\n");
    PrintEdges(*mp);
    printf("\n");
    PrintMultiAdj(*mp);

    /* 删除边 */
    printf("\n==============================delete_edge============================\n");
    DeleteEdge(mp, 'B', 'D');
    DeleteEdge(mp, 'A', 'D');

    PrintVertexes(*mp);
    printf("\n");
    PrintEdges(*mp);
    printf("\n");
    PrintMultiAdj(*mp);
}

