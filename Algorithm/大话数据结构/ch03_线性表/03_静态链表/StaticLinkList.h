#define MAXSIZE 20

/* 定义数据结构 */
typedef int Elemtype;
typedef struct {
    Elemtype data;
    int cur;
} Component, StaticLinkList[MAXSIZE];



/* 定义操作 */
int InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);
int ListInsert(StaticLinkList space, int i, Elemtype e);
void Free_SLL(StaticLinkList space, int i);
int ListDelete(StaticLinkList space, int i, Elemtype *ep);
int GetElem(StaticLinkList L, int i, Elemtype *ep);
int ListLength(StaticLinkList L);
int ListEmpty(StaticLinkList L);
void ClearList(StaticLinkList L);
