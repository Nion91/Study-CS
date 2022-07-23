#include <stdio.h>
#include <stdlib.h>
#include "LoopLinklist.h"


void PrintList(LoopLinkList L);

main(){
    LoopLinkList L, *lp;
    lp = &L;
    int i;

    /*初始化*/
    printf("==============init===============\n");
    CreateListHead(lp,3);
    PrintList(L);

    /*插入*/
    printf("==============insert===============\n");
    ListInsert(lp, 1, 1);
    ListInsert(lp, 1, 2);
    ListInsert(lp, 2, 3);
    ListInsert(lp, 7, 4);
    ListInsert(lp, 11, 10);
    PrintList(L);

    /*删除*/
    printf("==============delete===============\n");
    ListDelete(lp, 1, &i);
    ListDelete(lp, 5, &i);
    ListDelete(lp, 5, &i);
    PrintList(L);
    ListDelete(lp,10, &i);

    /*查找*/
    printf("==============find===============\n");
    printf("has: %d\n", HasElem(L, 3));
    printf("length: %d\n", ListLength(L));

    /*清除*/
    printf("==============clear===============\n");
    ClearList(lp);
    PrintList(L);
}



void PrintList(LoopLinkList L){
    LoopLinkList lp;
    lp = L->next;
    while (lp->next != L->next){
        lp = lp->next;
        printf("%d\n", lp->data);
    }
}
