#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]){
    int c, i;
    while((s[0] = c = getch()) == '\t' || c == ' '){
        ;
    }
    s[1] = '\0';
    if (!isalnum(c) && c!='.' && c!='-'){
        return c;
    }
    i = 0;
    if (isalpha(c)){                          /* 4-5_增加sin、exp等<math.h>操作 */
        while(isalpha(s[++i] = c = getch())){
            ;
        }
        ungetch(c);
        s[i] = '\0';
        return IDENTIFY;
    }
    if (c == '-'){
        c = getch();
        if (!isdigit(c) && c != '.'){
            ungetch(c);
            return s[0];
        } else {
            s[++i] = c;
        }
    }
    if(isdigit(c)){
        while(isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.'){
        while(isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;
}
