#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

/* Push: 将元素e加入栈中 */
int Push(LinkStack *lp, SElemType e){
    LinkStackPtr kp;
    if ((kp = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL){
        printf("Error: No space\n");
        return 0;
    }

    kp->data = e;
    kp->next = lp->top;
    lp->top = kp;
    lp->count++;
    return 1;
}


/* Pop: 将栈顶元素弹出，通过*ep返回 */
int Pop(LinkStack *lp, SElemType *ep){
    LinkStackPtr kp;
    if (StackEmpty(*lp)){
        printf("Error: Stack is empty\n");
        return 0;
    }

    kp = lp->top;
    *ep = kp->data;
    lp->top = kp->next;
    lp->count--;
    free(kp); 
    return 1;
}


/* InitStack: 初始化链栈 */
LinkStack * InitStack(){
    LinkStack *lp;
    lp = (LinkStack *)malloc(sizeof(LinkStack));
    if (lp == NULL){
        printf("Error: no space\n");
        return NULL;
    }

    lp->top = NULL;
    lp->count = 0;
    return lp;
}

/* DestroyStack: 销毁栈 */
void DestroyStack(LinkStack *lp){
    LinkStackPtr kp;
    while (lp->top){
        kp = lp->top;
        lp->top = kp->next;
        free(kp);
    }
    free(lp);
}

/* ClearStack: 清空栈 */
void ClearStack(LinkStack *lp){
    lp->top = NULL;
    lp->count = 0;
}

/* StackEmpty: 返回栈是否为空 */
int StackEmpty(LinkStack S){
    return S.count == 0 ? 1 : 0;
}

/* GetTop: 取栈顶元素，用*ep返回 */
int GetTop(LinkStack S, SElemType *ep){
    if (StackEmpty(S)){
        printf("Error: stack is empty\n");
        return 0;
    }

    *ep = S.top->data;
    return 1;
}

/* StackLength: 返回栈长度 */
int StackLength(LinkStack S){
    return S.count;
}