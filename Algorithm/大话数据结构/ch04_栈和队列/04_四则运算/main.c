#include <stdio.h>
#include "calculator.h"


main(){
    char s[MAXSIZE];
    
    InfixToPostfix(s);
    printf("%s\n", s);
    /* 
    输入9+(3-1)*3+10/2
    打印9 3 1 - 3 * + 10 2 / +
    */
    
}
