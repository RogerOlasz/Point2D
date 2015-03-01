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
				Alloc(res + 1);
				Clear();
				
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

	const P2String& operator= (const P2String& string) 
	{
		str = new char[string.len];
		strcpy_s(str, string.len, string.str);

		return(*this);
	}

	const P2String& operator= (const char* string)
	{
		if (string != NULL)
		{
			if (strlen(string) + 1 > len)
			{
				delete[] str;
				Alloc(strlen(string) + 1);
			}

			else

			strcpy_s(str, len, string);
		}
		else
		{
			Clear();
		}

		return (*this);

	}

	void Clear()
	{
		str[0] = '\0';
	}

private:

	void Alloc(unsigned int memory_space)
	{
		len = memory_space;
		str = new char[len];
	}

};

#endif //__String_H__