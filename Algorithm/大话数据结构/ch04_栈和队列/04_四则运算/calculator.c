#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculator.h"


/* InfixToPostfix: 将中缀表达式s1转化为后缀表达式s2 */
void InfixToPostfix(char *s2){
    int c, op;
    char word[MAXWORD];
    Stack * sp;

    sp = InitStack();                                                               /* 初始化栈 */
    *s2 = '\0';

    while ((c = getword(word, MAXSIZE)) != EOF){
        if (isdigit(c)){
            sprintf(s2, "%s%d ", s2, atoi(word));  
        } else if (c == '(') {
            Push(sp, c);
        } else if (c == ')'){
            while(1){
                Pop(sp, &op);
                if (op == '(')
                    break;
                sprintf(s2, "%s%c ", s2, op);
            }
        } else if (strchr("+-*/", c)){
            while (GetTop(*sp, &op) && GetPriority(c) <= GetPriority(op)){
                Pop(sp, &op);
                sprintf(s2, "%s%c ", s2, op);
            }
            Push(sp, c);
        }
    }

    while (!StackEmpty(*sp)){
        Pop(sp, &op);
        sprintf(s2, "%s%c ", s2, op);
    }
}



/* GetPriority：返回操作符优先级 */
int GetPriority(int c){
    switch (c){
        case '(': return 1;
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        default:
            printf("Error: wrong operator\n");
            return 0;
    }
}