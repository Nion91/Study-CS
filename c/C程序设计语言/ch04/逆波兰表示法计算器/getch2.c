#include <stdio.h>

static int buff = EOF;

int getch2(void){
    int tmp;
    if (buff != EOF){
        tmp = buff;
        buff = EOF;
        return tmp;
    } else {
        return getchar();
    }
}

void ungetch2(int c){
    if (buff==EOF){
        buff = c;
    } else {
        printf("error: buff is full\n");
    }
}
