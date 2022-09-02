#define MAXSIZE 10000

/* 定义数据结构 */
typedef struct {
    int data[MAXSIZE+1];    /* data[0]用于哨兵或辅助存储 */
    int length;             /* 元素数量 */
} SqlList;


/* 定义基本操作 */
void InitSqlList(SqlList *lp, int n);
void swap(SqlList *lp, int i, int j);
void PrintSqlList(SqlList L);
void Test(void (*sortfunc)(SqlList *), int n);

void SwapArr(int SR[], int i, int j);

/* 快速排序 */
void QuickSort(SqlList *lp);
void QSort(int SR[], int s, int t);