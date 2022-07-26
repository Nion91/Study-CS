/* 定义数据结构 */
#define MAXSIZE 20
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;        /* 栈顶指针 */
} Stack;


/* 定义操作 */
Stack * InitStack();
void DestroyStack(Stack *sp);
void ClearStack(Stack *sp);
int StackEmpty(Stack S);
int StackFull(Stack S);
int GetTop(Stack S, ElemType *ep);
int Push(Stack *sp, ElemType e);
int Pop(Stack *sp, ElemType *ep);
int StackLength(Stack S);
void PrintStack(Stack S);