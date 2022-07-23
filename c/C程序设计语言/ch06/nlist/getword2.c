#include <stdio.h>
#include <ctype.h>

int getword2(char *word, int limitlen){
    int getch(void);
    void ungetch(int);
    char *w = word;
    int c;
    
    while (isspace(c = getch()))
        ;
    if (c != EOF){
        *w++ = c;
    } else {
        return EOF;
    }
    
    for (; --limitlen > 0; w++){
        if (isspace(*w = getch()) || *w == EOF){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}
