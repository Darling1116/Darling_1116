#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

using namespace std;
//传统的，用开空间的方法
namespace GXR
{/*
	class String
	{
	public:*/
	//	//无参数构造
	//	String()
	//		:_str(new char[1])
	//	{
	//		_str[0] = '\0';
	//	}
	//	//参数构造

	//	String(char* s)
	//		:_str(new char[strlen(s) + 1])
	//	{
	//		strcpy(_str, s);
	//	}

	//	//拷贝构造
	//	String(const String& s)
	//		:_str(new char[strlen(s._str) + 1])
	//	{
	//		strcpy(_str, s._str);
	//	}



	//	//复制
	//	String& operator=(const String& s)
	//	{
	//		if (this != &s)
	//		{
	//			delete []_str;
	//			_str = new char[strlen(s._str) + 1];
	//			strcpy(_str, s._str);
	//		}
	//		return *this;
	//	}


	//现代的
	//String(char* s = "")
	//{
	//	_str = new char[(strlen(s) + 1)];
	//	strcpy(_str, s);
	//}

	//String(const String& s)
	//{
	//	String tmp(s._str);
	//	swap(_str, tmp._str);
	//}

	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String tmp(s._str);
	//		swap(_str, tmp._str);
	//	}
	//	return *this;
	//}

	////	//析构函数
	//	~String()
	//	{
	//		if (_str)
	//			delete[]_str;
	//	}

	//	//打印
	//	char* c_str()
	//	{
	//		return _str;
	//	}


	//	char& operator[](size_t pos)
	//	{
	//		return _str[pos];
	//	}

	//	size_t Size()
	//	{
	//		return strlen(_str);
	//	}

	//private:
	//	char* _str;
	//};

	//void stringTest1()
	//{

	//	String s1("hello");
	//	String s2("world");

	//	String s3 = s2;
	//	for (size_t i = 0; i < s1.Size(); i++)
	//	{
	//		cout << s1[i] << ' ';
	//	}
	//	cout << endl;

	//	cout << s1.c_str() << endl;
	//	cout << s2.c_str() << endl;
	//	cout << s3.c_str() << endl;
	//}

class String
{
public:
	//构造：参数为数组
	String(char* s = "")
	{
		_size = strlen(s);
		_capacity = _size;
		_str = new char[(_capacity)+1];
		strcpy(_str, s);
	}

	//拷贝构造
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}

	//复制
	String& operator=(const String s)
	{
			//Swap(s);
			//return *this;
		if (this != &s)
		{
			String tmp(s);
			Swap(tmp);
		}
		return *this;
		
	}

	void Swap(String& s)
	{
		swap(_str ,s._str);
		swap(_size ,s._size);
		swap(_capacity ,s._capacity);
	}

	~String()
	{
		if (_str)
			delete []_str;
	}

	char* c_str()
	{
		return _str;
	}

	char& operator[](size_t pos)
	{
		return _str[pos];
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}


	bool operator>(const String& s)
	{
		const char* tmp1 = _str;
		const char* tmp2 = s._str;
		while (*tmp1 != '\0' && *tmp2 != '\0' && *tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp1 > *tmp2)
		{
			return true;
		}
		else
			return false;

	}

	bool operator==(const String& s)
	{
		const char* tmp1 = _str;
		const char* tmp2 = s._str;
		while (*tmp1 == *tmp2)
		{
			if (*tmp1 == '\0' && *tmp2 == '\0')
			{
				return true;
			}
			*tmp1++;
			*tmp2++;
		}
		return false;
	}

	//bool operator<(const String& s)
	//{
	//	return !(operator>(s) || operator==(s));
	//}

	bool operator<(const String& s)
	{
		return !(*this>s || *this == s);
	}

	bool operator<=(const String& s)
	{
		return !(operator>(s));
	}

	bool operator>=(const String& s)
	{
		return !(operator<(s));
	}

	bool operator!=(const String& s)
	{
		return !(operator==(s));
	}

	void Expand(size_t n)//增容：增加为n
	{
		char* tmp = new char[n];
		memcpy(tmp, _str, _size + 1);//包括\0
		delete[]_str;
		_str = tmp;
		_capacity = n;
	}

	void Insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size >= _capacity-1)
		{
			Expand(2 * _capacity + 1);//一次增2倍
		}

		for (size_t i = _size; i >= pos; i--)//从最后一个数开始向后依次挪动，知道pos后的一个位置
		{
			_str[i+1] = _str[i];//包括\0，也要挪动
		}
		_str[pos] = ch;
		++_size;
	}


	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		const char* tmp = str;
		size_t tsize = strlen(tmp);

		if (_capacity <= _size + tsize)//
		{
			Expand(_capacity + tsize+1);//也要给\0开一个空间
		}

		for (size_t i =_size; i >= pos; i--)
		{
			_str[i+tsize] = _str[i];//
		}

		int j = 0;

		while (*(str + j) != '\0')
		{
			_str[pos + j] = str[j];
			++j;
		}
		
		_size += tsize;
	}

	void PushBack(char ch)
	{
		Insert(_size, ch);

	}
	
	void PushBack(const char* str)
	{
		Insert(_size, str);
	}

	void Append(const char* str)
	{
		Insert(_size, str);

	}

	size_t Find(char ch, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
                   return i;
			}
		}
		return _size;
	}


	size_t Find(const char* str, size_t pos = 0)
	{
		size_t p_str = 0;//从原string的第一个字符开始寻找
		while (_str[p_str] != '\0')
		{
			if (_str[p_str] == *str)
			{
				size_t pfind = p_str;
				size_t pstr = 0;
				while (1)
				{
					if (str[pstr] == '\0')
						return pstr;

					if (str[pstr] != _str[pfind])
					{
						break;
					}
					pfind++;
					pstr++;
				}

				
			}
			p_str++;
		}

	return -1;
	}
	

	String& operator+=(char ch)
	{
		PushBack(ch);
		return *this;
	
	}

	String& operator+=(const char* str)
	{
		PushBack(str);
		return *this;
	}
	
	//
	//		void Erase(size_t pos, size_t len);

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void StringTest2()
 {
	String s1("hell");
	String s2("hello");
	s1 += 'q';
	s1 += "QQQQQQ";
//	s1.PushBack("mmmmmmm");
	//s1.Insert(4, 'a');
//	s1.Insert(2, "abcdefg");

//	size_t ret = s1.Find("he");
	//cout << ret << endl;

//	size_t ret= s1.Find('p');
	//cout << ret << endl;
	//s1.PushBack('a');
	//s1.Append("abcdefg");
//	String s3 = s2;
	cout << s1.c_str() << endl;
///	cout << s2.c_str() << endl;
//	cout << s3.c_str() << endl;
	//cout << (s1 < s2) << endl;
	//cout << (s1 != s2) << endl;

	

 }

}



