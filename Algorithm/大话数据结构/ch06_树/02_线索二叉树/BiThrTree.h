#include <stdio.h>
#include <stdlib.h>

/* 定义数据结构 */
typedef int TElemType;

typedef enum {Link, Thread} PointerTag;     /* Link表示指向左右子树指针；Thread表示前驱或后继线索 */

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;


/* 定义操作 */
void InThreading(BiThrTree BT);
