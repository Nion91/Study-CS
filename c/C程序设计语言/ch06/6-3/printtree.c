#include <stdio.h>
#include "main.h"


void printtree(struct tnode *root){
    int i;
    if (root){
        printtree(root->left);
        printf("%s:\t%d\tno:", root->word, root->count);
        for (i = 0; i < ARRLEN; i++){
            if ((root->arr)[i] > 0){
                printf(" %d", i);
            }
        }
        printf("\n");
        printtree(root->right);
    }
}