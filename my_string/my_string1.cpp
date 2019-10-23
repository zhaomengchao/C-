#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

namespace zmc
{
	class String
	{
	public:
		typedef char* iterator;//普通迭代器
		typedef const char* const_iterator;//const迭代器

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

		const_iterator end()const
		{
			return _str + size;
		}

		String(const char *str = "")//构造函数
					:_str(new char[strlen(str) + 1])
		{
					strcpy(_str, str);   // 字符串拷贝函数
					size = strlen(str);
					capacity = size;   // _capacity不加1
		}

		~String()//析构函数
		{
			delete[]  _str;
			_str = nullptr;
			size = capacity = 0;
		}

		String(const String& s1)//拷贝构造函数
			:_str(new char[s1.size + 1])
			, size(s1.size)
			, capacity(s1.size)
		{
			strcpy(_str, s1._str);
		}

		String& operator=(const String& s)//重载赋值运算符
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s.size + 1];//开辟新的空间

				strcpy(_str, s._str);
				size = s.size;
				capacity = s.capacity;
			}
			return *this;
		}

		const char* c_str()//输出一个c形式的字符串
		{
			return _str;
		}

		char& operator[](size_t pos)//重载[]运算符
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

				delete[]_str;
				_str = tmp;

				capacity = n;

			}
		}


		void push_back(char ch)//尾插
		{
			/*if (size == capacity)
			{
				reserve(capacity * 2);
			}

			_str[size] = ch;
			++size;
			_str[size] = '\0';*/
			insert(size, ch);
		}

		void append(const char* s)//添加字符串
		{
			size_t len = strlen(s);
			if (size + len > capacity)
			{
				reserve(size + len);
			}

			strcpy(_str + size, s);
			size += len;
			//insert(size, s);
		}

		/*void append(size_t n, char c)
		{
			for (size_t i = 0; i < n; ++i)
				push_back(c);
		}*/

		const String& operator+=(char ch)//重载+=函数
		{
			push_back(ch);
			return *this;
		}

		const String& operator+=(const char* str)
		{
			append(str);
			return *this;
		}


		const String& operator+=(const String& s)
		{
			append(s._str);
			return *this;
		}
		void insert(size_t pos, char ch)//插入一个字符
		{
			assert(pos <= size);
			if (size <= capacity)
			{
				reserve(capacity * 2);
			}
			int end = size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}

			_str[pos] = ch;
			++size;//注意在调用一次insert后需要将size更新，不然\n会被覆盖掉了，从而出现越界情况
		}
		void insert(size_t pos, const char* str)//在指定位置插入一个字符串
		{
			//assert(pos <= size);
			size_t len = strlen(str);
			if (size + len > capacity)//判容
			{
				reserve(size + len);
			}
			size_t end = size;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			while (*str != '\0')
			{
				_str[pos++] = *str++;
			}
			size += len;
		}


		bool operator>(const String& s)const//重载>运算符，判断两个字符串的长度，以ascii码的值作为比较条件
		{
			const char* str1 = _str;
			const char* str2 = s._str;

			while (*str1 && *str2)
			{
				if (*str1 > *str2)
				{
					return true;
				}
				else if (*str1 < *str2)
				{
					return false;
				}
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator==(const String& s)const
		{
			char* str1 = _str;
			char* str2 = s._str;

			while (*str1 && *str2)
			{
				if (*str1 != *str2)
				{
					return false;
				}
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str1 || *str2)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool operator>=(const String& s)const
		{
			return *this > s || *this == s;
		}

		bool operator<(const String& s)const
		{
			return !(*this >= s);
		}

		bool operator<=(const String& s)const
		{
			return !(*this > s);
		}

		size_t find(const char* str)//查找函数
		{
			const char* pos = strstr(_str, str);
			if (pos == nullptr)
			{
				return string::npos;
			}
			else
			{
				return pos - _str;
			}
		}
		size_t find(char ch)//查找字符
		{
			size_t i = 0;
			for (i = 0; i < size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return -1;//npos == -1

		}
		private:
			char *_str;
			size_t size;
			size_t capacity;
	};
	string operator +(const string& s1, const string& s2)//重载string的+
	{
		string ret = s1; 
		ret += s2;
		return ret;
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}
	istream& operator>>(iostream& in,string& s)
	{
		in >> s.size;
		return in;

	}


}






void test1()
{
	zmc::String s1("hello");
	cout << s1._size() << endl;
	cout << s1.c_str() << endl;

	for (size_t i = 0; i < s1._size(); i++)
	{
		s1[i] = 'a';
		cout << s1[i] << "";
	}
	cout << endl;

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

}
void test2()
{
	zmc:: String s("hello");
	s += "world";

	cout << s.c_str() << endl;
	/*s.insert(5, ' ');
	cout << s.c_str() << "";*/
}

void test3()
{
	zmc::String s("hello world!");
	zmc::String s3("hello");
	cout << (s > s3) << endl;
	
	
	//cout<<s.find('h')<<endl;

	//cout << s.find("world") << endl;

}

int main()
{
	test2();
	system("pause");
	return 0;
}



