#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"




/* SearchBST: 在二叉查找树中搜索key，f为T的父节点，初始为NULL */
int SearchBST(BiTree T, int key, BiTree f, BiTree *bp){
    if (!T){                    /* T为NULL，查找失败；将父节点赋值给bp，便于后续插入操作 */
        *bp = f;
        return 0;
    }

    if (T->data == key){
        *bp = T;
        return 1;
    } else if (T->data > key)
        return SearchBST(T->lchild, key, T, bp);
    else
        return SearchBST(T->rchild, key, T, bp);
}


/* InsertBST: 在二叉查找树中插入节点 */
int InsertBST(BiTree *bt, int key){
    BiTree s, p;
    if (SearchBST(*bt, key, NULL, &p)){             /* key已存在，不再插入 */
        printf("Error: already has %d\n", key);
        return 0;
    }

    s = (BiTree)malloc(sizeof(BiNode));             /* key不存在，构造新节点 */
    s->data = key;
    s->lchild = s->rchild = NULL;

    if (!p)                                         /* bt为空树，直接插入 */
        *bt = s;
    else if (key > p->data)                         /* 插入右子树 */
        p->rchild = s;
    else                                            /* 插入左子树 */
        p->lchild = s;
    return 1;
}


/* DeleteBST: 以递归方式删除二叉查找树的节点 */
int DeleteBST(BiTree *bt, int key){                 /* 未找到key */
    if (!*bt){
        printf("Error: no %d\n", key);
        return 0;
    }

    if ((*bt)->data == key)                         /* 找到key，进行删除操作 */
        return Delete(bt);
    else if ((*bt)->data < key)
        return DeleteBST(&(*bt)->rchild, key);      /* 在右子树递归 */
    else
        return DeleteBST(&(*bt)->lchild, key);      /* 在左子树递归 */
}


/* Delete: 从二叉查找树中删除节点bt，并重接bt的左子树或右子树 */
int Delete(BiTree *bt){
    BiTree s, p;

    s = *bt;
    if (s->lchild == NULL){             /* 如果右节点为空，接入节点的左子树 */
        (*bt) = s->rchild;
        free(s);
    } else if (s->rchild == NULL){      /* 如果左节点为空，接入节点的右子树 */
        (*bt) = s->lchild;
        free(s);
    } else {                            /* 如果两个节点都不为空 */
        p = s->lchild;                  /* 在右子树中找最左的点，即找最小的点 */
        while (p->rchild){
            s = p;
            p = p->rchild;
        }
        (*bt)->data = p->data;          /* 把最小的点放到bt中 */
        if (*bt == s)                   /* bt的右节点没有左节点的情况 */
            s->lchild = p->lchild;
        else                            /* bt的右节点有左节点的情况 */
            s->rchild = p->lchild;
        free(p);
    }
    return 1;
}



/* PrintBST: 以前序方式打印二叉查找树 */
void PrintBST(BiTree T){
    if (!T)
        return;
    else {
        PrintBST(T->lchild);
        printf("%d\n", T->data);
        PrintBST(T->rchild);
    }
}
