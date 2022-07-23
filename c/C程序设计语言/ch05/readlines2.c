#include <stdio.h>
#include <string.h>
#include "head.h"
#define MAXLEN 10000

int readlines2(char *lineptr[], char linebuff[], int limitlines){
    int len, nlines = 0;
    char *p, line[MAXLEN];
    lineptr[0] = p = linebuff;
    while ((len = getline(line, MAXLEN)) > 0 && (p+len) <= (lineptr[0]+MAXLEN)){
        line[len-1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
        p += len;
    }
    return nlines;
}