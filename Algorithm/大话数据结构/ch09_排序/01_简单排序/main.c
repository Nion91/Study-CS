#include <stdio.h>
#include <time.h>
#include "SimpleSort.h"

main(){
    SqlList L;

    printf("\n==============================SimpleSort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    SimpleSort(&L);
    PrintSqlList(L);

    printf("\n==============================BubbleSort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    BubbleSort(&L);
    PrintSqlList(L);

    printf("\n==============================BubbleSort2============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    BubbleSort2(&L);
    PrintSqlList(L);

    printf("\n==============================SelectSort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    SelectSort(&L);
    PrintSqlList(L);

    printf("\n==============================Test============================\n");
    Test(SimpleSort, 100);
    Test(BubbleSort, 100);
    Test(BubbleSort2, 100);
    Test(SelectSort, 100);
}



