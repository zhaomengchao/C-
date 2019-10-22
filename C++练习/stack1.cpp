#include<iostream>
#include<stack>
#include<vector>


using namespace std;


//最小栈的实现，采用两个栈，
//如果后一个数小于前一个数，入mins
//出栈时，如果s中的top等于mins中的top都删除,否则只删除s
class minstack
{
private:
	stack<int> mins;
	stack<int> s;

public:
	minstack()//自定义类型构造函数。可以使用默认的
	{

	}
	void push(int x)
	{
		s.push(x);
		if (mins.empty() || mins.top() <= s.top())
		{
			mins.push(x);
		}
	}

	void pop()
	{
		if (mins.top() == s.top())
		{
			mins.pop();
		}
		s.pop();
	}

	int top()
	{
		return s.top();
	}

	int getMin()
	{
		return mins.top();
	}
};


int main()
{
	minstack ms;
	ms.push(1);
	ms.push(0);
	ms.push(6);
	ms.push(3);
	ms.push(2);

	ms.pop();
	ms.top();

	system("pause");
	return 0;
}