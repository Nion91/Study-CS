#include <stdio.h>

int any(char s1[], char s2[]);

main(){
    char s1[] = "hello, world";
    char s2[] = "ld";
    printf("%d\n", any(s1, s2));
}

int any(char s1[], char s2[]){
    int i, j;
    for(i = 0; s1[i] != '\0'; i++){
        j = 0;
        while(s2[j] != '\0'){
            if(s1[i] == s2[j]){
                return i;
            } else {
                j++;
            }
        }
    }
    return -1;
}