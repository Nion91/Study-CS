#include <stdio.h>

void lower(char s[]);

main(){
    char s[] = "AbCdEF";
    lower(s);
    printf("%s\n", s);
}

void lower(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        s[i] = (s[i]>='A' && s[i]<='Z') ? s[i]-'A'+'a' : s[i];
    }
}