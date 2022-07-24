#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"


void PrintStack(LinkStack S);

main(){
    LinkStack *sp;
    SElemType a;
    int i;

    /* 初始化 */
    printf("======================init=====================\n");
    sp = InitStack();
    PrintStack(*sp);

    /* 入栈 */
    printf("======================push=====================\n");
    for (i = 1; i <= 5; i++){
        Push(sp, i);
    }
    
    PrintStack(*sp);

    /* 出栈 */
    printf("======================pop=====================\n");
    Pop(sp, &a);
    printf("pop: %d\n", a);
    Pop(sp, &a);
    printf("pop: %d\n", a);
    PrintStack(*sp);

    /* 清空栈 */
    printf("=====================clear=====================\n");
    ClearStack(sp);
    Pop(sp, &a);
    PrintStack(*sp);
}



void PrintStack(LinkStack S){
    LinkStackPtr np;
    np = S.top;
    while (np){
        printf("%d\n", np->data);
        np = np->next;
    }
}
