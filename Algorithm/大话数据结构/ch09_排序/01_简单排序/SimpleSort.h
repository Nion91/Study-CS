#define MAXSIZE 10000

/* 定义数据结构 */
typedef struct {
    int data[MAXSIZE+1];    /* data[0]用于哨兵或辅助存储 */
    int length;             /* 元素数量 */
} SqlList;


/* 定义基本操作 */
void InitSqlList(SqlList *lp, int n);
void PrintSqlList(SqlList L);

void swap(SqlList *lp, int i, int j);

void SimpleSort(SqlList *sp);
void BubbleSort(SqlList *lp);
void BubbleSort2(SqlList *lp);
void SelectSort(SqlList *lp);

void Test(void (*sortfunc)(SqlList *), int n);