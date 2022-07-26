#include <stdio.h>
#include <ctype.h>


/* getword：获取单词 */
int getword(char *word, int limitlen){
    int getch(void);
    void ungetch(int);
    char *w = word;
    int c;
    
    while (isspace(c = getch()))
        ;
    if (c != EOF){
        *w++ = c;
    }
    if (!isalnum(c) && c != '_'){
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
