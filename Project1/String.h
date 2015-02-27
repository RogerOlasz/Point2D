#ifndef __String_H__
#define __String_H__

#include <string.h>

class P2String
{
public:
	int len;
	char* str;

	P2String()
	{
		len = 1;
		str = new char[len];
		str[0] = '\0';
		
	}
	P2String(const char* strc)
	{
		len = strlen(strc) + 1;
		str = new char[len];
		strcpy_s(str, len, strc);
	}
	P2String(const String& str)
	{

	}

	P2String(const char* format, ...)
	{

	}

	~P2String()
	{
		delete[] str;
	}

	int len() const
	{
		return strlen(str);
	}

	bool operator== (const P2String& string) const
	{
		return strcmp(string.str, str) == 0;
	}

	bool operator== (const P2String& string) const
	{
		return strcmp(string.str, str) != 0;
	}

};

#endif //__String_H__