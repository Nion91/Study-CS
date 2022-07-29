#define MAXSIZE 10

/* 定义数据结构 */
typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;  /* 队列首元素指针 */
    QueuePtr rear;   /* 队列尾元素指针 */
} LinkQueue;


/* 定义操作 */
LinkQueue * InitQueue(void);
void DestroyQueue(LinkQueue *qp);
void ClearQueue(LinkQueue *qp);
int QueueEmpty(LinkQueue Q);
int GetHead(LinkQueue Q, QElemType *ep);
int EnQueue(LinkQueue *qp, QElemType e);
int DeQueue(LinkQueue *qp, QElemType *ep);
int QueueLength(LinkQueue Q);
void PrintQueue(LinkQueue Q);
void PrintQueue(LinkQueue Q);



