#include <stdio.h>
#include "StaticLinkList.h"


/* InitList: 初始化静态链表，将表中备用空间连城链表 */
int InitList(StaticLinkList space){
    int i;
    for (i = 0; i < MAXSIZE - 1; i++){
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;
    return 1;
}


/* Malloc_SLL: 分配静态链表中的位置，返回可用的备用空间下标 */
int Malloc_SLL(StaticLinkList space){
    int i;
    i = space[0].cur;
    if (i){
        space[0].cur = space[i].cur;
    }
    return i;
}

/* Free_SLL: 回收下标为i的空间为备用空间 */
void Free_SLL(StaticLinkList space, int i){
    space[i].cur = space[0].cur;
    space[0].cur = i;
}




/* ListLength：返回静态链表长度 */
int ListLength(StaticLinkList L){
    int k, n;

    k = L[MAXSIZE - 1].cur;
    n = 0;
    while (k){
        k = L[k].cur;
        n++;
    }
    return n;
}

/* ListInsert: 在静态链表的i位置插入元素e */
int ListInsert(StaticLinkList space, int i, Elemtype e){
    int k, n, new;
    
    if (space[0].cur == MAXSIZE-1){
        printf("List is full\n");
        return 0;
    }
    
    k = MAXSIZE - 1;
    n = 0;
    while (space[k].cur && n < i){  /* 取到第n-1个节点 */
        k = space[k].cur;
        n++;
    }
    if (n < i-1){
        printf("i is out of range\n");
        return 0;
    }

    new = Malloc_SLL(space);
    space[new].data = e;
    space[new].cur = space[k].cur;
    space[k].cur = new;
    return 1;
}

/* ListDelete: 删除静态链表第i个节点 */
int ListDelete(StaticLinkList space, int i, Elemtype *ep){
    int k, n, tmp;

    if (i < 1 || i > ListLength(space)){
        printf("Out of range\n");
        return 0;
    }
    
    for (k = MAXSIZE - 1, n = 1; n < i; n++){
        k = space[k].cur;
    }
    tmp = space[k].cur;
    *ep = space[tmp].data;
    space[k].cur = space[tmp].cur;
    Free_SLL(space, tmp);
    return 1;
}


/* GetElem: 获取静态链表第i个元素，赋值到*ep */
int GetElem(StaticLinkList L, int i, Elemtype *ep){
    int k, n;
    if (i < 1 || i > ListLength(L)){
        printf("Out of range\n");
        return 0;
    }
    for (k = MAXSIZE - 1, n = 1; n <= i; n++){
        k = L[k].cur;
    }
    *ep = L[k].data;
    return 1;
}





/* ListEmpty：返回静态链表是否为空 */
int ListEmpty(StaticLinkList L){
    return L[MAXSIZE - 1].cur ? 1 : 0;
}


/* ClearList：清空静态链表 */
void ClearList(StaticLinkList L){
    int k, first_cur, next;
    
    k = L[MAXSIZE - 1].cur;
    L[MAXSIZE - 1].cur = 0;
    first_cur = L[0].cur; /* 第一个备用空间 */
    while (k){
        next = L[k].cur;
        L[k].cur = first_cur;
        first_cur = k;
        k = next;
    }
    L[0].cur = first_cur;
}


/* HasElem：返回元素e是否在静态链表中 */
int HasElem(StaticLinkList L, Elemtype e){
    int k;

    k = L[MAXSIZE - 1].cur;
    while (k){
        if (L[k].data == e)
            return 1;
        k = L[k].cur;
    }
    return 0;
}
