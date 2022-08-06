#define MAXSIZE 10
#define MAXWORD 1000

/* 定义数据结构 */
typedef int TElemType;

typedef struct TNode {
    TElemType elem;         /* 记录元素 */
    int weight;             /* 记录权重 */
    int is_leaf;            /* 记录是否为叶节点 */
    struct TNode *lchild, *rchild;
} TNode, *BTree;

typedef struct {
    BTree data[MAXSIZE];
    int count;
} HuffmanTree;


/* 定义操作 */
HuffmanTree * InitHuffman(int weight[], int len);
void WeightQuickSort(HuffmanTree *hp, int left, int right);
BTree MergeNode(BTree T1, BTree T2);
void CreateHuffman(HuffmanTree *hp);
void PrintData(HuffmanTree *hp);
void PostPrint(BTree T);
void PrintHuffman(HuffmanTree *hp);
void GetHuffmanCode(BTree T, char * prefix, char codelist[][MAXWORD]);



/* 其他函数 */
char * CharToCode(char *res, char *s, char codelist[][MAXWORD]);














