#include <stdio.h>
#include <string.h>

#include "main.h"

main(){
    char word[MAXWORD];
    struct tnode *root = NULL;
    while (getword(word, MAXWORD) != EOF){
        root = addtree(root, word);
    }
    printtree(root);
    return 0;
}
