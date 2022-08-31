#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "InsertSort.h"


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


/* 
InsertSort: 选择排序
两层循环，n次比较，n次交换
每轮将第n位元素和已排序的n-1个元素比较，性能优于冒泡排序和选择排序
*/
void InsertSort(SqlList *lp){
    int i, j;

    for (i = 2; i <= lp->length; i++){
        lp->data[0] = lp->data[i];
        for (j = i-1; j >=1 ; j--){         /* 和已排序的元素进行比较，从后往前比较 */
            if (lp->data[j] > lp->data[0])
                swap(lp, j, j+1);
            else{
                lp->data[j+1] = lp->data[0];
                break;
            }
        }
    }
}


/* ShellSort: 插入排序的优化版
在插入排序的基础上加入了步长，步长从大到小逐渐缩短，按每个步长分别做一次插入排序
两轮循环，length/步长次比较，length/步长次交换，
*/
void ShellSort(SqlList *lp){
    int i, j, step;

    step = lp->length;
    do {
        step = step / 3 + 1;                        /* 计算步长，当前根据经验从step/3开始 */
        for (i = step + 1; i <= lp->length; i++){
            lp->data[0] = lp->data[i];
            for (j = i - step; j > 0 && lp->data[0] < lp->data[j]; j -= step){
                    lp->data[j+step] = lp->data[j];       
            }
            lp->data[j+step] = lp->data[0];
        }
    } while (step > 1);
}