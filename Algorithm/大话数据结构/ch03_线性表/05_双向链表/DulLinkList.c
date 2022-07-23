#include <stdio.h>
#include <stdlib.h>
#include "DulLinkList.h"

/* GetElem: 取L第n个元素，赋值给e */
int GetElem(DulLinkList L, int n, ElemType *ep){
    DulLinkList pn;
    int i;

    for (i = 0, pn = L; i < n; i++){
        if (pn->next == L){
            return 0;
        }
        pn = pn->next;
    }
    *ep = pn->data;
    return 1;
}

/* ListInsert: 在链表*lp的第n个位置插入元素e */
int ListInsert(DulLinkList *lp, int n, ElemType e){
    DulLinkList np, kp;
    int i;

    if (n < 1 || n > ListLength(*lp)+1){
        printf("Out of range\n");
        return 0;
    }

    for (i = 1, np = *lp; i < n; i++){
        np = np->next;
    }

    kp = (DulLinkList)malloc(sizeof(DulNode));
    kp->data = e;
    kp->next = np->next;
    kp->prior = np;
    np->next = kp;
    kp->next->prior = kp;
    return 1;
}


/* ListDelete: 删除链表*lp的第n个元素，赋值给元素*ep */
int ListDelete(DulLinkList *lp, int n, ElemType *ep){
    DulLinkList np, kp;
    int i;
    
    if (n < 1 || n > ListLength(*lp)){
        printf("Out of range\n");
        return 0;
    }

    for (i = 1, np = *lp; i < n; i++){
        np = np->next;
    }
    kp = np->next;
    np->next = kp->next;
    kp->next->prior = np;
    *ep = kp->data;
    free(kp);
    return 1;
}

/* ListLength: 返回链表长度 */
int ListLength(DulLinkList L){
    int n;
    DulLinkList np;
    np = L;
    n = 0;
    while (np->next != L){
        np = np->next;
        n++;
    }
    return n;
}

/* CreateListHead: 创建带有头指针的双向链表 */
void CreateListHead(DulLinkList *lp, int n){
    DulLinkList np, kp;
    int i;

    kp = (DulLinkList)malloc(sizeof(DulNode));
    kp->next = kp;
    kp->prior = kp;
    *lp = kp;

    for (i = 0, np = kp; i < n; i++){
        kp = (DulLinkList)malloc(sizeof(DulNode));
        kp->data = 0;
        kp->next = np->next;
        np->next = kp;
        kp->prior = np;
        kp->next->prior = kp;
    }
}

/* ClearList: 清空链表 */
void ClearList(DulLinkList *lp){
    DulLinkList np, kp;
    np = (*lp)->next;
    while (np != *lp){
        kp = np;
        np = np->next;
        free(kp);
    }
    (*lp)->next = (*lp)->prior = *lp;
}


/* ListEmpty: 返回链表是否为空 */
int ListEmpty(DulLinkList L){
    return L->next == L ? 0 : 1;
}

/* HasElem: 判断链表中是否有元素e */
int HasElem(DulLinkList L, ElemType e){
    DulLinkList np;
    np = L;
    while (np->next != L){
        np = np->next;
        if (np->data == e)
            return 1;
    }
    return 0;
}