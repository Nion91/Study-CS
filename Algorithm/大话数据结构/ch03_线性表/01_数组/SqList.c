#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

/* GetElem: 获取L第i个元素，给到e */
int GetElem(SqList L, int i, ElemType *e){
    if (L.length == 0 || i < 1 || i > L.length)
        return 0;
    
    *e = L.data[i-1];
    return 1;
}


/* ListInsert: 将e插到L的第i个位置 */
int ListInsert(SqList *L, int i, ElemType e){
    if (L->length == MAXSIZE){
        printf("List is full.\n");
        return 0;
    }
    if (i < 1 || i > L->length+1){
        printf("i is out of range.\n");
        return 0;
    }
    
    int k;
    for (k = L->length; k > i-1; k--)
        L->data[k] = L->data[k-1];
    L->data[i-1] = e;
    L->length++;
    return 1;
}


/* ListDelete: 删除L的第i个位置元素，并将该元素赋值给*e */
int ListDelete(SqList *L, int i, ElemType *e){
    int k;
    if (L->length == 0){
        printf("List is empty.\n");
        return 0;
    }
    if (i < 1 || i > L->length){
        printf("i is out of range.\n");
        return 0;
    }
    *e = L->data[i - 1];
    for (k = i; k < L->length; k++)
        L->data[k-1] = L->data[k];
    L->length--;
    return 1;
}



/* InitList: 初始化L为SqList */
SqList * InitList(SqList *L){
    int i;
    L = (SqList *) malloc(sizeof(SqList));
    for (i = 0; i < MAXSIZE; i++)
        L->data[i] = 0;
    L->length = 0;
    return L;
}

/* ListEmpty: 返回L是否为空 */
int ListEmpty(SqList L){
    return L.length > 0 ? 1 : 0;
}

/* ClearList: 清空L */
void ClearList(SqList *L){
    L->length = 0;
}

/* LocateElem: 返回元素e在列表L中的位置 */
int LocateElem(SqList L, ElemType e){
    int i;
    if (L.length == 0){
        return 0;   
    }
    for (i = 0; i < L.length; i++){
        if (e = L.data[i])
            return i+1;
    }
    return 0;
}


/* ListLength: 返回列表L的长度 */
int ListLength(SqList L){
    return L.length;
}