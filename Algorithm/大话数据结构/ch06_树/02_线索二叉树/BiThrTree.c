#include <stdio.h>
#include <stdlib.h>
#include "BiThrTree.h"


/* InThreading: 用中序遍历进行线索化 */
BiThrTree pre;
void InThreading(BiThrTree BT){
    if (BT){
        InThreading(BT->lchild);
        if (!BT->lchild){
            BT->LTag = Thread;
            BT->lchild = pre;
        }

        if (!BT->rchild){
            BT->RTag = Thread;
            BT->rchild = BT;
        }

        pre = BT;
        InThreading(BT->rchild);
    }
}



