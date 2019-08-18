#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

Status InitList(List *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        return ERROR;
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestoryList(List *L)
{
    free(L->elem);

    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;

    return OK;
}

Status ClearList(List *L)
{
    L->length = 0;
    return OK;
}

int ListLength(List L)
{
    return L.length;
}

Status ListEmpty(List L)
{
    return L.length == 0 ? TRUE : FALSE;
}

Status GetElem(List L, int i, ElemType *e)
{
    if (i > L.length || i < 1)
        return ERROR;
    else
        *e = L.elem[i - 1];
    return OK;
}

Status ListInsert(List *L, int i, ElemType elem)
{
    ElemType *newbase, *q, *p;

    if (i < 1 || i > L->length + 1 || L == NULL) {
        return ERROR;
    }
    if(L->length >= L->listsize)
    {
        newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) {
            return ERROR;
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; --p) {
        *(p + 1) = *q;
    }
    *q = elem;
    L->length ++;
    return OK;
}

int LocateElem(List L, ElemType e, Status(Compare)(ElemType, ElemType))
{
    int i = 1;
    while (i <= L.length && !Compare(e, L.elem[i - 1]))
        ++i;
    if (i <= L.length)
        return i;
    else 
        return 0;

}

Status PriorElem(List L, ElemType cur_e, ElemType *pre_e)
{
    int i = 1;
    if (cur_e != L.elem[0]) {
        while (i < L.length && L.elem[i] != cur_e)
            ++i;
        if (i < L.length) {
            *pre_e = L.elem[i - 1];
            return OK;
        }
    } else {
        return ERROR;
    }
}

Status NextElem(List L, ElemType cur_e, ElemType *next_e)
{
    int i = 0;

    while (i < L.length && L.elem[i] != cur_e)
        ++i;
    if (i < L.length - 1) {
        *next_e = L.elem[i + 1];
        return OK;
    } else {
        return ERROR;
    }
}

Status ListDelete(List *L, int i, ElemType *e)
{
    int *p, *q;
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    *e = L->elem[i - 1];
    p = &(L->elem[i - 1]);
    q = L->elem + L->length - 1;

    for (++p; q <= p; ++p)
        *(p - 1) = *p;

    L->length--;
    return OK;
}

Status ListTraverse(List L, void(Visit)(List))
{

}

#endif
