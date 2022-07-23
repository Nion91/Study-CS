/* 定义结构 */
typedef int ElemType;
typedef struct DulNode {
    ElemType data;
    struct DulNode * prior;
    struct DulNode * next;
} DulNode, *DulLinkList;


/* 定义操作 */
int GetElem(DulLinkList L, int n, ElemType *ep);
int ListInsert(DulLinkList *lp, int n, ElemType e);
int ListDelete(DulLinkList *lp, int n, ElemType *ep);
int ListLength(DulLinkList L);
void CreateListHead(DulLinkList *lp, int n);
void ClearList(DulLinkList *lp);
int ListEmpty(DulLinkList L);
int HasElem(DulLinkList L, ElemType e);
