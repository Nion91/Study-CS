#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "RecurSort.h"


/* 
MergeSort: 归并排序 
从下往上将子序列两两归并
将两个有序数列进行合并 
*/
void MergeSort(SqlList *lp){
    MSort(lp->data, lp->data, 1, lp->length);
}


/* MSort: 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t){
    int TR2[MAXSIZE + 1];
    int m;

    if (s == t)                         /* 只有1个元素 */
        TR1[s] = SR[s];
    else {                              /* 有多个元素 */
        m = s + (t - s) / 2;            /* 将SR[s..t]平分为两个子序列SR[s..m]和SR[m+1..t] */
        MSort(SR, TR2, s, m);           /* 递归将SR[s..m]归并为有序的TR2[s..m] */
        MSort(SR, TR2, m+1, t);         /* 递归将SR[m+1..t]归并为有序的TR2[m+1..t] */
        Merge(TR2, TR1, s, m, t);       /* 将TR2[s..m]和TR2[m+1..t]合并为有序的TR1[s..t] */
    }
}


/* Merge: 将两个有序子序列合并为一个有序序列*/
void Merge(int SR[], int TR[], int s, int m, int t){
    int i, j, k;

    for (i = s, j = m + 1, k = s; i <= m && j <= t; k++){   /* 依次比较两个子序列中的元素 */
        if (SR[i] <= SR[j]){
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }

    for (; i <= m; i++, k++){                               /* 将子序列[s..m]剩余元素放入 */
        TR[k] = SR[i];
    }

    for (; j <= t; j++, k++){                               /* 将子序列[m+1..t]剩余元素放入 */
        TR[k] = SR[j];
    }
}


/* 
MergeSort2: 非递归方式的归并排序
节省大量空间开销
两层循环，外层以倍数方式不断加长子序列，
内层以循环方式两两归并两个子序列 
*/
void MergeSort2(SqlList *lp){
    int k = 1;
    int *TR = (int *)malloc((lp->length) *sizeof(int));

    while (k < lp->length){
        MergePass(lp->data, TR, k, lp->length);
        k *= 2;                                     /* 扩大子序列长度 */
        MergePass(TR, lp->data, k, lp->length);
        k *= 2;
    }
}


/* MergePass: 将SR中相邻的两个长度为s的子序列归并到TR中 */
void MergePass(int SR[], int TR[], int s, int t){
    int i, k;

    for (i = 1; i <= t /(2*s); i++){        /* 将2个s序列看做一组，进行循环 */
        k = (i - 1) * 2 * s + 1;
        Merge(SR, TR, k, k+s-1, k+2*s-1);
    }

    k = (i - 1) * 2 * s + 1;
    if ((t-k+1) <= s){                      /* 剩余的序列长度是否超过s，如果没超过，直接放入 */
        for (i = k; i <= t; i++){
            TR[i] = SR[i];
        }
    } else {                                /* 如果超过，将剩余序列拆为2个子序列进行合并，其中1个长度为s，另一个不足s */
        Merge(SR, TR, k, k+s-1, t);
    }
}