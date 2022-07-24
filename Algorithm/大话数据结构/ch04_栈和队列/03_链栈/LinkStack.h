/* 定义数据结构 */
typedef int SElemType;

typedef struct StackNode{
    SElemType data;
    struct StackNode * next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;


/* 定义操作 */
int Push(LinkStack *lp, SElemType e);
int Pop(LinkStack *lp, SElemType *ep);
LinkStack * InitStack();
void DestroyStack(LinkStack *lp);
void ClearStack(LinkStack *lp);
int StackEmpty(LinkStack S);
int GetTop(LinkStack S, SElemType *ep);
int StackLength(LinkStack S);




