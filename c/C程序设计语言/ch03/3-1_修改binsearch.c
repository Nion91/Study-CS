#include <stdio.h>
#include <time.h>

#define MAXLEN 10000
int binsearch(int x, int v[], int n);

main(){
    int v[MAXLEN];
    int i, j;
    for(i = 0; i < MAXLEN; i++){
        v[i] = i;
    }

    printf("%d\n", binsearch(9, v, 20));

    /*测试运行时间*/
    clock_t start = clock(), end;
    for (i = 0; i < 5000; i++){
        for (j = 0; j < MAXLEN; j++){
            binsearch(j, v, MAXLEN);
        }
    }
    end = clock();
    printf("%.0f ms\n", (float) (end - start) / CLOCKS_PER_SEC * 1000);
    
}

/* binsearch：在v中查找x，返回x的位置；while循环内只进行一次if判断*/
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (low + high) / 2;
    while(low<=high && x!=v[mid]){
        if(x < v[mid]){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return x==v[mid] ? mid : -1;
}
