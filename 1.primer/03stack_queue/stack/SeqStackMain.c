#include<stdio.h>

#include "SeqStack.c"

int main(void)
{
    SqStack S;
    ElemType e, n;
    if (InitStack(&S)) {
        printf("初始化成功\n");
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
        ClearStack(&S);
        printf("请输入一个数字");
        scanf("%d", &n);
        while (n) {
            Push(&S, n % 2);
            n = n / 2;
        }
        while (!StackEmpty(S)) {
            Pop(&S, &e);
            printf("%d", e);
        }
    } else {
        printf("初始化失败");
    }
    return 0;
}
