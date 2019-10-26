#include<iostream>
#include<string>
using namespace std;


int main()
{
	string s;
	while (cin >> s)
	{
		bool flag = false;
		int count[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			count[s[i]] += 1;
		}
		for (int i = 0; i < s.size(); ++i)
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
