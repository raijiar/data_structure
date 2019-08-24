#include<stdio.h>

#include "LinkList.c"

void Visit(ElemType);

int main()
{
    LinkList L;
    ElemType pre_e, next_e, e;
    if (InitList(&L)) {
        printf("初始化成功\n");
        printf("当前线性表长度%d\n", ListLength(L));
        ListInsert(&L, 1, 23);
        /*ListInsert(&L, 2, 33);
        ListInsert(&L, 3, 89);
        ListInsert(&L, 4, 12);
        ListInsert(&L, 1, 14);
        ListInsert(&L, 1, 90);
        ListInsert(&L, 2, 788);
        ListInsert(&L, 2, 56);
        */
        printf("当前线性表长度%d\n", ListLength(L));
        /*GetElem(L, 3, &e);
        printf("线性表的第3个元素为:%d\n", e);
        printf("删除的第3个元素为:%d\n", e);
        PriorElem(L, 12, &pre_e);
        NextElem(L, 23, &next_e);
        printf("%d元素的前驱为:%d\n", 12, pre_e);
        printf("%d元素的后继为:%d\n", 23, next_e);
        ListSort(&L);
        ListTraverse(L, Visit);
        */
    } else 
        printf("初始化失败");
}

void Visit(ElemType i)
{
    printf("元素值:%d\n", i);
}
