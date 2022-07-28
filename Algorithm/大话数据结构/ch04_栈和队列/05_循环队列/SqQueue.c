#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"


/* SqQueue: 初始化队列 */
SqQueue * InitQueue(void){
    SqQueue *qp;
    qp = (SqQueue *)malloc(sizeof(SqQueue));
    qp->front = qp->rear = 0;
    return qp;
}

/* QueueLength: 返回队列长度 */
int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* EnQueue: 将元素加入队列尾部 */
int EnQueue(SqQueue *qp, QElemType e){
    if (QueueFull(*qp)){
        printf("Error: queue is full\n");
        return 0;
    }

    qp->data[qp->rear] = e;
    qp->rear = (qp->rear + 1) % MAXSIZE;
    return 1;
}

/* DeQueue: 从队列头部弹出元素 */
int DeQueue(SqQueue *qp, QElemType *ep){
    if (QueueEmpty(*qp)){
        printf("Error: queue is empty\n");
        return 0;
    }

    *ep = qp->data[qp->front];
    qp->front = (qp->front + 1) % MAXSIZE;
    return 1;
}

/* DestroyQueue: 销毁队列 */
void DestroyQueue(SqQueue *qp){
    if (qp){
        free(qp);
    }
}

/* ClearQueue: 清空队列 */
void ClearQueue(SqQueue *qp){
    qp->front = qp->rear = 0;
}

/* QueueEmtpy: 返回队列是否为空 */
int QueueEmpty(SqQueue Q){
    return Q.front == Q.rear;
}


/* QueueFull: 返回队列是否已满 */
int QueueFull(SqQueue Q){
    return (Q.rear + 1) % MAXSIZE == Q.front;
}

/* GetHead: 返回队列头部元素 */
int GetHead(SqQueue Q, QElemType *ep){
    if (QueueEmpty(Q)){
        printf("Error: queue is empty\n");
        return 0;
    }

    *ep = Q.data[Q.front];
    return 1;
}

/* PrintQueue: 打印队列 */
void PrintQueue(SqQueue Q){
    int i;
    for (i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE){
        printf("%d\n", Q.data[i]);
    }
}
