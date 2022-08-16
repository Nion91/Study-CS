#include <stdio.h>
#include "ShortestPath.h"

main(){
    MGraph *gp;    
    /* 初始化图 */
    /* 输入：
    2, 1
    01
    0, 1, 1
    */
    printf("==============================init_graph============================\n");
    gp = CreateMGraph();

    char *ch, *e1, *e2;
    int k;
    int w[] = {5, 3, 5, 7, 1, 2, 3, 6, 7, 3, 9, 2, 7, 5, 4};
    
    ch = "2345678";
    for (k = 0; k < 7; k++)
        InsertVex(gp, *(ch + k));

    e1 = "011123342446657";
    e2 = "224344665577878";
    for (k = 0; k < 15; k++)
        InsertEdge(gp, *(e1 + k), *(e2 + k), w[k]);

    PrintVertexes(*gp);
    PrintEdges(*gp);

    printf("vex: %d, edge: %d\n", gp->numVertexes, gp->numEdges);
    
    printf("\n==============================Dijkstra============================\n");
    PathMatrix mp;
    ShortWeight sp;
    ShortestPath_Dijkstra(*gp, '0', &mp, &sp);


    printf("\n==============================Floyd============================\n");
    PathMatrix2 mp2;
    ShortWeight2 sp2;
    ShortestPath_Floyd(*gp, &mp2, &sp2);

    PrintPath_a_to_b(*gp, '0', '8', mp2);
    printf("\n");
    PrintPath_a_to_all(*gp, '0', mp2, sp2);
}
