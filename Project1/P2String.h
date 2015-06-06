#ifndef __P2String_H__
#define __P2String_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define TMP_STRING_SIZE 4096

class P2String
{
private:
		unsigned int len;
		char* str;

		void Alloc(unsigned int memory_space)
		{
			len = memory_space;
			str = new char[len];
		}

public:
	

	P2String()
	{
		Alloc(1);
		clear();
		
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
				Alloc(res + 1);
				strcpy_s(str, len, tmp);
				
			}
		if (len == 0)
		{
			Alloc(1);
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

	void Trim()
	{
		unsigned int size = getLength();

		char* end = str + size;
		while (*--end == ' ') *end = '\0';

		char* start = str;
		while (*++start == ' ');

		size = strlen(start);

		for (unsigned int i = 0; i < size + 1; i++)
		{
			str[i] = start[i];
		}
	}

	bool SwapChar(char* c1, char* c2)
	{
		int start = 0;
		int end = -1;
		int dif = strlen(c2) - strlen(c1);
		int oldLength = getLength();

		//Find the word
		for (unsigned int i = 0; i < getLength(); i++)
		{
			if (str[i] == c1[0])
			{
				start = i;
				if (strlen(c1) == 1)
				{
					end = i;
				}
					
				else
				{
					for (unsigned int j = 0; str[i + 1] == c1[j], j < strlen(c1); j++, i++)
					{
						if (j == strlen(c1) - 1)
						{
							end = i + 1;
						}		
					}
				}					
			}
		}	

		//Doesn't exist
		if (end == -1)
		{
			return false;
		}
			
		//Resize
		if (dif > 0)
		{
			char* tmp = str;

			Alloc(len + dif);
			strcpy_s(str, getLength(), tmp);

			for (int i = oldLength; i > end; i--)
			{
				str[i + dif] = str[i];
			}
				
		}
		else
		{
			for (int i = end + 1; i < oldLength; i++)
			{
				str[i + dif] = str[i];
			}
			
			str[oldLength + dif] = '\0';
			len += dif;
		}
		//Rewrite
		for (int i = 0; i < strlen(c2); i++)
		{
			str[i + start] = c2[i];
		}
			
		return true;
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
				Alloc(strlen(string) + 1);
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
		str = tmp;

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
			str = tmp;
		}
		else
		{
			clear();
		}
			

		return (*this);
	}

	void clear()
	{
		str[0] = '\0';
	}

};

#endif //__P2String_H__
