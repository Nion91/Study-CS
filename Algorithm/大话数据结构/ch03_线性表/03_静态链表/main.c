#include <stdio.h>
#include <stdlib.h>
#include "StaticLinkList.h"


void PrintList(StaticLinkList L);

main(){
    StaticLinkList L;
    int i;

    /*初始化*/
    printf("==============init===============\n");
    InitList(L);
    PrintList(L);

    /*插入*/
    printf("==============insert===============\n");
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 3);
    ListInsert(L, 2, 5);
    ListInsert(L, 10, 10);
    PrintList(L);

    /*删除*/
    printf("==============delete===============\n");
    ListDelete(L, 1, &i);
    printf("Delete: %d\n", i);
    ListDelete(L, 10, &i);
    PrintList(L);

    /*查找*/
    printf("==============find===============\n");
    GetElem(L, 2, &i);
    printf("get: %d\n", i);

    printf("has: %d\n", HasElem(L, 3));
    printf("has: %d\n", HasElem(L, 4));
    printf("length: %d\n", ListLength(L));

    /*清除*/
    printf("==============clear===============\n");
    ClearList(L);
    int k;
    for (i = MAXSIZE - 1, k = 1; k <= MAXSIZE; k++){
        printf("idx: %d, cur: %d\n", i, L[i].cur);
        i = L[i].cur;
    }
    PrintList(L);
}



void PrintList(StaticLinkList L){
    int k;
    k = L[MAXSIZE - 1].cur;
    while (k){
        printf("%d ", L[k].data);
        k = L[k].cur;
    }
    printf("\n");
}
