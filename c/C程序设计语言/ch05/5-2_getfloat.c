#include <stdio.h>
#include <ctype.h>
#include "head.h"

int getfloat(double *pf){
    int c, sign;
    while(isspace(c = getch()))
        ;
    if (!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c=='+' || c=='-'){
        int next = getch();
        if (!isdigit(next) && next!='.'){
            ungetch(next);
            ungetch(c);
            return 0;
        } else {
            c = next;
        }
    }
    for (*pf = 0.0; isdigit(c); c = getch()){
        *pf = *pf * 10 + (c - '0');
    }
    if (c == '.'){
        c = getch();
        int n;
        for (n = 1; isdigit(c); c = getch()){
            *pf = *pf * 10 + (c - '0');
            n *= 10;
        }
        *pf = *pf / n;
    }
    *pf *= sign;
    if (c != EOF){
        ungetch(c);
    }
    return c;
}


