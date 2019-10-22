#include<iostream>
#include<stack>
#include<vector>


using namespace std;


//��Сջ��ʵ�֣���������ջ��
//�����һ����С��ǰһ��������mins
//��ջʱ�����s�е�top����mins�е�top��ɾ��,����ֻɾ��s
class minstack
{
private:
	stack<int> mins;
	stack<int> s;

public:
	minstack()//�Զ������͹��캯��������ʹ��Ĭ�ϵ�
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