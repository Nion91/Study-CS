#include <stdio.h>
#define BUFSIZE 100 

static char buffer[BUFSIZE];        /*设置缓存*/
static char *pb = buffer;           /*指向下一个缓存位置*/

char getch(void){
    return (pb > buffer) ? *--pb : getchar();
}

void ungetch(char c){
    if (pb >= buffer + BUFSIZE){
        printf("Error: buffer is full\n");
    } else {
        *pb++ = c;
    }
}

