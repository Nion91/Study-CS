#include <string.h>

int strend(char *s, char *t){
    int n = strlen(s) - strlen(t);
    if (n < 0){
        return 0;
    }
    s += n;
    while (*s == *t){
        if (*s == '\0'){
            return 1;
        }
        s++;
        t++;
    }
    return 0;
}