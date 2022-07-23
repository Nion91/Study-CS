#include <stdio.h>
#include <string.h>
#include "dcl_main.h"

void dirdcl(void){
    if (tokentype == '('){
        dcl();
        if (tokentype != ')'){
            printf("Error: miss ')'\n");
            return;
        }
    } else if (tokentype == NAME){
        strcpy(name, token);
    } else {
        printf("Error: expected name or (dcl)\n");
        return;
    }

    while (gettoken() == PARENS || tokentype == BRACKETS){
        if (tokentype == PARENS){
            if (strcmp(token, "()") == 0)
                strcat(out, " function returning");
            else {
                char temp[MAXLEN];
                char *pt = token;
                strcpy(temp, ++pt);
                temp[strlen(temp)-1] = '\0';
                strcat(out, " function with ");
                strcat(out, temp);
                strcat(out, " returning");
            }
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

