#include <stdio.h>
#include <time.h>
#include "RecurSort.h"

main(){
    SqlList L;

    printf("\n==============================Mergesort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    MergeSort(&L);
    PrintSqlList(L);

    printf("\n==============================Mergesort2============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    MergeSort2(&L);
    PrintSqlList(L);

    printf("\n==============================Test============================\n");
    Test(MergeSort, 100);
    Test(MergeSort2, 100);
}
