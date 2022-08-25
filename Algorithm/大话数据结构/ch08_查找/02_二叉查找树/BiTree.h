/* 定义数据结构 */
typedef struct BiNode {
    int data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;



/* 定义操作 */
int SearchBST(BiTree T, int key, BiTree f, BiTree *bp);
int InsertBST(BiTree *bt, int key);
int DeleteBST(BiTree *bt, int key);
int Delete(BiTree *bt);

void PrintBST(BiTree T);

