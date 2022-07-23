#define MAXSIZE 20


/* 定义结构 */
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;


/* 声明操作 */
SqList * InitList(SqList *L);
int ListEmpty(SqList L);
void ClearList(SqList *L);
int GetElem(SqList L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e);
int ListInsert(SqList *L, int i, ElemType e);
int ListDelete(SqList *L, int i, ElemType *e);
int ListLength(SqList L);


