#include "String.h"
#include <string.h>

String CreateString(void)
{
	String retStr;
	retStr.m_length = 0;
	retStr.m_content = NULL;
	return retStr;
}

size_t GetLength(String* this)
{
	return this->m_length;
}

void AssignString(String* this, String otherString)
{
	Clear(this);

	size_t length = otherString.m_length;
	this->m_length = length;
	this->m_content = malloc(length * sizeof(char) + 1);
	strcpy_s(this->m_content, length + 1, otherString.m_content);
}

void AssignChar(String* this, char* source)
{
	size_t length = strlen(source) + 1;
	Clear(this);

	this->m_length = length - 1;
	this->m_content = malloc(length + 1);
	strcpy_s(this->m_content, length, source);
}

char CharAt(String* this, size_t index)
{
	if (index > this->m_length || index < 0)
	{
		return NULL;
	}

	return this->m_content[ index ];
}

void Append(String* this, String otherString)
{
	size_t newLength = this->m_length + GetLength(&otherString) + 1;
	char* tmp = malloc(newLength + 1);
	strcpy_s(tmp, this->m_length + 1, this->m_content);
	strcpy_s(tmp + sizeof(char)* this->m_length, newLength, otherString.m_content);

	free(this->m_content);
	this->m_content = tmp;
	this->m_length = newLength - 1;
}

int Compare(String* this, String otherString)
{
	return strcmp(this->m_content, otherString.m_content);
}

BOOL IsEmpty(String* this)
{
	return this->m_length <= 0 ? TRUE : FALSE;
}

void Clear(String* this)
{
	this->m_length = 0;

	if (NULL != this->m_content)
	{
		free(this->m_content);
	}
}