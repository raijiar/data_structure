#ifndef LINKLIST_C
#define LINKLIST_C

#include "LinkList.h"

//线性表初始化
Status InitList(LinkList *L)
{
    L = (LinkList *)malloc(sizeof(LinkList));
    if (!L)
        return ERROR;
    L->next = NULL;
    return OK;
}

//销毁线性表
void DestoryList(LinkList *L)
{
    Node *p = L;
    while (p)
    {
        p = L->next;
        free(L);
        L = p;
    }

}

//重置线性表为空
Status ClearList(LinkList *L)
{
    Node *pre, *p;
    if (!L)
        return ERROR;
    
    pre = L->next;
    while (pre) {
        p = pre->next;
        free (pre);
        pre = p;
    }
    L->next = NULL;

    return OK;
    

}

//是否是空表
Status ListEmpty(Node L)
{

}

//返回线性表中的元素个数
int ListLength(LinkList L)
{
    int i = 0;
    Node *p = L.next;
    while(p) {
        p = p->next;
        i++;
    }
    
    return i;

}

//向线性表插入元素
Status ListInsert(LinkList *L, int i, ElemType e)
{

    Node *p, *q, *s;

    p = L;

    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }    

    s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}

/*用e返回L中第i个元素
ElemType GetElem(Node L, int i, ElemType *e);

//返回满足compare关系的元素位序
int LocateElem(Node L, ElemType e, Status(Compare)(ElemType, ElemType));

//返回元素的前驱
Status PriorElem(Node L, ElemType cur_e, ElemType *pre_e);

//返回元素的后继
Status NextElem(Node L, ElemType cur_e, ElemType *next_e);

//删除线性表中的某个元素
Status ListDelete(Node *L, int i, ElemType *e);

//对线性表中的每个元素调用Visit函数
Status ListTraverse(Node L, void(Visit)(ElemType));

//线性表排序
void ListSort(Node *L);
*/
#endif
