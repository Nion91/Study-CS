#include <stdio.h>
#include <stdlib.h>
#include "MiniSpanTree.h"

main(){
    MGraph *gp;    
    /* 初始化图 */
    /* 输入：
    2, 1
    AB
    0, 1, 10
    */
    printf("==============================init_graph============================\n");
    gp = CreateMGraph();

    char *ch, *e1, *e2;
    int k;
    int w[] = {18, 12, 8, 22, 21, 24, 16, 20, 19, 11, 17, 16, 7, 26};
    
    ch = "CDEFGHI";
    for (k = 0; k < 7; k++)
        InsertVex(gp, *(ch + k));

    e1 = "BBCDDDDDGAFBHF";
    e2 = "CIICIGHEHFGGEE";
    for (k = 0; k < 14; k++)
        InsertEdge(gp, *(e1 + k), *(e2 + k), w[k]);

    PrintVertexes(*gp);
    PrintEdges(*gp);
    
    printf("\n==============================Prim============================\n");
    MiniSpanTree_Prim(*gp);

    printf("\n==============================Kruskal============================\n");
    
    Edge edgelist[gp->numEdges];
    //InitEdgeList(*gp, edgelist);
    //QuickSortEdgeList(edgelist, 0, gp->numEdges-1);
    //PrintEdgeList(edgelist, gp->numEdges);

    MiniSpanTree_Kruskal(*gp);
    
}

