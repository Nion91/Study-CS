#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"



/* EnQueue: 将元素加入队列尾部 */
int EnQueue(LinkQueue *qp, QElemType e){
    QueuePtr kp;

    kp = (QueuePtr)malloc(sizeof(QNode));
    if (kp == NULL)
        return 0;
    
    kp->data = e;
    kp->next = NULL;
    qp->rear->next = kp;
    qp->rear = kp;
    return 1;
}


/* DeQueue: 从队列头部弹出元素 */
int DeQueue(LinkQueue *qp, QElemType *ep){
    QueuePtr kp;

    if (QueueEmpty(*qp)){
        printf("Error: Queue is empty\n");
        return 0;
    }

    kp = qp->front->next;
    qp->front->next = kp->next;
    if (qp->rear == kp)
        qp->rear = qp->front;
    *ep = kp->data;
    free(kp);
    return 1;
}


/* InitQueue: 初始化队列 */
LinkQueue * InitQueue(void){
    LinkQueue *qp;
    QueuePtr np;

    np = (QueuePtr)malloc(sizeof(QNode));           /* 初始化头结点 */
    if (np == NULL)
        return NULL;
    np->next = NULL;

    qp = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (qp == NULL)
        return NULL;
    qp->front = qp->rear = np;
    return qp;
}


/* DestroyQueue: 销毁队列 */
void DestroyQueue(LinkQueue *qp){
    QueuePtr np, kp;

    np = qp->front;
    while (np){
        kp = np;
        np = np->next;
        free(kp);
    }
    free(qp);
}


/* ClearQueue: 清空队列 */
void ClearQueue(LinkQueue *qp){
    QueuePtr np, kp;

    np = qp->front->next;
    while (np){
        kp = np;
        np = np->next;
        free(kp);
    }
    qp->rear  = qp->front;
    qp->front->next = NULL;
}


/* QueueEmtpy: 返回队列是否为空 */
int QueueEmpty(LinkQueue Q){
    return Q.front == Q.rear;
}


/* GetHead: 返回队列头部元素 */
int GetHead(LinkQueue Q, QElemType *ep){
    if (QueueEmpty(Q)){
        printf("Error: Queue is empty\n");
        return 0;
    }

    *ep = Q.front->next->data;
    return 1;
}


/* QueueLength: 返回队列长度 */
int QueueLength(LinkQueue Q){
    int n;
    QueuePtr kp;

    n = 0;
    kp = Q.front;
    while (kp->next){
        n++;
        kp = kp->next;
    }
    return n;
}

/* PrintQueue: 打印队列 */
void PrintQueue(LinkQueue Q){
    QueuePtr np;

    np = Q.front;
    while (np->next){
        np = np->next;
        printf("%d\n", np->data);
    }
}








