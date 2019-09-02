#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include "../../01preface/Status.h"

typedef int ElemType;

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, QueuePtr;

typedef struct {
    QueuePtr *front;
    QueuePtr *rear;
} LinkQueue;

//队列初始化
Status InitQueue(LinkQueue *Q);

//队列销毁
Status DestroyQueue(LinkQueue *Q);

//清空队列
Status ClearQueue(LinkQueue *Q);

//判断队列是否为空
Status QueueEmpty(LinkQueue Q);

//计算队列的元素数
int QueueLength(LinkQueue Q);

//用e返回队头元素
Status GetHead(LinkQueue Q, ElemType *e);

Status EnQueue(LinkQueue *Q, ElemType e);

Status DeQueue(LinkQueue *Q, ElemType *e);

//Status QueueTraverse(LinkQueue Q, Status(visit)(ElemType));

#endif
