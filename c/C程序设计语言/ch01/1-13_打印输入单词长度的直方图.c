#include <stdio.h>

#define MAXLEN 50   /* 单词最大长度 */

main(){
    int c, wlen, mlen, i, j;
    int warr[MAXLEN];

    wlen = mlen = 0;
    for(i = 0; i<50; i++){
        warr[i] = 0;
    }

    /* 统计单词长度 */
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(wlen > 0){
                warr[wlen-1]++;
                if(wlen > mlen){
                    mlen = wlen;
                }
                wlen = 0;
            }
        } else {
            wlen++;
        }
    }

    /* 打印水平直方图 */
    for(i = 0; i < mlen; i++){
        printf("%2d: ", i+1);
        for(j = 0; j < warr[i]; j++){
            printf("1");
        }
        printf("\n");
    }

    printf("\n\n-------------------\n\n\n");

    /* 打印垂直直方图 */
    int mfeq = 0;
    for(i = 0; i < mlen; i++){
        if(warr[i] > mfeq){
            mfeq = warr[i];
        }
    }

    for(i = 0; i < mfeq; i++){
        for(j = 0; j < mlen; j++){
            if(warr[j] >= mfeq-i){
                printf("1");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i = 0; i < mlen; i++){
        printf("-");
    }
    printf("\n");

    for(i = 0; i < mlen; i++){
        printf("%d", i+1);
    }
    printf("\n");
}