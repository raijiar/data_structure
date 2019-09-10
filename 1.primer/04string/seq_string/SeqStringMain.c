#include<stdio.h>
#include<string.h>

#include "SeqString.c"

int main(void)
{
    SString S, T, E, Tem;
    unsigned char chars[] = "Hello world!";
    unsigned char ele[] = "Hello";
    //printf("字符串长度%zd\n", strlen(chars));
    //printf("%s\n", chars);

    if (StrAssign(T, chars)) {
        StrPrint(T);
        StrCopy(S, T);
        StrPrint(S);
        printf("字符串长度%d\n", StrLength(S));
        ClearString(S);
        printf("字符串长度%d\n", StrLength(S));
        StrAssign(S, ele);
        if (!Concat(Tem, T, S)) 
            printf("拼接失败\n");
        printf("字符串长度%d\n", StrLength(Tem));
        StrPrint(Tem);
        StrInsert(T, 6, S);
        printf("字符串长度%d\n", StrLength(T));
        printf("字符串T是否为空：%d\n", StrEmpty(T)); 
        printf("字符串T,S对比：%d\n", StrCompare(T, S)); 
        StrPrint(T);
        
    } else
        printf("赋值错误");
    
    return 0;
}
