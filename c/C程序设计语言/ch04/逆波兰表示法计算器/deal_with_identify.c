#include <stdio.h>
#include <string.h>
#include <math.h>

#include "calc.h"

void deal_with_identify(char s[]){
    double op2;
    if (!strcmp(s, "sin")){
        push(sin(pop()));
    } else if (!strcmp(s, "cos")){
        push(cos(pop()));
    } else if (!strcmp(s, "exp")){
        push(exp(pop()));
    } else if (!strcmp(s, "log")){
        push(log(pop()));
    } else if (!strcmp(s, "pow")){
        op2 = pop();
        push(pow(pop(), op2));
    } else if (!strcmp(s, "sqrt")){
        push(sqrt(pop()));
    } else {
        printf("error: unknown command %s\n", s);
    }
}
