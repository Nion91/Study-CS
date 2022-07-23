#include <stdio.h>

#define MAXNODE 100
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

static struct tnode *nodelist[MAXNODE];
static struct tnode **pt = nodelist;


void sorttreelist(struct tnode *nodelist[], struct tnode **left, struct tnode **right);
int lentree(struct tnode *p); 
void gettree(struct tnode *tree);

void descprint(struct tnode *p){
    gettree(p);
    struct tnode **left = nodelist, **right = (pt-1);

    sorttreelist(nodelist, left, right);
    struct tnode **tmp = pt;
    while (--tmp >= nodelist){
        printf("%s:\t %d\n", (**tmp).word, (**tmp).count);
    }
}

/*计算节点数量*/
int lentree(struct tnode *p){
    if (p == NULL){
        return 0;
    } else {
        return 1 + lentree(p->left) + lentree(p->right);
    }
}

/*将指向节点的指针存到nodelist*/
void gettree(struct tnode *tree){
    if (tree != NULL){
        *(pt++) = tree;
        gettree(tree->left);
        gettree(tree->right);
    }
}


/*按出现频率排序*/
void sorttreelist(struct tnode *nodelist[], struct tnode **left, struct tnode **right){
    struct tnode *temp;
    struct tnode **i, **j;

    if (left >= right){
        return;
    }
    for (i = j = left; i < right; i++){
        if ((*i)->count < (*right)->count){
            temp = *i;
            *i = *j;
            *j = temp;
            j++;
        }
    }
    temp = *j;
    *j = *right;
    *right = temp;

    
    if (j > left){
        sorttreelist(nodelist, left, j-1);
    }
    sorttreelist(nodelist, j+1, right);
}







