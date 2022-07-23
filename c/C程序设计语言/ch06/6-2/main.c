#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

main(int argc, char *argv[]){
    char word[MAXWORD];
    int c, n;
    struct fnode *root = NULL;

    n = (argc > 1) ? atoi(argv[1]) : 6;
    while ((c = getword2(word, MAXWORD)) != EOF){
        if (!isalnum(c) || strlen(word) < n){
            continue;
        }
        root = addvartree(root, word, n);
    }

    vartreeprint(root);
    return 0;
}
