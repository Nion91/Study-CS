#include <stdio.h>
#include "BTree.h"



main(){
    BTree T;
    
    /* 创建二叉树 */
    /* 
    输入：ABDH#K###E##CFI###G#J##
    前序打印：ABDH#K###E##CFI###G#J##
    中序打印：#H#K#D#B#E#A#I#F#C#G#J#
    后续打印：###KH#D##EB##I#F###JGCA
    */
    printf("======================create=====================\n");
    T = CreateTree();
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");


    /* 查找父节点 */
    printf("======================parent=====================\n");
    TNode *np, *kp;
    np = T->left->left->left;
    kp = Parent(T, np);
    printf("parent: %c\n", kp->data);


    /* 清空二叉树 */
    printf("======================clear=====================\n");
    printf("Depth: %d\n", TreeDepth(T));
    printf("Empty: %d\n", TreeEmpty(T));
    ClearTree(&T);
    printf("Depth: %d\n", TreeDepth(T));
    printf("Empty: %d\n", TreeEmpty(T));
    printf("Null: %d\n", T == NULL);
    DestroyTree(&T);
    printf("Null: %d\n", T == NULL);
}
