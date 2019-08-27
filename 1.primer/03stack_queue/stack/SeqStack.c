#ifndef SEQSTACK_C
#define SEQSTACK_C

#include "SeqStack.h"

Status InitStack(SqStack *S)
{
    S->base = (ElemType *)malloc(INIT_STACKSIZE * sizeof(ElemType));
    if (!S->base) 
        return ERROR;
    S->top = S->base;
    S->stacksize = INIT_STACKSIZE;
    return OK;
}

Status DestroyStack(SqStack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;

    S->stacksize = 0;

    return 0;
    
}

//清空栈
Status ClearStack(SqStack *S)
{
    S->top = S->base;

    return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack S)
{
    return S.top == S.base ? TRUE : FALSE;
}

//计算栈的元素数
int StackLength(SqStack S)
{
    return S.top - S.base;
}

//用e返回栈顶元素
Status GetTop(SqStack S, ElemType *e)
{
    if (S.top == S.base)
        return ERROR;
    *e = *(S.top - 1);
    return OK;
}

Status Push(SqStack *S, ElemType e)
{
    if (S->top - S->base > S->stacksize) {
        S->base = (ElemType *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(ElemType));
        if (!S->base)
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S, ElemType *e)
{
    if (S->top == S->base)
        return ERROR;
    *e = * -- S->top;
    return OK;
}

//StackTraverse(SqStack S, Status(visit)(ElemType *e);

#endif
