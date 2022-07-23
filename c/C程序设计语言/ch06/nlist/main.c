#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

#define MAXWORD 100

main(){
    char name[MAXWORD];
    char defn[MAXWORD];
    int c;

    /*添加nlist*/
    while (getdefine(name, defn, MAXWORD) != EOF)
        install(name, defn);
    
    hashprint();

    /*删除nlist*/
    struct nlist *pn;
    while ((c = getword(name, MAXWORD)) != EOF){
        pn = undef(name);
        if (pn){
            printf("delete %s: %s\n", pn->name, pn->defn);
        }
    }
    hashprint();
    return 0;
}
