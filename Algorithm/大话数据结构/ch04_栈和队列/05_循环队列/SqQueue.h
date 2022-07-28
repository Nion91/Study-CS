#define MAXSIZE 10

/* 定义数据结构 */
typedef int QElemType;
typedef struct {
    QElemType data[MAXSIZE];
    int front;  /* 队列首元素指针 */
    int rear;   /* 队列尾元素指针 */
} SqQueue;


/* 定义操作 */
SqQueue * InitQueue(void);
void DestroyQueue(SqQueue *qp);
void ClearQueue(SqQueue *qp);
int QueueEmpty(SqQueue Q);
int QueueFull(SqQueue Q);
int GetHead(SqQueue Q, QElemType *ep);
int EnQueue(SqQueue *qp, QElemType e);
int DeQueue(SqQueue *qp, QElemType *ep);
int QueueLength(SqQueue Q);
void PrintQueue(SqQueue Q);

