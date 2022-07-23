#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl_main.h"



int gettoken(void){
    int c;
    char *p = token;
    if (buffflg){
        buffflg = 0;
        strcpy(token, bufftoken);
        return tokentype = bufftokentype;
    }
    
    while ((c = getch()) == ' ' || c == '\t')       /*跳过空格*/
        ;
    if (c == '('){
        if ((c = getch()) == ')'){                  /*识别函数*/
            strcpy(token, "()");    
            return tokentype = PARENS;
        } else if (c != '*') {                      /*识别带参数的函数*/
            *p++ = '(';
            for (*p = c; (c = getch()) != ')'; ){
                *++p = c;
            }
            *++p = c;
            *++p = '\0';
            return tokentype = PARENS;
        } else {                                    /*识别(*/
            ungetch(c);
            return tokentype = '(';         
        }
    } else if (c == '['){                           /*识别数组*/
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalnum(c)){                         /*识别变量名称*/
        *p++ = c;
        while (isalnum(c = getch())){
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}
