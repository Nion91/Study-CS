#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculator.h"


/* InfixToPostfix: 将中缀表达式s1转化为后缀表达式s */
void InfixToPostfix(char *s1, char *s2){
    int c, op;
    char word[MAXWORD];
    Stack * sp;

    sp = InitStack();  
    clearfill();        
    fillbuff(s1);                                                   
    *s2 = '\0';

    while ((c = getword(word, MAXSIZE)) != EOF){
        if (isdigit(c)){                            /* 输出数字 */
            sprintf(s2, "%s%d ", s2, atoi(word));  
        } else if (c == '(') {                      /* 将'('压入栈 */
            Push(sp, c);
        } else if (c == ')'){                       /* 依次弹出栈顶元素，直到'(' */
            while(1){
                Pop(sp, &op);
                if (op == '(')
                    break;
                sprintf(s2, "%s%c ", s2, op);
            }
        } else if (strchr("+-/*", c)){              /* 和栈顶元素逐个进行比较，直到遇到优先级更低的，将前面优先级更高的都弹出 */
            while (GetTop(*sp, &op) && GetPriority(c) <= GetPriority(op)){
                Pop(sp, &op);
                sprintf(s2, "%s%c ", s2, op);
            }
            Push(sp, c);
        }
    }

    while (!StackEmpty(*sp)){                       /* 当输入读完，依次弹出栈内所有元素 */
        Pop(sp, &op);
        sprintf(s2, "%s%c ", s2, op);
    }
    clearfill();
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


/* CalPostfix: 计算后缀表达式 */
int CalPostfix(char *s){
    Stack *sp;
    char word[MAXWORD];
    int c, op;

    sp = InitStack();
    clearfill();
    fillbuff(s);

    while ((c = getword(word, MAXWORD)) != EOF){
        if (isdigit(c)){                            /* 如果为数字，压入栈 */
            Push(sp, atoi(word));
        } else if (strchr("+-/*", c)){              /* 如果为四则运算符，弹出栈顶数字进行计算 */
            OpCal(c, sp);
        } else {
            printf("Error: wrong operator\n");
            break;
        }
    }
    clearfill();

    Pop(sp, &op);                                   /* 弹出栈顶数字，输出*/
    return op;
}


/* OpCal: 根据操作符计算 */
void OpCal(int c, Stack *sp){
    int op1, op2;

    Pop(sp, &op1);
    Pop(sp, &op2);
    switch (c)
    {
        case '+':
            Push(sp, op1+op2);
            break;
        case '-':      
            Push(sp, op2-op1);
            break;  
        case '*':
            Push(sp, op1*op2);
            break;
        case '/':      
            Push(sp, op2/op1);
            break;  
        default:
            printf("Error: wrong cal operator\n");
            break;
    }
}




/*
从屏幕输入
void InfixToPostfix(char *s){
    int c, op;
    char word[MAXWORD];
    Stack * sp;

    sp = InitStack();                                                               
    *s = '\0';

    while ((c = getword(word, MAXSIZE)) != EOF){
        if (isdigit(c)){
            sprintf(s, "%s%d ", s, atoi(word));  
        } else if (c == '(') {
            Push(sp, c);
        } else if (c == ')'){
            while(1){
                Pop(sp, &op);
                if (op == '(')
                    break;
                sprintf(s, "%s%c ", s, op);
            }
        } else if (strchr("+-/*", c)){
            while (GetTop(*sp, &op) && GetPriority(c) <= GetPriority(op)){
                Pop(sp, &op);
                sprintf(s, "%s%c ", s, op);
            }
            Push(sp, c);
        }
    }

    while (!StackEmpty(*sp)){
        Pop(sp, &op);
        sprintf(s, "%s%c ", s, op);
    }
}
*/
