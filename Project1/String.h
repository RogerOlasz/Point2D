#ifndef __String_H__
#define __String_H__

#include <string.h>

class String
{
public:
	int len;
	char* str;

	String()
	{
		len = 1;
		str = new char[len];
		str[0] = '\0';
		
	}
	String(const char* strc)
	{
		len = strlen(strc) + 1;
		str = new char[len];
		strcpy_s(str, len, strc);
	}
	String(const String& str)
	{

	}

	String(const char* format, ...)
	{

	}

	~String()
	{
		delete[] str;
	}

	int len() const
	{
		return strlen(str);
	}
};

#endif //__String_H__