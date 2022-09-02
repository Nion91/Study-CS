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


/* 归并排序 */
void MergeSort(SqlList *lp);
void MSort(int SR[], int TR1[], int s, int t);
void Merge(int SR[], int TR[], int s, int m, int t);

/* 不采用递归的归并排序 */
void MergeSort2(SqlList *lp);
void MergePass(int SR[], int TR[], int s, int t);