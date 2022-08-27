/* 定义平衡因子的状态 */
#define LH +1       /* 左子树高 */
#define EH 0        /* 等高 */
#define RH -1       /* 右子树高 */

/* 定义数据结构 */
typedef struct AvlBiNode{
    int data;
    int bf;         /* 节点的平衡因子 */
    struct AvlBiNode *lchild, *rchild;
} AvlBiNode, *AvlBiTree;


/* 定义操作 */
void R_Rotate(AvlBiTree *ap);
void L_Rotate(AvlBiTree *ap);
void LeftBalance(AvlBiTree *ap);
void RightBalance(AvlBiTree *ap);
int InsertAVL(AvlBiTree *ap, int key, int *taller);

void PrintAVL(AvlBiTree T);
