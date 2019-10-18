//实现一个简单的string，现代写法

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class my_string
{
private:
	char* _str;
public:
	//构造函数
	my_string(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}


	//拷贝构造函数
	my_string(const my_string& s)
		:_str(nullptr)
	{
		my_string tmp(s._str);
		swap(tmp._str, _str);//现代写法
	}

	my_string operator = (const my_string& s)
	{
		if (this != &s)
		{
			my_string tmp(s);
			swap(_str, tmp._str);
		}
		return *this;
	}


	/*my_string operator = (my_string s)
	{
		swap(_str, s._str);
		return *this;
	}*/

	~my_string()
	{
		if (_str)
		{
			delete[]_str;
		}
	}
};

int main()
{
	my_string s1("hello");
	my_string s2(s1);

	my_string s3("world");

	s1 = s3;
	system("pause");
	return 0;
}