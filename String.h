#pragma once
#include <stdio.h>

typedef enum { FALSE, TRUE } BOOL;

typedef struct
{
	size_t m_length;
	char* m_content;	
} String;

String CreateString(void);

size_t GetLength(String*);
void AssignString(String*, String);
void AssignChar(String*, char*);
char CharAt(String*, size_t);
void Append(String*, String);
int Compare(String*, String);
BOOL IsEmpty(String*);
void Clear(String*);


