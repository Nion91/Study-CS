#include <stdio.h>

#define TABWIDTH 5  /*  设定制表符宽度  */

main(){
    int c, i, j, n;

    i = 0;
    while((c=getchar()) != EOF){
        if(c == '\t'){
            n = TABWIDTH - (i % TABWIDTH);
            for(j = 1; j <= n; j++){
                putchar(' ');
            }
            i += n;
        } else {
            putchar(c);
            if(c == '\n'){
                i = 0;
            } else {
                i++;
            }
        }
    }

    return 0;
}