#include <stdio.h>
#include <string.h>

int simple_index(char *s, char *p, int pos);
int simple_index2(char *s, char *p, int pos);

main(){
    printf("match pos: %d\n", simple_index("goodgoogle", "google", 0));
    printf("match pos: %d\n", simple_index2("goodgoogle", "google", 0));
}



/* simple_index: 返回模式串p在主串s匹配成功的第一个子串的起始位置 */
int simple_index(char *s, char *p, int pos){
    int i, j, m, n;
    m = strlen(s);
    n = strlen(p);

    for (i = pos; i < m - n + 1; i++){
        for (j = 0; j < n; j++){
            if (s[i+j] != p[j])
                break;
        }
        if (j == n)
            return i;
    }
    return -1;
}



int simple_index2(char *s, char *p, int pos){
    int i, j, m, n;
    m = strlen(s);
    n = strlen(p);

    i = pos;
    j = 0;
    while (i < m && j < n){
        if (s[i] == p[j]){
            i++;
            j++;
        } else {                /* 如果不匹配，进行回退 */
            i = i - j + 1;      /* i回退到不匹配的起始位置的后一位 */
            j = 0;              /* j回退到0 */
        }
    }

    return j == n ? i - j : -1;
}
