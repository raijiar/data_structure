#include<stdio.h>

#include "LinkQueue.c"

int main(void)
{
    LinkQueue Q;
    ElemType e;
    if (InitQueue(&Q)) {
        printf("初始化成功\n");
        EnQueue(&Q, 5);
        EnQueue(&Q, 99);
        EnQueue(&Q, 21);
        EnQueue(&Q, 34);
        printf("队列长度%d\n", QueueLength(Q));
        DeQueue(&Q, &e);
        printf("出队%d", e);
        DeQueue(&Q, &e);
        printf("出队%d", e);
        DeQueue(&Q, &e);
        printf("出队%d\n", e);
        printf("队列长度%d\n", QueueLength(Q));
        ClearQueue(&Q);
        printf("队列长度%d\n", QueueLength(Q));
        EnQueue(&Q, 7);
        DeQueue(&Q, &e);
        printf("出队%d\n", e);
        EnQueue(&Q, 19);
        DeQueue(&Q, &e);
        printf("出队%d\n", e);
        /*GetHead(Q, &e);
        printf("获取队头%d\n", e);
        GetHead(Q, &e);
        printf("获取队头%d\n", e);
        */
    } else {
        printf("初始化失败");
    }
    return 0;

}
