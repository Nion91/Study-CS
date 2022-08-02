#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BTree.h"


/* InitTree: 初始化二叉树 */
BTree InitTree(void){
    BTree T;
    T = (BTree)malloc(sizeof(TNode));
    return T;
}


/* CreateTree: 根据输入流创建二叉树 */
BTree CreateTree(void){
    int c;
    BTree bp;

    c = getchar();
    if (!isalpha(c))
        return NULL;

    bp = InitTree();
    bp->data = c;
    bp->left = CreateTree();
    bp->right = CreateTree();

    return bp;
}


/* DestroyTree: 销毁二叉树 */
void DestroyTree(BTree *tp){
    if (!(*tp))
        return;

    if ((*tp)->left)
        DestroyTree(&(*tp)->left);
    
    if ((*tp)->right)
        DestroyTree(&(*tp)->right);

    free(*tp);
}


/* ClearTree: 清空栈 */
void ClearTree(BTree *tp){
    BTree kp;

    if (!(*tp))
        return;

    if ((*tp)->left)
        DestroyTree(&(*tp)->left);
    
    if ((*tp)->right)
        DestroyTree(&(*tp)->right);

    kp = *tp;
    *tp = NULL;
    free(kp);
}


/* TreeEmpty: 判断二叉树是否为空 */
int TreeEmpty(BTree T){
    return T == NULL;
}


/* TreeDepth: 返回二叉树的深度 */
int TreeDepth(BTree T){
    int n1, n2;

    if (TreeEmpty(T))
        return 0;
    
    n1 = TreeDepth(T->left);
    n2 = TreeDepth(T->right);
    return (n1 > n2) ? (n1 + 1) : (n2 + 1);
}


/* Parent: 在二叉树T中查找节点np的父节点 */
BTree Parent(BTree T, TNode *np){
    BTree kp;

    if (!T)
        return NULL;

    if (T->left == np || T->right == np)    /* 判断当前节点是否为目标节点的父节点 */
        return T;

    kp = Parent(T->left, np);               /* 从左子树找父节点 */
    if (kp)
        return kp;

    kp = Parent(T->right, np);              /* 从右子树找父节点 */
    if (kp)
        return kp;

    return NULL;
}


/* PreOrderTraverse: 前序遍历 */
void PreOrderTraverse(BTree T){
    if (T){
        printf("%c", T->data);
        PreOrderTraverse(T->left);
        PreOrderTraverse(T->right);
    } else {
        printf("#");
    }
}


/* InOrderTraverse: 中序遍历 */
void InOrderTraverse(BTree T){
    if (T){
        InOrderTraverse(T->left);
        printf("%c", T->data);
        InOrderTraverse(T->right);
    } else {
        printf("#");
    }
}


/* PostOrderTraverse: 后序遍历 */
void PostOrderTraverse(BTree T){
    if (T){
        PostOrderTraverse(T->left);
        PostOrderTraverse(T->right);
        printf("%c", T->data);
    } else {
        printf("#");
    }
}

