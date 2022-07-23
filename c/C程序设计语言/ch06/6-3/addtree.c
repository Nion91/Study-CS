#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "main.h"

struct tnode *talloc(void);
char *strdup_2(char *word);
extern int line_no;

struct tnode *addtree(struct tnode *root, char *word){
    int cond;
    if (root == NULL){
        root = talloc();
        if (root != NULL){
            root->word = strdup_2(word);
            int i;
            for (i = 0; i < ARRLEN; i++)
                (root->arr)[i] = 0;
            (root->arr)[line_no] = 1;
            root->count = 1;
            root->left = root->right = NULL;
        }
    } else {
        if ((cond = strcmp(word, root->word)) > 0){
            root->right = addtree(root->right, word);
        } else if (cond < 0){
            root->left = addtree(root->left, word);
        } else {
            (root->arr)[line_no]++;
            root->count++;
        }
    }
    return root;
}




struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}


char *strdup_2(char *word){
    char *w;
    w = (char *) malloc(strlen(word) + 1);
    if (w){
        strcpy(w, word);
    }
    return w;
}

