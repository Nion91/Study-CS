#include <stdio.h>
#include <string.h>
#include "head.h"
#define MAXSIZE 1000

int readlines(char *lineptr[], int limitlines){
    int len, nlines = 0;
    char *p, line[MAXSIZE];
    while((len = getline(line, MAXSIZE)) > 0){
        if (nlines >= limitlines || (p = alloc(len)) == NULL){
            return -1;
        }
        line[len - 1] = '\0';   /* 删除换行符 */
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}