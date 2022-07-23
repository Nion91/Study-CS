#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);

main(){
    char s1[]="-0-5a-cA-D", s2[MAXLINE];
    expand(s1, s2);
    printf("%s\n", s2);
}

void expand(char s1[], char s2[]){
    int i, j, k;
    i = j = 0;
    while (s1[i] != '\0'){
        if (s1[i+1] == '-' ){
            if((islower(s1[i]) && islower(s1[i+2])) || 
            (isupper(s1[i]) && isupper(s1[i+2])) || 
            (isdigit(s1[i]) && isdigit(s1[i+2]))){
                for (k = s1[i]; k <= s1[i+2]; k++, j++){
                    s2[j] = k;
                }
                i += 3;
            } else {
                s2[j++] = s1[i++];
            }
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}

