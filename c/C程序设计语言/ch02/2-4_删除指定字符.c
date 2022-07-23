#include <stdio.h>

void squeeze(char s1[], char s2[]);

main(){
    char s1[] = "hello, world";
    char s2[] = "ol";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]){
    int i, j, k;
    i = 0;
    while(s1[i] != '\0'){
        j = 0;
        while(s2[j] != '\0'){
            if(s1[i] == s2[j]){
                for(k = i; s1[k] != '\0'; k++){
                    s1[k] = s1[k+1];
                }
                break;
            } else {
                j++;
            }
        }
        if(s2[j] == '\0'){
            i++;
        }
    }
}

