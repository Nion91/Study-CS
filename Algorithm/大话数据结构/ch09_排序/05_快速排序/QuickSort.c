#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"


/* 
QuickSort: 快速排序 
自顶向下，将序列分为小数组和大数组
*/
void QuickSort(SqlList *lp){
    QSort(lp->data, 1, lp->length);
}

/* QSort: 对SR[s..t]做快速排序；选择SR[t]作为基数，比SR[t]小的放入小数区，大的放入大数区 */
void QSort(int SR[], int s, int t){
    int i, j;

    if (s >= t)                         /* s>=t，递归结束 */
        return;

    for (i = s, j = s; i < t; i++){     /* 将每个元素和SR[t]比较，如果比它小，放到小数区 */
        if (SR[i] < SR[t]){
            SwapArr(SR, i, j++);        /* j为小数区的指针，在j前面的元素都比SR[t]小 */
        }
    }
    SwapArr(SR, j, t);                  /* 将t放到j的位置 */

    QSort(SR, s, j-1);                  /* 对小数区递归 */
    QSort(SR, j+1, t);                  /* 对大数区递归 */
}


/* SwapArr: 将SR[]的第i个和第j个元素交换 */
void SwapArr(int SR[], int i, int j){
    int tmp = SR[i];
    SR[i] = SR[j];
    SR[j] = tmp;
}

