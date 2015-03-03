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
		alloc(1);
		str[0] = '\0';
		
	}
	/*P2String(const char* strc)
	{
		len = strlen(strc) + 1;
		str = new char[len];
		strcpy_s(str, len, strc);
	}*/
	P2String(const P2String& strc)
	{
		len = strc.len;
		str = new char[len];
		strcpy_s(str, len, strc.str);
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
				alloc(res + 1);
				strcpy_s(str, len, tmp);
				
			}
		if (len == 0)
		{
			alloc(1);
			clear();
		}

		}
	}

	~P2String()
	{
		delete[] str;
	}

	char* getString() const
	{
		return str;
	}

	unsigned int capacity() const
	{
		return len;
	}

	unsigned int getLength() const
	{
		return strlen(str);
	}

	bool operator== (const P2String& string) const
	{
		return strcmp(str, string.str) == 0;
	}

	bool operator== (const char* string) const
	{
		if (string != NULL)
			return strcmp(str, string) == 0;
		return false;
	}

	bool operator!= (const P2String& string) const
	{
		return strcmp(str, string.str) != 0;
	}

	bool operator!= (const char* string) const
	{
		if (string != NULL)
			return strcmp(str, string) != 0;
		return true;
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
				alloc(strlen(string) + 1);
			}

			else

			strcpy_s(str, len, string);
		}
		else
		{
			clear();
		}

		return (*this);

	}

	const P2String& P2String::operator+= (const P2String &string)
	{

		char *str_tmp = str;
		unsigned int len_tmp = len;
		len = string.len + len_tmp;

		char *tmp;
		tmp = new char[len];
		strcpy_s(tmp, len, str_tmp);
		strcat_s(tmp, len, string.str);

		delete[] str;
		str = new char[len];
		strcpy_s(str, len, tmp);
		delete[] tmp;

		return (*this);
	}

	const P2String& P2String::operator+= (const char *string)
	{
		if (string != NULL)
		{
			char *str_tmp = str;
			unsigned int len_tmp = len;
			len = strlen(string) + len_tmp + 1;

			char *tmp;
			tmp = new char[len];
			strcpy_s(tmp, len, str_tmp);
			strcat_s(tmp, len, string);

			delete[] str;
			str = new char[len];
			strcpy_s(str, len, tmp);
			delete[] tmp;
		}
		else
			clear();

		return (*this);
	}

	void clear()
	{
		str[0] = '\0';
	}

	void alloc(unsigned int memory_space)
	{
		len = memory_space;
		str = new char[len];
	}

};

#endif //__String_H__