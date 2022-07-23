#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* GetElem: 取L中第i个元素 */
int GetElem(LinkList L, int i, Elemtype *e){
    int k;
    Node *np;

    for (k = 1, np = L; k < i; k++, np = np->next){
        if (np == NULL)
            return 0;
    }
    if (np == NULL)
        return 0;
    *e = np->data;
    return 1;
}

/* ListInsert: 在*lp的第i个位置插入e */
int ListInsert(LinkList *lp, int i, Elemtype e){
    int j;
    LinkList p, s;
    
    p = *lp;
    j = 1;
    while (p && j < i){
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return 0;

    s = (LinkList) malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}


/* ListDelete: 删除链表*lp中第i个节点 */
int ListDelete(LinkList *lp, int i, Elemtype *ep){
    int k;
    LinkList np, ns;

    np = *lp;
    k = 1;
    while (np && k < i){
        np = np->next;
        k++;
    }
    if (!np || k < i || np->next == NULL){
        return 0;
    }
    ns = np->next;
    np->next = ns->next;
    *ep = ns->data;
    free(ns);
    return 1;
}


/* CreateListHead: 创建带有头指针的链表 */
void CreateListHead(LinkList *lp, int n){
    int i;
    LinkList r, tmp;
    *lp = (LinkList) malloc(sizeof(Node));
    r = *lp;
    for (i = 0; i < n; i++){
        tmp = (Node *) malloc(sizeof(Node));
        tmp->data = 0;
        r->next = tmp;
        r = tmp; 
    }
    r->next = NULL;
}


/* ClearList: 清空链表 */
void ClearList(LinkList *lp){
    LinkList r, p;
    r = *lp;
    while (r->next){
        p = r->next;
        r->next = p->next;
        free(p);
    }
}


/* ListEmpty: 返回链表是否为空 */
int ListEmpty(LinkList L){
    return L->next ? 1 : 0;
}

/* ListLength: 返回链表长度 */
int ListLength(LinkList L){
    int n = 0;
    LinkList lp;
    lp = L;
    while (lp->next){
        lp = lp->next;
        n++;
    }
    return n;
}

/* HasElem: 判断元素e是否在链表L中 */
int HasElem(LinkList L, Elemtype e){
    LinkList lp;
    lp = L;
    while (lp->next){
        lp = lp->next;
        if (lp->data == e)
            return 1;
    }
    return 0;
}

