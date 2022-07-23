#include <stdio.h>
#include <stdlib.h>
#include "LoopLinkList.h"

/* GetElem: 取L中第i个元素 */
int GetElem(LoopLinkList L, int i, Elemtype *e){
    int k;
    Node *np;

    np = L->next;
    k = 0;
    while (np->next != L->next && k < i){
        np = np->next;
        k++;
    }

    if (np == L->next  || k < i)
        return 0;

    *e = np->data;
    return 1;
}

/* ListInsert: 在*lp的第i个位置插入e */
int ListInsert(LoopLinkList *lp, int i, Elemtype e){
    int j;
    LoopLinkList p, s;
    
    p = (*lp)->next;
    j = 1;

    while (p->next != (*lp)->next && j < i){
        p = p->next;
        j++;
    }
    if ( j < i)
        return 0;

    s = (LoopLinkList) malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    if (s->next == (*lp)->next){
        *lp = s;
    }
    p->next = s;
    
    return 1;
}


/* ListDelete: 删除链表*lp中第i个节点 */
int ListDelete(LoopLinkList *lp, int i, Elemtype *ep){
    int k;
    LoopLinkList np, ns;

    np = (*lp)->next;
    k = 1;
    while (np->next != (*lp)->next && k < i){
        np = np->next;
        k++;
    }
    if (k < i || np->next == (*lp)->next){
        printf("Out of range.\n");
        return 0;
    }
    ns = np->next;
    np->next = ns->next;
    *ep = ns->data;
    if (ns->next == (*lp)->next)
        *lp = np;
    free(ns);
    return 1;
}


/* CreateListHead: 创建带有头指针的循环链表 */
void CreateListHead(LoopLinkList *lp, int n){
    int i;
    LoopLinkList r, tmp;
    *lp = (LoopLinkList) malloc(sizeof(Node));
    r = *lp;
    for (i = 0; i < n; i++){
        tmp = (Node *) malloc(sizeof(Node));
        tmp->data = 0;
        r->next = tmp;
        r = tmp; 
    }
    r->next = *lp;
    *lp = r;
}


/* ClearList: 清空链表 */
void ClearList(LoopLinkList *lp){
    LoopLinkList r, p;
    r = (*lp)->next;
    while (r->next != (*lp)->next){
        p = r->next;
        r->next = p->next;
        free(p);
    }
    *lp = r;
}


/* ListEmpty: 返回链表是否为空 */
int ListEmpty(LoopLinkList L){
    return L == L->next ? 0 : 1;
}

/* ListLength: 返回链表长度 */
int ListLength(LoopLinkList L){
    int n = 0;
    LoopLinkList lp;
    lp = L->next;
    while (lp->next != L->next){
        lp = lp->next;
        n++;
    }
    return n;
}

/* HasElem: 判断元素e是否在链表L中 */
int HasElem(LoopLinkList L, Elemtype e){
    LoopLinkList lp;
    lp = L->next;
    while (lp->next != L->next){
        lp = lp->next;
        if (lp->data == e)
            return 1;
    }
    return 0;
}

