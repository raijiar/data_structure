#ifndef LINKQUEUE_C
#define LINKQUEUE_C

#include "LinkQueue.h"

//队列初始化
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr *)malloc(sizeof(QNode));
    if (!Q->front)
        return ERROR;
    Q->front->next = NULL;

    return OK;
}

//队列销毁
Status DestroyQueue(LinkQueue *Q)
{
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

//清空队列
Status ClearQueue(LinkQueue *Q)
{
    QNode *pre, *p;
    if (Q->front->next) {
        pre = Q->front->next;
        while (pre) {
            p = pre->next;
            free(pre);
            pre = p;
        }
        Q->rear = Q->front;
    }
    return OK;
}

//判断队列是否为空
Status QueueEmpty(LinkQueue Q);

//计算队列的元素数
int QueueLength(LinkQueue Q)
{
    int i = 0;
    QNode *p = Q.front;
    while (p != Q.rear) {
        i++;
        p = p->next;
    }

    return i;

}

//用e返回队头元素
Status GetHead(LinkQueue Q, ElemType *e)
{
    if (Q.front = Q.rear)
        return ERROR;
    QNode *p;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

Status EnQueue(LinkQueue *Q, ElemType e)
{
    QNode *p;
    p = (QueuePtr *)malloc(sizeof(QNode));
    if (!p)
        return ERROR;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
        return ERROR;
    QNode *p;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;

}

//Status QueueTraverse(LinkQueue Q, Status(visit)(ElemType));

#endif
