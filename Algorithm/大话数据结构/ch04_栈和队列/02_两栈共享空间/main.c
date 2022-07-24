#include <stdio.h>
#include "SqDoubleStack.h"


void PrintStack(SqDoubleStack S);

main(){
    SqDoubleStack *sp;
    SElemType a;
    int i;

    /* 初始化 */
    printf("======================init=====================\n");
    sp = InitStack();
    PrintStack(*sp);

    /* 入栈 */
    printf("======================push=====================\n");
    for (i = 1; i <= 8; i++){
        Push(sp, i, 1);
    }
    Push(sp, 9, 2);
    Push(sp, 10, 2);
    Push(sp, 11, 2);
    
    PrintStack(*sp);

    /* 出栈 */
    printf("======================pop=====================\n");
    Pop(sp, &a, 1);
    printf("pop: %d\n", a);
    Pop(sp, &a, 2);
    printf("pop: %d\n", a);
    PrintStack(*sp);
    Pop(sp, &a, 2);
    Pop(sp, &a, 2);
    PrintStack(*sp);

    /* 清空栈 */
    printf("=====================clear=====================\n");
    ClearStack(sp, 2);
    ClearStack(sp, 1);
    PrintStack(*sp);
}



void PrintStack(SqDoubleStack S){
    int i;
    printf("Print Stack1:\n");
    for (i = S.top1; i >= 0; i--){
        printf("%d\n", S.data[i]);
    }

    printf("Print Stack2:\n");
    for (i = S.top2; i < MAXSIZE; i++){
        printf("%d\n", S.data[i]);
    }
}

