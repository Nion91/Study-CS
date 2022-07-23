#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getdefine(char *name, char *defn, int len){
    int getword2(char *, int);

    char word[len];

    while (getword2(word, len) != EOF){
        if (strcmp(word, "#define") != 0)
            continue;
        if (getword2(name, len) == EOF)
            break;
        else if (!isalpha(*name))
            continue;
        if (getword2(defn, len) == EOF)
            break;
        return *name;
    }
    
    return EOF;

}