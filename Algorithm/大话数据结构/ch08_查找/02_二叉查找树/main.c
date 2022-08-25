#include <stdio.h>
#include "BiTree.h"

main(){
    BiTree T = NULL;

    printf("\n==============================insert============================\n");
    int dat[] = {62, 58, 88, 73, 99, 93, 47, 35, 51, 29, 37, 36, 49, 56, 48, 50};
    int i;

    for (i = 0; i < 16; i++)
        InsertBST(&T, dat[i]);
    InsertBST(&T, 62);
    PrintBST(T);


    printf("\n==============================search1============================\n");
    BiTree *p;
    SearchBST(T, 37, NULL, p);
    PrintBST(*p);



    printf("\n==============================delete============================\n");
    DeleteBST(&T, 30);
    DeleteBST(&T, 47);
    PrintBST(T);


    printf("\n==============================search2============================\n");
    SearchBST(T, 37, NULL, p);
    PrintBST(*p);
}
