#include <stdio.h>

main(){
    int c, lc;

    lc=EOF;
    while((c=getchar()) != EOF){
        if(c != ' ' || lc != ' '){
            putchar(c);
            lc = c;
        }
    }
}