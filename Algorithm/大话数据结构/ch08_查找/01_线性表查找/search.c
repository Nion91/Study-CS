#include <stdio.h>
#include "search.h"

/* 顺序表查找 */
/* Sequential_Search: 通过设置哨兵，减少每次循环时，i与n进行比较 */
int Sequential_Search(int *arr, int n, int key){
    int i;

    arr[n] = key;           /* 设置哨兵 */

    i = 0;
    while (arr[i] != key)
        i++;
    
    return i < n ? i : -1;
}


/* 有序表查找：应用于已排序数据 */
/* Binary_Search: 二分查找算法 */
int Binary_Search(int *arr, int n, int key){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (key > arr[mid])
            low = mid + 1;
        else if (key < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

/* Interpolation_Search: 插值查找算法，是二分查找的优化版 
   利用了key与arr[low]和arr[high]的距离，优先从靠近arr[low]或arr[high]的地方开始查找
   适用于arr较大且数值分布较均匀的数据，不适用分布极不均匀的数据 */
int Interpolation_Search(int *arr, int n, int key){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high){
        mid = low + (high - low) * (key - arr[low]) / (arr[high] - arr[low]);   /* 根据key计算mid */
        if (key > arr[mid])
            low = mid + 1;
        else if (key < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}


/* Fibonacci_Search: 斐波那契查找算法，需预先设置Fibonacci数组
   算法特点是借助于Fibonacci数组，计算过程中只需简单的加减法；
   以及以黄金比例分割上下半区，平均效率略优于二分查找 */
int F[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 56};
int Fibonacci_Search(int *arr, int n, int key){
    int low, high, mid;
    int k, i;

    low = 0;
    high = n - 1;
    k = 0;
    while (n > F[k] - 1)                    /* 计算k值 */
        k++;

    for (i = n; i < F[k]; i++)              /* 将数组arr补全到长度为F[k] */
        arr[i] = arr[n - 1];

    while (low <= high){
        mid = low + F[k-1] - 1;             /* 计算当前分割点下标 */
        if (key > arr[mid]){
            low = mid + 1;
            k = k - 2;
        } else if (key < arr[mid]){
            high = mid - 1;
            k = k - 1;
        } else
            return (mid >= n) ? n-1 : mid;
    }
    return -1;
}


