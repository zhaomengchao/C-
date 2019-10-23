
//模拟实现队列
#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

namespace zmc
{
	template<class T, class con = vector<T>>
	class queue
	{
	public:
		queue()
		{

		}
		void Push(const T& x)
		{
			c.push_back(x);
		}
		void Pop()
		{
			c.pop_front();
		}
		T& Back()
		{
			return c.back();
		}
		const T& Back()const
		{
			return c.back();
		}

		T& Front()
		{
			return c.front();
		}
		
		const T& Front() const
		{
			return c.front();
		}

		size_t Size()
		{
			return c.size();
		}

		bool Empty()
		{
			return c.empty();
		}

	private:
		con c;
	};
}
int main()
{

	zmc::queue<int, list<int>> q;

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	
	cout << q.Size() << endl;

	cout << q.Front() << endl;
	q.Pop();
	cout << q.Front() << endl;

	cout << q.Back() << endl;
	system("pause");
	return 0;
}