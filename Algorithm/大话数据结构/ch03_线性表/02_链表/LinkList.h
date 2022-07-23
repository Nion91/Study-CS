/* 定义数据结构 */
typedef int Elemtype;
typedef struct Node{
    Elemtype data;
    struct Node *next;
} Node;
typedef Node *LinkList;


/* 声明操作 */
int GetElem(LinkList L, int i, Elemtype *ep);
int ListInsert(LinkList *lp, int i, Elemtype e);
int ListDelete(LinkList *lp, int i, Elemtype *ep);
void CreateListHead(LinkList *lp, int n);
void ClearList(LinkList *lp);
int ListEmpty(LinkList L);
int ListLength(LinkList L);
int HasElem(LinkList L,Elemtype e);
