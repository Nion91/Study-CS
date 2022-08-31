#include <stdio.h>
#include <time.h>
#include "HeapSort.h"

main(){
    SqlList L;

    printf("\n==============================Heapsort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    HeapSort(&L);
    PrintSqlList(L);

    printf("\n==============================Test============================\n");
    Test(HeapSort, 100);
}
