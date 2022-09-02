#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RecurSort.h"


/* InitSqlList: 初始化数组，n为元素数量 */
void InitSqlList(SqlList *lp, int n){
    int i;

    for (i = 1; i <= n; i++){
        lp->data[i] = rand();
    }
    lp->length = n;
}


/* PrintSqlLIst: 打印数组 */
void PrintSqlList(SqlList L){
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}


/* swap: 交换操作 */
void swap(SqlList *lp, int i, int j){
    int tmp = lp->data[i];
    lp->data[i] = lp->data[j];
    lp->data[j] = tmp; 
}


/* Test: 测试排序算法的性能 */
void Test(void (*sortfunc)(SqlList *), int n){
    int i;
    SqlList L;
    time_t srt, end;

    time(&srt);
    for (i = 1; i <= n; i++){
        InitSqlList(&L, MAXSIZE);
        (*sortfunc)(&L);
    }
    time(&end);

    printf("spend time: %ds\n", end-srt);
}

