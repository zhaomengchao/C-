#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;

	//不能用cin输入，因为它会遇见空格停止输入
	while (getline(cin, str))//获取一个字符串
	{
		size_t pos = str.rfind(' ');
		cout << str.size() - pos - 1 << endl;
	}
	system("pause");
	return 0;
}