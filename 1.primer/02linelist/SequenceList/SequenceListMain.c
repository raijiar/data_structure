#include<stdio.h>

#include "SequenceList.c"

int main()
{
    List L;
    if (InitList(&L)) 
        printf("初始化成功");
    else 
        printf("初始化失败");
}
