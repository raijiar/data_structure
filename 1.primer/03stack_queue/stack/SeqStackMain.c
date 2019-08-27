#include<stdio.h>

#include "SeqStack.c"

int main(void)
{
    SqStack S;
    ElemType e;
    if (InitStack(&S)) {
        printf("初始化成功");
        Push(&S, 5);
        Push(&S, 99);
        Push(&S, 3);
        Push(&S, 12);
        Push(&S, 43);
        Push(&S, 901);
        Pop(&S, &e);
        printf("出栈成功%d\n", e);
        Pop(&S, &e);
        printf("出栈成功%d\n", e);
        Pop(&S, &e);
        printf("出栈成功%d\n", e);
    } else {
        printf("初始化失败");
    }
    return 0;
}
