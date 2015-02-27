#ifndef __String_H__
#define __String_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define TMP_STRING_SIZE 4096

class P2String
{
public:
	unsigned int len;
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
	P2String(const P2String& str)
	{

	}

	P2String(const char* format, ...)
	{
		len = 0;

		if (format != NULL)
		{
			static char tmp[TMP_STRING_SIZE];
			static va_list ap;

			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);

			if (res > 0)
			{
				
			}

		}
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

	bool operator== (const char* string) const
	{
		if (string != NULL)
			return strcmp(string, str) == 0;
		return false;
	}

	bool operator!= (const P2String& string) const
	{
		return strcmp(string.str, str) != 0;
	}

	bool operator!= (const char* string) const
	{
		if (string != NULL)
			return strcmp(string, str) != 0;
		return false;
	}

	P2String& P2String::operator= (const P2String& string) 
	{
		str = new char[string.len];
		strcpy_s(str, string.len, string.str);

		return(*this);
	}

	P2String& P2String::operator= (const char* string)
	{
		Alloc(string.len);

		if (string != NULL)
		 strcpy_s(str, string.len, string.str);
		return (*this);
	}

private:

	void Alloc(unsigned int memory_space)
	{
		len = memory_space;
		str = new char[len];
	}

};

#endif //__String_H__