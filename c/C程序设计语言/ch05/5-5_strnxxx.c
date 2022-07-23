#include "head.h"

void my_strncpy(char *s, char *t, int n){
    while (n-- > 0){
        *s++ = *t++;
    }
    *s = '\0';
}

void my_strncat(char *s, char *t, int n){
    while (*s){
        s++;
    }
    while (n-- && (*s++ = *t++))
        ;
}

int my_strncmp(char *s, char *t, int n){
    while (n && *s == *t){
        n--;
        s++;
        t++;
    }
    
    if (n){
        return (*s - *t) > 0 ? 1 : -1;
    } else {
        return 0;
    }
}