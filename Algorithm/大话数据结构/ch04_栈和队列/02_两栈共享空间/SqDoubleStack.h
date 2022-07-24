#define MAXSIZE 10

/* 定义数据结构 */
typedef int SElemType;
typedef struct {
    SElemType data[MAXSIZE];
    int top1;   /* 栈1的栈顶指针 */
    int top2;   /* 栈2的栈顶指针 */
} SqDoubleStack;


/* 定义操作 */
SqDoubleStack * InitStack();
void DestroyStack(SqDoubleStack *sp);
void ClearStack(SqDoubleStack *sp, int stacknum);
int StackEmpty(SqDoubleStack S, int stacknum);
int StackFull(SqDoubleStack S);
int GetTop(SqDoubleStack S, SElemType *ep, int stacknum);
int Push(SqDoubleStack *sp, SElemType e, int stacknum);
int Pop(SqDoubleStack *sp, SElemType *ep, int stacknum);
int StackLength(SqDoubleStack S, int stacknum);

