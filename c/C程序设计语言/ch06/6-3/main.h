#define MAXWORD 100
#define ARRLEN 20


struct tnode {
    char *word;
    int arr[ARRLEN];
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *root, char *word);
void printtree(struct tnode *root);
int getword(char *word, int limitlen);