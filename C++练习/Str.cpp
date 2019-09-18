#include<iostream>
#include<string>

using namespace std;
//反转字符串
//class solution
//{
//public:
//	string reverseString(string s)
//	{
//		if (s.empty())
//		{
//			return s;
//		}
//		size_t left = 0;
//		size_t right = s.size() - 1;
//		while (left < right)
//		{
//			swap(s[left], s[right]);
//			++left;
//			--right;
//		}
//		return s;
//	}
//};

//找字符串中出现且出现一次的字符，并返回其下标
class solution
{
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		for (size_t i = 0; i < s.size(); ++i)//统计相应字符出现的次数
		{
			count[s[i]] += 1;
		}

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	solution a;
	//cout<<a.reverseString("123456")<<endl;
	cout << a.firstUniqChar("121234") << endl;
	system("pause");
	return 0;
}


