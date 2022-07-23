#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"


void PrintList(LinkList L);

main(){
    LinkList L, *lp;
    lp = &L;
    int i;

    /*初始化*/
    printf("==============init===============\n");
    CreateListHead(lp,5);
    PrintList(L);

    /*插入*/
    printf("==============insert===============\n");
    ListInsert(lp, 1, 1);
    ListInsert(lp, 2, 3);
    ListInsert(lp, 10, 10);
    PrintList(L);

    /*删除*/
    printf("==============delete===============\n");
    ListDelete(lp, 1, &i);
    ListDelete(lp,10, &i);
    PrintList(L);

    /*查找*/
    printf("==============find===============\n");
    printf("has: %d\n", HasElem(L, 3));
    printf("length: %d\n", ListLength(L));

    /*清除*/
    printf("==============clear===============\n");
    ClearList(lp);
    PrintList(L);
}



void PrintList(LinkList L){
    LinkList lp;
    lp = L;
    while (lp->next){
        lp = lp->next;
        printf("%d\n", lp->data);
    }
}
