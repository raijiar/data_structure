#ifndef LINKLIST_C
#define LINKLIST_C

#include "LinkList.h"

//线性表初始化
Status InitList(LinkList *L)
{
    /*L = (LinkList *)malloc(sizeof(LinkList));
    if (!L)
        return ERROR;
    */
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

//对线性表中的每个元素调用Visit函数
Status ListTraverse(LinkList L, void(Visit)(ElemType))
{
    Node *p = L.next;
    while (p) {
        Visit(p->data);
        p = p->next;
    }
    return OK;

}

//用e返回L中第i个元素
Status GetElem(LinkList L, int i, ElemType *e)
{
    Node *p = L.next;
    int j = 1;

    while (p && j < i) {
        p = p->next;
        j++;
    }
    *e = p->data;
    return OK;
}

//返回元素的前驱
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    Node *p = L.next, *suc;
    
    while (p) {
        suc = p->next;
        if (suc->data == cur_e) {
            *pre_e = p->data;
            return OK;
        } else
            p = p->next;
    }

    return ERROR;

}

//返回元素的后继
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    Node *p, *suc;
    p = L.next;
    while (p && p->next) {
        suc = p->next;
        if (suc && p->data == cur_e) {
            *next_e = suc->data;
            return OK;
        } else 
            p = p->next;
    }

    return ERROR;
}

//删除线性表中的某个元素
Status ListDelete(LinkList *L, int i, ElemType *e)
{

    if (i < 1) 
        return ERROR;
    Node *p = L->next, *s;
    int j = 1;
    if (j == i) {
        *e = p->data;
        L->next = p->next;
        free(p);
        return OK;
    }
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p->next || j > i) 
        return ERROR;
    s = p->next;
    *e = s->data;
    p->next = s->next;
    free(s);

    return OK;
    
}


/*返回满足compare关系的元素位序
int LocateElem(Node L, ElemType e, Status(Compare)(ElemType, ElemType));

*/
#endif
