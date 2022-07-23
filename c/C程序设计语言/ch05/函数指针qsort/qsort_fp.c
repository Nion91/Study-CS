#include <stdio.h>

void qsort(void *lineptr[], int left, int right, int (*cmp)(void *, void *)){
    void swap(void *s[], int i, int j);
    int i, j;
    if (left >= right){
        return;
    }
    for (i = j = left; i < right; i++){
        if ((*cmp)(lineptr[i], lineptr[right]) < 0){
            swap(lineptr,i, j++);
        }
    }
    swap(lineptr, j, right);
    qsort(lineptr, left, j-1, cmp);
    qsort(lineptr, j+1, right, cmp);
}


void swap(void *s[], int i, int j){
    void *tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
