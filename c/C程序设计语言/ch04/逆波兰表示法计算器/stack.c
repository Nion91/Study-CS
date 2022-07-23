#include <stdio.h>
#include "calc.h"
#define MAXVAL  100     /* 栈的最大深度 */

double stack[MAXVAL];   /* 值栈 */
int cursor=0;           /* 下一个空闲栈位置 */

/*  push：把val压如值栈中   */
void push(double val){
    if (cursor < MAXVAL){
        stack[cursor++] = val;
    } else {
        printf("Stack is fullsize\n");
    }
}

/*  pop：弹出并返回栈顶的值 */
double pop(void){
    if (cursor > 0){
        return stack[--cursor];
    } else {
        printf("Stack is empty\n");
        return 0.0;
    }
}

/* printtop: 打印栈顶元素 */
void printtop(void){
    if (cursor > 0){
        printf("printtop: %g\n", stack[cursor-1]);
    } else {
        printf("error: Stack is empty\n");
    }
}

/* copytop：复制栈顶元素 */
void copytop(void){
    if (cursor > 0){
        push(stack[cursor - 1]);
    } else {
        printf("error: Stack is empty\n");
    }
}

/* swaptop: 交换栈顶两个元素 */
void swaptop(void){
    if (cursor < 2){
        printf("error: less then 2 element\n");
    } else {
        double tmp = stack[cursor - 1];
        stack[cursor-1] = stack[cursor-2];
        stack[cursor-2] = tmp;
    }
}

/* clearstack: 清空栈 */
void clearstack(void){
    while (cursor > 0){
        pop();
    }
    printf("Stack is empty\n");
}