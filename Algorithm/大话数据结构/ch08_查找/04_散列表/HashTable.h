#define HASHSIZE 12         /* 定义散列表长度 */
#define NULLKEY -32768

/* 定义数据结构 */
typedef struct {
    int *elem;              /* 数据元素存储基址，动态分配数组 */
    int count;              /* 当前数据元素个数 */
} HashTable;


/* 定义操作 */
void InitHashTable(HashTable *hp);
int Hash(int key);
int InsertHash(HashTable *hp, int key);
int SearchHash(HashTable H, int key, int *addr);

void PrintHash(HashTable H);

