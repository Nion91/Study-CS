#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Push：将e压入栈 */
int Push(Stack *sp, ElemType e){
    if (StackFull(*sp)){
        printf("Stack is full\n");
        return 0;
    }
    
    sp->top++;
    sp->data[sp->top] = e;
    return 1;
}

/* Pop: 弹出栈顶元素，并用*ep返回 */
int Pop(Stack *sp, ElemType *ep){
    if (StackEmpty(*sp)){
        printf("Stack is empty\n");
        return 0;
    }
    
    *ep = sp->data[sp->top];
    sp->top--;
    return 1;
}


/* InitStack：初始化栈 */
Stack * InitStack(){
    Stack *sp;
    if ((sp = (Stack *)malloc(sizeof(Stack))) == NULL){
        printf("No space for stack\n");
        return NULL;
    }
    sp->top = -1;
    return sp;
}

/* DestropStack: 销毁栈 */
void DestroyStack(Stack *sp){
    if (sp)
        free(sp);
}

/* ClearStack: 清空栈 */
void ClearStack(Stack *sp){
    sp->top = -1;
}

/* StackEmpty: 返回栈是否为空 */
int StackEmpty(Stack S){
    return S.top == -1? 1 : 0;
}

/* StackFull: 返回栈是否已满 */
int StackFull(Stack S){
    return S.top == MAXSIZE - 1 ? 1 : 0;
}

/* GetTop: 取栈顶元素，并用*ep返回 */
int GetTop(Stack S, ElemType *ep){
    if (StackEmpty){
        printf("Stack is empty\n");
        return 0;
    }

    *ep = S.data[S.top];
    return 1;
}

/* StackLength：返回栈内元素数量 */
int StackLength(Stack S){
    return S.top + 1;
}

