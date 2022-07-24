#include <stdio.h>
#include "stack.h"


void PrintStack(Stack S);

main(){
    Stack *sp;
    ElemType a;

    /* 初始化 */
    printf("======================init=====================\n");
    sp = InitStack();
    PrintStack(*sp);

    /* 入栈 */
    printf("======================push=====================\n");
    Push(sp, 1);
    Push(sp, 2);
    PrintStack(*sp);

    /* 出栈 */
    printf("======================pop=====================\n");
    Pop(sp, &a);
    printf("pop: %d\n", a);
    PrintStack(*sp);
    Pop(sp, &a);
    Pop(sp, &a);
}



void PrintStack(Stack S){
    int i;
    for (i = S.top; i >= 0; i--){
        printf("%d\n", S.data[i]);
    }
}

