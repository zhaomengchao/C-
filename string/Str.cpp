#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;

	const_iterator begin()const
	{
		return _str;
	}
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + size;
	}


	String(const char* str = "")
		:_str(new char[strlen(str)] + 1)
	{
		strcpy(_str, str);
		size = strlen(str);
		capacity = size;
	}

	//~String()
	//{
	//	delete[]  _str;
	//	_str = nullptr;
	//	size = capacity = 0;
	//}

	String(const String& s1)
		:_str(new char[s1.size + 1])
		, size(s1.size)
		, capacity(s1.size)
	{
		strcpy(_str, s1._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s.size + 1];

			strcpy(_str, s._str);
			size = s.size;
			capacity = s.capacity;
		}
		return *this;
	}

	const char* c_str()
	{
		return _str;
	}
	
	char& operator[](size_t pos)
	{
		assert(pos < size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const//函数重载
	{
		assert(pos < size);
		return _str[pos];
	}

	size_t _size()
	{
		return size;
	}

	size_t _capacity()
	{
		return capacity;
	}

	void reserve(size_t n)//扩容，不仅扩容，直接初始化
	{
		if (n > capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);

			//delete[]_str;
			_str = tmp;

			capacity = n;

		}
	}


	void push_back(char ch)//尾插
	{
		if (size == capacity)
		{
			reserve(capacity * 2);
		}
		
		_str[size] = ch;
		++size;
		_str[size] = '\0';
	}

	/*void append(const char* s)
	{
		size_t len = strlen(s);
		if (size + len > capacity)
		{
			reserve(size + len);
		}

		strcpy(_str + size, _str);
		size += len;
	}*/

	void Append(size_t n, char c)
	{
		for (size_t i = 0; i < n; ++i)
			push_back(c);
	}
	



private:
	char *_str;
	size_t size;
	size_t capacity;
};



void test1()
{
	String s1("hello");
	//cout << s1.c_str() << endl;

	//for (size_t i = 0; i < s1._size(); i++)
	//{
	//	s1[i] = 'a';
	//	cout << s1[i] << "";
	//}
	//s1.push_back('w');
	s1.push_back('w');
	//s1.append("www");
	s1.Append(1, 'i');
}



int main()
{
	test1();
	system("pause");
	return 0;
}