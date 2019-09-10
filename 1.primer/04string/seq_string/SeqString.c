#ifndef SEQSTRING_C
#define SEQSTRING_C

#include<string.h>
#include "SeqString.h"

Status StrAssign(SString T, unsigned char *chars)
{
    int len;
    len = strlen(chars);
    if (len < MAXSTRLEN) {
        T[0] = len;
        for (int i = 1; i <= len; i++) 
            T[i] = chars[i - 1];
        return OK;
    } else 
        return ERROR;

}

Status StrCopy(SString T, SString S) 
{
    for (int i = 0; i <= S[0]; i++)
        T[i] = S[i];

    return OK;

}

int StrLength(SString S)
{
    return S[0];
}

void ClearString(SString S)
{
    S[0] = 0;
}

Status Concat(SString T, SString S1, SString S2)
{
    int i;
    for (i = 1; i <= S1[0]; i++) 
        T[i] = S1[i];

    if (S1[0] + S2[0] <= MAXSTRLEN) {
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        
        T[0] = S1[0] + S2[0];
        return OK;
    } else {
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        
        T[0] = MAXSTRLEN;
        return ERROR;   
    }
}

Status StrEmpty(SString S)
{
    return S[0] == 0 ? TRUE : FALSE;
}

int StrCompare(SString S, SString T)
{
    int i = 1;
    while (i <= S[0] && i <= T[0]) {
        if (S[i] == T[i])
            i++;
        else
            return S[i] - T[i];
    }

    return S[0] - T[0];
}

/*
Status SubString(SString *Sub, SString S, int pos, int len)
{
    if (S[0] == 0)
        return ERROR;
    if (!(pos >= 1 && pos <= S[0] && 0 <= len && len <= S[0] - pos + 1))
        return ERROR;
    int i = 0;
    for (i; i <= len; i++) 
        Sub[i] = S[pos - 1 + i];
    return OK;
}

int Index(SString S, SString T, int pos)
{
    int s, t, i = pos;

    SString Sub;

    if (pos >= 0) {
        s = S[0];
        t = T[0];

        if (s && t) {
            while (i <= s - t + 1) {
                SubString(&Sub, S, i, t);
                if (StrCompare(Sub, T) !=0)
                    ++i;
                else
                    return i;
            }
        }
    }
    return 0;
}

Status Replace(SString *S, SString T, SString V)
{
    
}

*/
Status StrInsert(SString S, int pos, SString T)
{
    if (S[0] + 1 <= pos || pos < 1 || S[0] + T[0] > MAXSTRLEN)
        return ERROR;
    for (int i = S[0]; i >= pos; i--) 
        S[i + T[0]] = S[i];

    for (int i = 1; i <= T[0]; i++)
        S[pos - 1 + i] = T[i];

    S[0] += T[0];
    return OK;

}

void StrPrint(SString S)
{
    for (int i = 1; i <= S[0]; i++) 
        printf("%c", S[i]);
    printf("\n");
}
//Status StrDelete(SString *S, int pos, int len);

//Status DestroyString(SString *S);

#endif
