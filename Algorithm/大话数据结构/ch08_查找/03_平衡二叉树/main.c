#include <stdio.h>
#include "AvlTree.h"

main(){
    AvlBiTree T = NULL;

    printf("\n==============================insert============================\n");
    int a[10] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    int i, taller;

    for (i = 0; i < 10; i++)
        InsertAVL(&T, a[i], &taller);
    PrintAVL(T);
}
