#include <ctype.h>
#include <stdio.h>
#include "head.h"

int getint(int *pn){
    int sign, c;
    while(isspace(c = getch())){
        ;
    }
    if (!isdigit(c) && c!='+' && c!='-' & c!=EOF){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c=='+' || c=='-'){
        c = getch();
        if (!isdigit(c)){
            ungetch(c);
            ungetch((sign==1) ? '+' : '-');
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()){
        *pn = *pn * 10 + c - '0';
    }
    *pn *= sign;
    if (c != EOF){
        ungetch(c);
    }
    return c;
}