#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "main.h"

struct tnode *talloc(void);
char *strdup2(char *word);

struct tnode *addtree(struct tnode *root, char *word){
    struct tnode *p = root;
    int cond;
    if (p == NULL){
        p = talloc();
        if (p && (p->word = strdup2(word))){
            p->count = 1;
            p->left = NULL;
            p->right = NULL;
        }
    } else {
        if ((cond = strcmp(word, p->word)) < 0){
            p->left = addtree(p->left, word);
        } else if (cond > 0){
            p->right = addtree(p->right, word);
        } else {
            p->count++;
        }
    }
    return p;
}




struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}


char *strdup2(char *word){
    char *w;
    w = (char *) malloc(strlen(word) + 1);
    if (w){
        strcpy(w, word);
    }
    return w;
}

