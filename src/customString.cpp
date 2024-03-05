#include <iostream>
#include "russification.h"



/// <summary>
/// CUSTOM string class. Russification.
/// <para> ---IMPORTANT---</para>
/// <para> It's NOT a std::string, but can be used as it.</para>
/// </summary>
class string
{
public:
	/*            ---Constructors---                            */
	// default string
	string(std::string str)
	{
		_str = new char[str.length() + 1];
		strcpy_s(_str, str.length() + 1, str.c_str());
	}
	// const char array
	string(const char* str)
	{
		_str = new char[strlen(str) + 1];
		strcpy_s(_str, strlen(str) + 1, str);
	}
	// destructor
	~string()
	{
		// dispose
		delete[] _str;
	}
	/*            ---Convert to base class---                   */
	operator char* ()
	{
		return _str;
	}

	operator std::string()
	{
		return std::string(_str);
	}

	/*            ---Functions---                               */

	// length of string
	size_t length()
	{
		// return length
		return strlen(_str);
	}

	// char array
	char* c_str()
	{
		// return str
		return _str;
	}

	char* ch_substr(int start, int count)
	{
		// check
		if (static_cast<unsigned long long>(start) + count > length())
		{
			throw std::out_of_range("Index out of range");
		}

		// new array
		char* sub = new char[count + 1];

		// copy
		for (int i = 0; i < count; i++)
		{
			sub[i] = _str[start + i];
		}

		// add termination
		sub[count] = '\0';

		return sub;
	}

	string str_substr(int start, int count)
	{
		char* sub = ch_substr(start, count);
		return string(sub);
	}

	
	/*            ---Operators---                              */
	void operator=(const char* str)
	{
		// copy
		strcpy_s(_str, strlen(str) + 1, str);
		return;
	}

	char& operator [] (int index)
	{
		// return char by index
		return _str[index];
	}

	string& operator += (const char* str)
	{
		// add str to _str
		strcat_s(_str, strlen(str) + 1, str);
		return *this;
	}

	string& operator += (const string& str)
	{
		// add str to _str
		strcat_s(_str, strlen(str._str) + 1, str._str);
		return *this;
	}

	string operator + (const char* str)
	{
		// add str to _str
		strcat_s(_str, strlen(str) + 1, str);
		return string(_str);

	}

	string operator + (const string& str)
	{
		// add str to _str
		strcat_s(_str, strlen(str._str) + 1, str._str);
		return string(_str);
	}

private:
	char* _str;
};

