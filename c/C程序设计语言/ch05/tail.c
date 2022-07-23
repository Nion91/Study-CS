#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10000

static char buff[MAXLEN];
static char *pb = buff;
static char *p[100];

int getline(char *line, int limitline);

/* 将输入的最后n行打印出来 */
main(int argc, char *argv[]){
    int n = 2;
    int tmp, len, i;
    int srt;
    i = 0;
    /* 确认n */
    if (argc > 1 && (*++argv)[0] == '-'){
        if ((tmp = atoi((*argv)+1)) > 0) {
            n = tmp;
        }
    }

    /* 读取输入 */
    while ((len = getline(pb,MAXLEN)) > 1 && (pb+len) <= (buff+MAXLEN)){
        p[i++] = pb;
        pb += len;
    }
    /* 打印最后n行 */
    printf("\n===============\n");
    srt = (i > n) ? (i - n) : 0;
    for (;srt < i; srt++){
        printf("%s",p[srt]);
    }
}

int getline(char *line, int limitline){
    int c, n = limitline;
    while (limitline-- > 1 && (c = getchar()) != EOF && c != '\n'){
        *line++ = c;
    }
    if (c == '\n'){
        *line++ = c;
    }
    *line = '\0';
    return n - limitline;
}