#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "main.h"

struct fnode *falloc(void);

struct fnode *addvartree(struct fnode *root, char *word, int len){
    char varname[MAXWORD];
    strncpy(varname, word, len);
    if (root == NULL){
        root = falloc();
        if (root){
            root->var = strdup(varname);
            root->vartree = addtree(NULL, word);
            root->left = NULL;
            root->right = NULL;
        }
    } else {
        int cond = strcmp(varname, root->var);
        if (cond > 0){
            root->right = addvartree(root->right, word, len);
        } else if (cond < 0){
            root->left = addvartree(root->left, word, len);
        } else {
            root->vartree = addtree(root->vartree, word);
        }
    }
    return root;
}


struct fnode *falloc(void){
    return (struct fnode *) malloc(sizeof(struct fnode));
}


void vartreeprint(struct fnode *root){
    if (root != NULL){
        vartreeprint(root->left);
        printf("varname: %s\n", root->var);
        treeprint(root->vartree);
        vartreeprint(root->right);
    }
}