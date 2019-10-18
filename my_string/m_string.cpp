//´«Í³Ð´·¨
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class my_string
{
private:
	char* _str;
public:
	my_string(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	//my_string s2(s1);
	my_string(const my_string& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	//s1 = s3;
	my_string operator=(const my_string& s)
	{
		if (this != &s)
		{
			delete[]_str;
			_str = (new char[strlen(s._str) + 1]);
			strcpy(_str, s._str);
		}
		return *this;
	}

	~my_string()
	{
		delete[]_str;
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