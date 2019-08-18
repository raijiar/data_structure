#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include<stdio.h>
#include<stdlib.h>
#include "../../01preface/Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct sq_list {
    ElemType *elem;
    int length;
    int listsize;
} List;

//线性表初始化
Status InitList(List *L);

//销毁线性表
Status DestoryList(List *L);

//重置线性表为空
Status ClearList(List *L);

//是否是空表
Status ListEmpty(List L);

//返回线性表中的元素个数
int ListLength(List L);

//用e返回L中第i个元素
ElemType GetElem(List L, int i, ElemType *e);

//返回满足compare关系的元素位序
int LocateElem(List L, ElemType e, Status(Compare)(ElemType, ElemType));

//返回元素的前驱
Status PriorElem(List L, ElemType cur_e, ElemType *pre_e);

//返回元素的后继
Status NextElem(List L, ElemType cur_e, ElemType *next_e);

//向线性表插入元素
Status ListInsert(List *L, int i, ElemType e);

//删除线性表中的某个元素
Status ListDelete(List *L, int i, ElemType *e);

//对线性表中的每个元素调用Visit函数
Status ListTraverse(List L, void(Visit)(List));

#endif
