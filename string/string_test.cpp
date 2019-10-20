#include<iostream>
#include<string>
using namespace std;

//string类的常见构造接口

void test_string1()
{
	string s1;//构造空串
	string s2("hello world");//用C格式字符串构造string类对象s2
	string s3(10, 'c');//用10个字符'c'构造string类对象s3
	string s4(s2);     // 拷贝构造s4    
	string s5(s3, 5);  // 用s3中前5个字符构造string对象s5

	cout << s2 << endl;
}

//string类对象的容量操作size/capacity/

void test_string2()
{
	string s2("hello world");
	cout << s2.size() << endl;
	
	cout << s2.capacity() << endl;

	cout << s2.length() << endl;

	//将s2清空时，使用clear，只是size变为0，不改变底层空间

	s2.clear();
	cout << s2.size() << endl;

	cout << s2.capacity() << endl;

	//将s2中字符增加到20，空余的用a补充
	s2.resize(10, 'a');
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	
	//将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充

	s2.resize(15);
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;


	//将有效字符缩小到5个
	s2.resize(5);
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;//有效字符减少，容量不变

}


void test_string3()
{
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//reserve 不会改变size()的大小，而且空间只增不缩
}




int main()
{

	//test_string1();
	//test_string2();

	//test_string3();

	
	system("pause");
	return 0;
}