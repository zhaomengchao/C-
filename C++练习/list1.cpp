#include<iostream>
#include<list>
using namespace std;

//list 构造函数接口的使用


//int main()
//{
//
//
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::list<int> l(array, array + sizeof(array) / sizeof(int));
//	
//	// 打印list中有效节点的个数
//	cout << l.size() << endl;
//
//	if (l.empty())
//	{
//		cout << "空的list" << endl;
//	}
//	else
//	{
//		for (const auto &e : l)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}


int main()
{


	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	

	for (const auto &e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	
	l.front() = 10;
	l.back() = 100;

	for (const auto &e : l)
	{
		cout << e << " ";
	}
	cout << endl;


	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	//int& a = l2.front();   因为l2是const类型的list对象，因此其front()为const 引用类型
	const int& a = l2.front();
	cout << l2.front() << endl;
	system("pause");
	return 0;
}

