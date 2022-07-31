#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int kmp_index(char *s, char *p, int pos);
int * get_next(char *s);

main(){
    printf("match pos: %d\n", kmp_index("goodgoogle", "google", 0));
}

/* kmp_index: 返回模式串p在主串s匹配成功的第一个子串的起始位置 */
int kmp_index(char *s, char *p, int pos){
    int i, j, m, n, *next;
    m = strlen(s);
    n = strlen(p);

    next = get_next(p);
    i = pos;
    j = 0;
    while (i < m && j < n){
        if (j == -1 || s[i] == p[j]){
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == n)
        return i - j;
    else 
        return -1;
}


/* get_next: 返回模式串s的next数组 */
int * get_next(char *s){
    int i, j, m, *next;
    m = strlen(s);

    next = (int *)malloc(m * sizeof(int));
    next[0] = -1;
    i = 1;  /* 后缀指针 */
    j = 0;  /* 前缀指针 */
    while (i < m){
        if (j == -1 || s[i] == s[j]){
            next[i] = j;
            i++;
            j++;
        } else {
            j = next[j];    /* 当s[i]!=s[j]时，j回退 */
        }
    }
    return next;
}

