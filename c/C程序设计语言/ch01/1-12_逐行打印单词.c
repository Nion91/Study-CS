#include <stdio.h>

#define IN  1   /* 单词内部 */
#define OUT 0   /* 单词外部 */

main(){
    int c, status;

    status = OUT;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(status == IN){
                putchar('\n');
            }
            status = OUT;
        } else{
            putchar(c);
            status = IN;
        }
    }
}