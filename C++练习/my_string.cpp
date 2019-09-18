#include<iostream>
#include<string>
using namespace std;
//计算字符串最后一个单词的长度，单词以空格隔开
int main()
{
	string s;
	while (getline(cin, s))
	{
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
	}
	return 0;
}



//https://www.nowcoder.com/profile/844508568/codeBookDetail?submissionId=58424926


int main()
{
	string s;
	while (cin >> s)
	{
		bool flag = false;
		int count[256] = { 0 };
		for (int i = 0; i <s.size(); ++i)
		{
			count[s[i]] += 1;
		}
		for (int i = 0; i< s.size(); ++i)
		{
			if (count[s[i]] == 1)
			{
				cout << s[i] << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "-1" << endl;

	}

	return 0;
}