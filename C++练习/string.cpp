#include<iostream>
#include<string>
using namespace std;

//void TestString2()
//{
//	string s;    
//	// 测试reserve是否会改变string中有效元素个数    
//	s.reserve(100);//仅仅改变空间   ，已经知道需要多少空间依次给够，避免扩容带来的浪费 
//	cout << s.size() << endl;    
//	cout << s.capacity() << endl;
//
//	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小    
//	s.resize(50);    
//	cout << s.size() << endl;    
//	cout << s.capacity() << endl; 
//}
//
//int main()
//{
//	string s1;
//	string s2("hello");
//	string s3 = s2;
//	cout << s3 << endl;
//
//	cout << s1.size() << endl;//常用返回字符串的有效长度
//	cout << s2.length() << endl;
//
//
//	cout << s1.capacity() << endl;//十五个字符，后面加\0;
//	cout << s2.capacity() << endl;//15
//
//	s2.clear();//只清空内容，不清空间。
//	cout << s2.capacity() << endl;//15
//
//
//
//	TestString2();
//
//	string s("123");
//	int value = 0;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		value *= 10;
//		value += s[i] - '0';
//	}
//	cout << value << endl;
//
//
//	system("pause");
//	return 0;
//}

