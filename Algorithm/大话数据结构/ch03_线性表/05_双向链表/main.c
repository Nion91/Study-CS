#include <stdio.h>
#include <stdlib.h>
#include "DulLinklist.h"


void PrintList(DulLinkList L, int i);

main(){
    DulLinkList L, *lp;
    lp = &L;
    int i;

    /*初始化*/
    printf("==============init===============\n");
    CreateListHead(lp,3);
    printf("len: %d\n", ListLength(L));
    PrintList(L, 1);

    /*插入*/
    printf("==============insert===============\n");
    ListInsert(lp, 1, 1);
    ListInsert(lp, 1, 2);
    ListInsert(lp, 2, 3);
    ListInsert(lp, 7, 4);
    ListInsert(lp, 11, 10);
    PrintList(L, 1);
    PrintList(L, 0);

    /*删除*/
    printf("==============delete===============\n");
    ListDelete(lp, 1, &i);
    ListDelete(lp, 5, &i);
    ListDelete(lp, 5, &i);
    PrintList(L, 1);
    ListDelete(lp,10, &i);

    /*查找*/
    printf("==============find===============\n");
    printf("has: %d\n", HasElem(L, 3));
    printf("length: %d\n", ListLength(L));

    /*清除*/
    printf("==============clear===============\n");
    ClearList(lp);
    PrintList(L, 1);
}



void PrintList(DulLinkList L, int ascend){
    DulLinkList lp;
    lp = L;
    if (ascend){
        printf("ascend print:\n");
        while (lp->next != L){
            lp = lp->next;
            printf("%d\n", lp->data);
        }
    } else {
        printf("descend print:\n");
        while (lp->prior != L){
            lp = lp->prior;
            printf("%d\n", lp->data);
        }
    }
}
