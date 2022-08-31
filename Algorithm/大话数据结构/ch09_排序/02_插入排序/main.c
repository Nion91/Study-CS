#include <stdio.h>
#include <time.h>
#include "InsertSort.h"

main(){
    SqlList L;

    printf("\n==============================Insertsort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    InsertSort(&L);
    PrintSqlList(L);

    printf("\n==============================ShellSort============================\n");
    InitSqlList(&L, 10);
    PrintSqlList(L);
    ShellSort(&L);
    PrintSqlList(L);

    printf("\n==============================Test============================\n");
    Test(InsertSort, 100);
    Test(ShellSort, 100);
}



