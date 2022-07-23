/* 定义数据结构 */
typedef int Elemtype;
typedef struct Node{
    Elemtype data;
    struct Node *next;
} Node;
typedef Node *LoopLinkList;


/* 声明操作 */
int GetElem(LoopLinkList L, int i, Elemtype *ep);
int ListInsert(LoopLinkList *lp, int i, Elemtype e);
int ListDelete(LoopLinkList *lp, int i, Elemtype *ep);
void CreateListHead(LoopLinkList *lp, int n);
void ClearList(LoopLinkList *lp);
int ListEmpty(LoopLinkList L);
int ListLength(LoopLinkList L);
int HasElem(LoopLinkList L,Elemtype e);
