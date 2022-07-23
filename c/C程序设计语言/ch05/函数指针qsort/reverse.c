#include <stdio.h>
#include "qsort_main.h"

void reverse(void *v[], int nlines){
    int i, j;
    for (i = 0, j = nlines-1; i < j; i++, j--){
        swap(v, i, j);
    }
}

