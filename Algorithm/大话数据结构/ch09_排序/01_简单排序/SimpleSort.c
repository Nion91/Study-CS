#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SimpleSort.h"


/* InitSqlList: 初始化数组，n为元素数量 */
void InitSqlList(SqlList *lp, int n){
    int i;

    for (i = 1; i <= n; i++){
        lp->data[i] = rand() % MAXSIZE;
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


/* 
SimpleSort: 简单排序
两层循环，每轮进行n次比较和n次交换
每轮只比较当前的i，效率非常低 
*/
void SimpleSort(SqlList *sp){
    int i, j;

    for (i = 1; i < sp->length; i++){
        for (j = i+1; j <= sp->length; j++){
            if (sp->data[i] > sp->data[j])
                swap(sp, i, j);
        }
    }
}


/* 
BubbleSort: 冒泡排序
两层循环，每轮进行n次比较和n次交换
每次比较不同位置的数，将更小/大的数往上移动，效率比简单排序高
*/
void BubbleSort(SqlList *lp){
    int i, j;

    for (i = 1; i < lp->length; i++){
        for (j = 2; j <= lp->length - i + 1; j++){
            if (lp->data[j-1] > lp->data[j])
                swap(lp, j-1, j);
        }
    }
}


/* 
BubbleSort2: 冒泡排序的优化版
优化了数据已排序的情况下，无需再进行比较
*/
void BubbleSort2(SqlList *lp){
    int i, j, flag;

    for (i = 1; i < lp->length; i++){
        flag = 1;                                   /* 每轮开始前设置flag */
        for (j = lp->length-1; j >= i; j--){
            if (lp->data[j] > lp->data[j+1]){
                swap(lp, j, j+1);
                flag = 0;                           /* 如果发生交换，flag置为0 */
            }
        }
        if (flag)                                   /* 如果flag为1，说明本轮没有发生交换，即数据已按顺序排列，无需再进行比较 */
            break;
    }
}



/* 
SelectSort: 选择排序
两层循环，n次比较，1次交换
每轮记录最小元素的下标，和i进行交换，性能略优于冒泡排序
*/
void SelectSort(SqlList *lp){
    int i, j, min;

    for (i = 1; i <= lp->length; i++){
        min = i;
        for (j = i + 1; j <= lp->length; j++){
            if (lp->data[j] < lp->data[min])
                min = j;
        }
        if (min != i)
            swap(lp, i, min);
    }

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