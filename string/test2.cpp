#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;

	//������cin���룬��Ϊ���������ո�ֹͣ����
	while (getline(cin, str))//��ȡһ���ַ���
	{
		size_t pos = str.rfind(' ');
		cout << str.size() - pos - 1 << endl;
	}
	system("pause");
	return 0;
}