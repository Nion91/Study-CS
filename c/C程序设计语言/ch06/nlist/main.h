
struct nlist {              /* 链表项 */
    struct nlist *next;     /* 链表中的下一项 */
    char *name;             /* 定义的名字 */
    char *defn;             /* 替换的文本 */
};

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void hashprint(void);

int getword(char *, int);
int getword2(char *, int);
int getdefine(char *, char *, int);

struct nlist *undef(char *name);