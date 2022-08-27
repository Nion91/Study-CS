#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"


/* R_Rotate: 以ap为根节点进行右旋 */
void R_Rotate(AvlBiTree *ap){
    AvlBiTree L;

    L = (*ap)->lchild;              /* 获取ap的左子树 */
    (*ap)->lchild = L->rchild;      /* 将L的右子树重接为ap的左子树 */
    L->rchild = *ap;                /* 将ap重接为L的右子树 */
    *ap = L;                        /* 将根节点指向L */
}


/* L_Rotate: 以ap为根节点进行左旋 */
void L_Rotate(AvlBiTree *ap){
    AvlBiTree R;

    R = (*ap)->rchild;              /* 获取ap的右子树 */
    (*ap)->rchild = R->lchild;      /* 将R的左子树重接为ap的右子树 */
    R->lchild = *ap;                /* 将ap重接为R的左子树 */
    *ap = R;                        /* 将根节点指向R */
}


/* LeftBalance: 对以ap为根节点的二叉树做左平衡旋转处理 */
void LeftBalance(AvlBiTree *ap){
    AvlBiTree L, Lr;

    L = (*ap)->lchild;                      /* 获取ap的左子树 */
    switch(L->bf){                          /* 检查L的平衡因子，作相应处理 */
        case LH:                            /* 和ap同为左子树高的情况，只需做一次右旋 */
            (*ap)->bf = L->bf = EH;
            R_Rotate(ap);
            break;
        case RH:                            /* 和ap相反，L右子树高的情况，需要做两次旋转 */
            Lr = L->rchild;                 /* 获取L的右子树 */
            switch(Lr->bf){                 /* 检查Lr的平衡因子，调整ap和L的平衡因子 */
                case LH:
                    (*ap)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*ap)->bf = L->bf = EH;
                    break;
                case RH:
                    (*ap)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*ap)->lchild);       /* 先以L为根节点，进行左旋 */ 
            R_Rotate(ap);                   /* 再以Lr为根节点，进行右旋 */
            break;
    }
}


/* RightBalance: 对以ap为根节点的二叉树做右平衡旋转处理 */
void RightBalance(AvlBiTree *ap){
    AvlBiTree R, Rl;

    R = (*ap)->rchild;
    switch(R->bf){
        case RH:
            (*ap)->bf = R->bf = EH;
            L_Rotate(ap);
            break;
        case LH:
            Rl = R->lchild;
            switch(Rl->bf){
                case RH:
                    (*ap)->bf = LH;
                    R->bf = EH;
                    break;
                case EH:
                    (*ap)->bf = R->bf = EH;
                    break;
                case LH:
                    (*ap)->bf = EH;
                    R->bf = RH;
                    break;
            }
            Rl->bf = EH;
            R_Rotate(&(*ap)->rchild);
            L_Rotate(ap);
            break;
    }
}


/* InsertAVL: 在平衡二叉树中插入节点key；taller反映ap是否长高 */
int InsertAVL(AvlBiTree *ap, int key, int *taller){
    if(!(*ap)){                                                 /* ap为空树，直接插入新节点，树长高 */
        (*ap) = (AvlBiTree)malloc(sizeof(AvlBiNode));
        (*ap)->data = key;
        (*ap)->bf = EH;
        (*ap)->lchild = (*ap)->rchild = NULL;

        *taller = 1;
        return 1;
    }

    if (key == (*ap)->data){                                    /* 二叉树中已有key，不再插入 */
        printf("Error: already has %d\n", key); 
        *taller = 0;
        return 0;
    } else if (key < (*ap)->data){                              /* 在左子树中进行搜索 */
        if (!InsertAVL(&(*ap)->lchild, key, taller))            /* 左子树中插入失败 */
            return 0;
        
        if (*taller){                                           /* 左子树中插入成功，并且左子树长高 */
            switch((*ap)->bf){                                  /* 根据ap的平衡因子，作相应处理 */
                case LH:                                        /* 如果ap本身就左高，需要进行左平衡处理，平衡后树未长高 */
                    LeftBalance(ap);
                    *taller = 0;
                    break;
                case EH:                                        /* 如果ap本身平衡，转为左高，ap长高 */
                    (*ap)->bf = LH;
                    *taller = 1;
                    break;
                case RH:                                        /* 如果ap本身右高，转为平衡，ap未长高 */
                    (*ap)->bf = EH;
                    *taller = 0;
                    break;
            }
        }
    } else {                                                    /* 在右子树中进行搜索 */
        if (!InsertAVL(&(*ap)->rchild, key, taller))            /* 右子树中插入失败 */
            return 0;

        if (*taller){                                           /* 右子树中插入成功，并且右子树长高 */
            switch((*ap)->bf){                                  /* 根据ap的平衡因子，作相应处理 */
                case RH:                                        /* 如果ap本身就右高，需要进行右平衡处理，平衡后树未长高 */
                    RightBalance(ap);
                    *taller = 0;
                    break;
                case EH:                                        /* 如果ap本身平衡，转为右高，ap长高 */
                    (*ap)->bf = RH;
                    *taller = 1;
                    break;
                case LH:                                        /* 如果ap本身左高，转为平衡，ap未长高 */
                    (*ap)->bf = EH;
                    *taller = 0;
                    break;
            }
        }
    }
    return 1;
}


/* PrintAVL: 打印二叉树 */
void PrintAVL(AvlBiTree T){
    if (!T)
        return ;
    else {
        printf("data: %d, bf: %d\n", T->data, T->bf);
        PrintAVL(T->lchild);
        PrintAVL(T->rchild);
    }
}



