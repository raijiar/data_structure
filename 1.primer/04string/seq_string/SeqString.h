#ifndef SEQSTRING_H
#define SEQSTRING_H

#include<stdio.h>
#include<string.h>
#include "../../01preface/Status.h"

#define MAXSTRLEN 255

typedef char SString[MAXSTRLEN + 1];

Status StrAssign(SString, unsigned char *);

Status StrCopy(SString, SString);

Status StrEmpty(SString);

int StrCompare(SString, SString);

int StrLength(SString);

void ClearString(SString);

Status Concat(SString, SString, SString);

Status SubString(SString *, SString, int, int);

int Index(SString, SString, int);

Status Replace(SString *, SString, SString);

Status StrInsert(SString, int, SString);

Status StrDelete(SString *, int pos, int len);

Status DestroyString(SString *);

#endif
