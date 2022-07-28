#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"


main(){
    SqQueue *sp;
    QElemType a;
    int i;

    /* 初始化 */
    printf("======================init=====================\n");
    sp = InitQueue();
    PrintQueue(*sp);

    /* 入队 */
    printf("======================push=====================\n");
    for (i = 1; i <= 5; i++){
        EnQueue(sp, i);
    }
    
    PrintQueue(*sp);

    /* 出队 */
    printf("======================pop=====================\n");
    DeQueue(sp, &a);
    printf("pop: %d\n", a);
    DeQueue(sp, &a);
    printf("pop: %d\n", a);
    PrintQueue(*sp);
    printf("Len: %d\n", QueueLength(*sp));

    /* 清空队列 */
    printf("=====================clear=====================\n");
    ClearQueue(sp);
    DeQueue(sp, &a);
    PrintQueue(*sp);
}


