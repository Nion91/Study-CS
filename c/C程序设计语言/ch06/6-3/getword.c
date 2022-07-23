#include <stdio.h>
#include <ctype.h>

#include "main.h"
int line_no = 0;
int getword(char *word, int limitlen){
    int getch(void);
    void ungetch(int);
    char *w = word;
    int c;

    
    while (isspace(c = getch())){
        if (c == '\n')
            line_no++;
    }
    if (c != EOF){
        *w++ = c;
    } else {
        line_no = 0;
    }
    if (!isalpha(c) && c != '_'){
        *w = '\0';
        return c;
    }
    for (; --limitlen > 0; w++){
        if (!isalnum(*w = getch()) && *w != '_'){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}
