#include <stdio.h>

main(){
    int c;
    int b, t, n;    /* 空格、制表符、换行符统计变量 */

    for(b=0, t=0, n=0; (c=getchar()) != EOF;){
        if (c == ' '){
            b++;
        } else if (c == '\t'){
            t++;
        } else if (c == '\n'){
            n++;
        }
    }

    printf("blank: %d\ntab: %d\nenter: %d\n", b, t, n);
}