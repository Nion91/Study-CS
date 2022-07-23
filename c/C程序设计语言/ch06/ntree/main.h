#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};


struct tnode *addtree(struct tnode *root, char *word);
void treeprint(struct tnode *);
int getword(char *, int);