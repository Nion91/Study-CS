#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct fnode {
    char *var;
    struct tnode *vartree;
    struct fnode *left;
    struct fnode *right;
};

struct tnode *addtree(struct tnode *root, char *word);
struct fnode *addvartree(struct fnode *root, char *word, int len);
void vartreeprint(struct fnode *);
void treeprint(struct tnode *);
int getword2(char *, int);