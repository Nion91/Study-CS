#define MAXALLOC 1000   /* 可用空间大小 */

static char allocbuf[MAXALLOC];     /* alloc使用的存储区 */
static char *allocp = allocbuf;     /* 下一个空闲位置 */

char * alloc(int n){
    if (allocbuf + MAXALLOC - allocp >= n){
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *pa){
    if (pa >= allocbuf && pa < allocbuf + MAXALLOC){
        allocp = pa;
    }
}