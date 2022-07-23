#include <stdio.h>

int htoi(char s[]);

main(){
    printf("%d\n", htoi("0Xa1"));
}

int htoi(char s[]){
    int i, n;
    i = n = 0;
    if(s[0]=='0' && (s[1]=='x' || s[1]=='X')){
        i = 2;
    }
    while(s[i] != '\0'){
        if(s[i]>='0' && s[i]<='9'){
            n = n * 16 + s[i] - '0';
        } else if(s[i]>='a' && s[i]<='f'){
            n = n * 16 + (s[i] - 'a' + 10);
        } else if(s[i]>='A' && s[i]<='F'){
            n = n * 16 + (s[i] - 'A' + 10);
        }
        i++;
    }
    return n;
}

