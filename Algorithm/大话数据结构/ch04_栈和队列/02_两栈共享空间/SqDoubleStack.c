#include <stdio.h>
#include <stdlib.h>
#include "SqDoubleStack.h"


/* Push：将元素e压入序号为stacknum的栈 */
int Push(SqDoubleStack *sp, SElemType e, int stacknum){
    if (stacknum < 1 || stacknum > 2){
        printf("Wrong stacknum\n");
        return 0;
    }

    if (StackFull(*sp)){
        printf("Stack is full\n");
        return 0;
    }

    if (stacknum == 1){
        sp->top1++;
        sp->data[sp->top1] = e;
    } else {
        sp->top2--;
        sp->data[sp->top2] = e;
    }
    return 1;
}


/* Pop: 弹出stacknum的栈顶元素，通过*ep返回 */
int Pop(SqDoubleStack *sp, SElemType *ep, int stacknum){
    if (stacknum < 1 || stacknum > 2){
        printf("Wrong stacknum\n");
        return 0;
    }
    if (StackEmpty(*sp, stacknum)){
        printf("Stack is empty\n");
        return 0;
    }

    if (stacknum == 1){
        *ep = sp->data[sp->top1--];
    } else {
        *ep = sp->data[sp->top2++];
    }
    return 1;
}


/* InitStack: 初始化栈 */
SqDoubleStack * InitStack(){
    SqDoubleStack *sp;
    sp = (SqDoubleStack *)malloc(sizeof(SqDoubleStack));
    sp->top1 = -1;
    sp->top2 = MAXSIZE;
    return sp;
}


/* DestroyStack: 销毁栈 */
void DestroyStack(SqDoubleStack *sp){
    if (sp)
        free(sp);
}

/* ClearStack: 根据stacknum清空栈 */
void ClearStack(SqDoubleStack *sp, int stacknum){
    switch (stacknum){
        case 0:
            sp->top1 = -1;
            sp->top2 = MAXSIZE;
            break;
        case 1:
            sp->top1 = -1;
            break;
        case 2:
            sp->top2 = MAXSIZE;
            break;
        default:
            printf("Wrong stacknum\n");
    }
}

/* StackEmpty: 根据stacknum返回栈是否为空 */
int StackEmpty(SqDoubleStack S, int stacknum){
    switch (stacknum){
        case 0:
            return StackEmpty(S, 1) || StackEmpty(S, 2);
        case 1:
            return S.top1 == -1 ? 1 : 0;
        case 2:
            return S.top2 == MAXSIZE ? 1 : 0;
        default:
            printf("Wrong stacknum\n");
            return -1;
    }
}

/* StackFull: 返回栈是否已满 */
int StackFull(SqDoubleStack S){
    return S.top1 + 1 == S.top2 ? 1 : 0;
}

/* GetTop: 根据stacknum取栈顶元素 */
int GetTop(SqDoubleStack S, SElemType *ep, int stacknum){
    if (stacknum < 1 || stacknum > 2){
        printf("Wrong stacknum\n");
        return 0;
    }

    if (StackEmpty(S, stacknum)){
        printf("Stack is empty\n");
        return 0;
    }
    
    *ep = (stacknum == 1) ? S.data[S.top1] : S.data[S.top2];
}

/* StackLength: 根据stacknum返回栈的长度 */
int StackLength(SqDoubleStack S, int stacknum){
    switch(stacknum){
        case 0:
            return StackLength(S, 1) + StackLength(S, 2);
        case 1:
            return S.top1 + 1;
        case 2:
            return MAXSIZE - S.top2;
        default:
            printf("Wrong stacknum");
            return -1; 
    }
}