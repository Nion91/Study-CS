#include <stdio.h>
#include <string.h>
#include "dcl_main.h"

extern int tokentype;
extern char token[MAXLEN];
extern char out[MAXLEN];
extern char bufftoken[MAXLEN];
extern int bufftokentype;
extern int buffflg;

void undcl(void){
    char temp[MAXLEN];
    while(gettoken() != '\n'){
        if (tokentype == NAME){
            sprintf(temp, "%s %s", token, out);
            strcpy(out, temp);
        }   
        else if (tokentype == '*'){
            if (gettoken() != NAME && tokentype != '*'){
                sprintf(temp, "(*%s)", out);   
            } else {
                sprintf(temp, "*%s", out);
            }
            strcpy(out, temp);
            strcpy(bufftoken, token);
            bufftokentype = tokentype;
            buffflg = 1;
        } else if (tokentype == PARENS || tokentype == BRACKETS){
            strcat(out, token);
        } else {
            printf("Wrong token\n");
            return;
        }
    }
}


