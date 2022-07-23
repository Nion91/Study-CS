#include <stdio.h>

int strrindex(char s[], char t[]){
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++){
        for (j = i; t[k]!='\0' && s[j]==t[k]; j++, k++){
            ;
        }
        if (k>0 && t[k]=='\0'){
            return j;
        }
    }
    return -1;
}

