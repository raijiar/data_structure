#ifndef SLINKLIST_H
#define SLINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include "../../01preface/Status.h"

#define MAXSIZE 100

typedef int ElemType;

typedef struct  {
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];


//线性表初始化
Status InitList(LinkList *space);

//销毁线性表
void DestoryList(LinkList *L);

//重置线性表为空
Status ClearList(LinkList *L);

//是否是空表
Status ListEmpty(Node L);

//返回线性表中的元素个数
int ListLength(Node L);

//用e返回L中第i个元素
ElemType GetElem(Node L, int i, ElemType *e);

//返回满足compare关系的元素位序
int LocateElem(Node L, ElemType e, Status(Compare)(ElemType, ElemType));

//返回元素的前驱
Status PriorElem(Node L, ElemType cur_e, ElemType *pre_e);

//返回元素的后继
Status NextElem(Node L, ElemType cur_e, ElemType *next_e);

//向线性表插入元素
Status ListInsert(LinkList *L, int i, ElemType e);

//删除线性表中的某个元素
Status ListDelete(LinkList *L, int i, ElemType *e);

//对线性表中的每个元素调用Visit函数
Status ListTraverse(Node L, void(Visit)(ElemType));

//线性表排序
void ListSort(Node *L);
#endif
