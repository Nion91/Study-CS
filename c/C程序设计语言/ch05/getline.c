#include <stdio.h>

int getline(char *p, int limitlen){
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        *p++ = c;
    }
    if (c == '\n'){
        *p++ = '\n';
        i++;
    }
    *p = '\0';
    return i;
}