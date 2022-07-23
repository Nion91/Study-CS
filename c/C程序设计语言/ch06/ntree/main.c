#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "main.h"




/*统计单词出现的频率*/

main(){
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF){
        if (isalpha(word[0])){
            root = addtree(root, word);
        }
    }

    treeprint(root);

    return 0;
}
