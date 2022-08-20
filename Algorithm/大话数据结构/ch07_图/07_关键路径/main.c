#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DiGraphAdjList.h"


main(){
    DiGraphAdjList *ap;    
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

    printf("%d\n", HasEdge(*ap, 'A', 'D'));

    PrintVertexes(*ap);
    printf("\n");
    PrintEdges(*ap);
    printf("\n");
    PrintAdjList(*ap);


    /* 拓扑排序 */
    printf("\n==============================topological============================\n");
    DeleteEdge(ap, 'A', 'B');

    char *ch, *e1, *e2;
    int k;
    
    ch = "CDEFGHIJKLMN";
    for (k = 0; k < strlen(ch); k++)
        InsertVex(ap, *(ch + k));

    e1 = "AAABBBCCCDDEFFGIJJKM";
    e2 = "EFLECIFGJCNHIMFHKLNJ";
    for (k = 0; k < strlen(e1); k++)
        InsertEdge(ap, *(e1 + k), *(e2 + k), 1);

    /*TopologicalSort(ap);*/
    TopologicalSort_2(ap);

    /* 关键路径 */
    printf("\n==============================key_path============================\n");
    /* 初始化输入：
    2, 1
    01
    0, 1, 3
    */
    int w[] = {4, 5, 6, 8, 7, 3, 9, 4, 6, 2, 5, 3};
    ap = CreateALGraph();

    ch = "23456789";
    for (k = 0; k < strlen(ch); k++)
        InsertVex(ap, *(ch + k));

    e1 = "011223445678";
    e2 = "234354677989";
    for (k = 0; k < strlen(e1); k++)
        InsertEdge(ap, *(e1 + k), *(e2 + k), w[k]);

    PrintAdjList(*ap);

    printf("\n");
    printf("key_path: \n");
    CriticalPath(*ap);
}
