#include <stdio.h>
#include <string.h>
#include "calculator.h"


main(){
    char s[MAXSIZE];
    char exp[] = "9+(3-1)*3+10/2";

    /* 
    将中缀表达式转为后缀表达式 
    输入9+(3-1)*3+10/2
    打印9 3 1 - 3 * + 10 2 / +
    */
    InfixToPostfix(exp, s);
    printf("%s\n", s);

    /* 
    计算后缀表达式
    输入9 3 1 - 3 * + 10 2 / +
    打印20
    */
    printf("%d\n", CalPostfix(s));
}