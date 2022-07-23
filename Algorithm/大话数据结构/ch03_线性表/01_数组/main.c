#include <stdio.h>
#include "SqList.h"


void PrintList(SqList *L);

main(){
    SqList *lp;
    int i;

    /*初始化*/
    lp = InitList(lp);

    /*插入*/
    for (i = 1; i <= 5; i++)
        ListInsert(lp, i, i);
    ListInsert(lp, 2, 10);
    PrintList(lp);

    /*删除*/
    int n, *np;
    np = &n;
    ListDelete(lp, 3, np);
    printf("delete: %d\n", n);
    PrintList(lp);

    /*查找*/
    GetElem(*lp, 2, np);
    printf("find: %d\n", n);

    printf("locate: %d\n",LocateElem(*lp, n));

    /*清除*/
    ClearList(lp);
    PrintList(lp);
}



void PrintList(SqList *L){
    int i;
    for (i = 0; i < L->length; i++){
        printf("%d\n", L->data[i]);
    }
}
