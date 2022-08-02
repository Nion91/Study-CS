
/* 定义数据结构 */
typedef int TElemType;

typedef struct TNode {
    TElemType data;
    struct TNode *left, *right;
} TNode, *BTree;


/* 定义操作 */
BTree InitTree(void);
BTree CreateTree(void);
void DestroyTree(BTree *tp);
void ClearTree(BTree *tp);
int TreeEmpty(BTree T);
int TreeDepth(BTree T);
BTree Parent(BTree T, TNode *np);
void PreOrderTraverse(BTree T);
void InOrderTraverse(BTree T);
void PostOrderTraverse(BTree T);


