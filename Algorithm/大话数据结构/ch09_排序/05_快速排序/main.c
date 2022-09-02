#include <stdio.h>
#include <time.h>
#include "QuickSort.h"

main(){
    SqlList L;

    printf("\n==============================Quicksort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    QuickSort(&L);
    PrintSqlList(L);

    printf("\n==============================Test============================\n");
    Test(QuickSort, 100);
}
