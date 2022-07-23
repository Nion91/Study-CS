#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];     /* 指针表 */

/* hash: 为字符串s生成散列值 */
unsigned hash(char *s){
    unsigned int res = 0;
    int c;
    while (*s != '\0'){
        res = *s + 31 * res;
        s++;
    }

    return res % HASHSIZE;
}


/* lookup: 在hashtab中查找字符串s */
struct nlist *lookup(char *s){
    struct nlist *p;

    for (p = hashtab[hash(s)]; p != NULL; p = p->next){
        if (strcmp(s, p->name) == 0)
            break;
    }
    return p;
}


/* install: 将(name, defn)加入到hashtab中 */
struct nlist *install(char *name, char *defn){
    struct nlist *pn;
    pn = lookup(name);
    if (pn == NULL){
        pn = (struct nlist *) malloc(sizeof(struct nlist));
        pn->name = strdup(name);
        pn->next = hashtab[hash(name)];
        hashtab[hash(name)] = pn;
    } else {
        free((void *) pn->defn);
    }
    pn->defn = strdup(defn);
    return pn;
}


/* hashprint: 打印hashtable中的链表 */
void hashprint(void){
    int i;
    struct nlist *np;

    for (i = 0; i < HASHSIZE; i++){
        for(np = hashtab[i]; np != NULL; np = np->next)
            printf("%s:\t%s\n", np->name, np->defn);
    }
}

/* undef: 在hashtable中删除变量名name */
struct nlist *undef(char *name){
    struct nlist *pn, *lastpn;
    for (pn = hashtab[hash(name)], lastpn = NULL; pn != NULL; lastpn = pn, pn = pn->next){
        if (strcmp(name, pn->name) == 0){
            break;
        }
    }
    if (pn != NULL){
        if (lastpn != NULL){
            lastpn->next = pn->next;
        } else {
            hashtab[hash(name)] = pn->next;
        }
    }
    return pn;
}
