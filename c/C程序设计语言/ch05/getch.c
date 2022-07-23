#include <stdio.h>

#define MAXBUFF 100

static int buffer[MAXBUFF];
static int sp = 0;

int getch(void){
    return (sp>0) ? buffer[--sp] : getchar();
}

void ungetch(int c){
    if (sp < MAXBUFF){
        buffer[sp++] = c; 
    } else {
        printf("Error: buffer is full\n");
    }
}
