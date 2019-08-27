#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include "../../01preface/Status.h"

#define INIT_STACKSIZE  100
#define STACK_INCREMENT 10

typedef int ElemType;

typedef struct Stack {
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

//栈初始化
Status InitStack(SqStack *S);

//栈销毁
Status DestroyStack(SqStack *S);

//清空栈
Status ClearStack(SqStack *S);

//判断栈是否为空
Status StackEmpty(SqStack S);

//计算栈的元素数
int StackLength(SqStack S);

//用e返回栈顶元素
Status GetTop(SqStack S, ElemType *e);

Status Push(SqStack *S, ElemType e);

Status Pop(SqStack *S, ElemType *e);

Status StackTraverse(SqStack S, Status(visit)(ElemType));

#endif
