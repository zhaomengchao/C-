#include<iostream>
#include<stack>
#include<vector>


using namespace std;




//栈的压入弹出序列，判断两个序列是否为同一个栈的序列

class soultion
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		size_t i = 0;
		size_t j = 0;

		stack<int> s;

		while (j < popV.size())
		{
			while (s.empty() || s.top() != popV[j])
			{
				if (i < pushV.size())
				{
					s.push(pushV[i]);
					++i;
				}

				else
				{
					return false;
				}
			}
			s.pop();
			++j;
		}
		return true;
	}
};
int main()
{
	soultion s;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);


	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	bool i = s.IsPopOrder(v1, v2);
	cout << i << endl;
	
	system("pause");
	return 0;
}