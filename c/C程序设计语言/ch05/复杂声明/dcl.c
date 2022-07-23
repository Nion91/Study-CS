#include <stdio.h>
#include <string.h>
#include "dcl_main.h"

extern int buffflg2;
void dcl(void){
    int ns = 0;
    while (gettoken() == '*')
        ns++;
    dirdcl();
    while (ns-- > 0){
        strcat(out, " pointer to");
    }
}


