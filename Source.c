#include <stdlib.h>
#include "String.h"

int main()
{
	String str1 = CreateString();
	String str2 = CreateString();

	AssignChar(&str1, "Hi");
	AssignString(&str2, str1);

	Append(&str1, str2);

	printf("%s\n", str1.m_content);
	printf("%s\n", str2.m_content);

	system("pause");
	return 0;
}