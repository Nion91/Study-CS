#include <stdio.h>
#include "main.h"

void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        printf("%s:\t%d\n", p->word, p->count);
        treeprint(p->right);
    }
}