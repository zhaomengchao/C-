#include<iostream>
#include<list>
using namespace std;

//list ���캯���ӿڵ�ʹ��


//int main()
//{
//
//
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::list<int> l(array, array + sizeof(array) / sizeof(int));
//	
//	// ��ӡlist����Ч�ڵ�ĸ���
//	cout << l.size() << endl;
//
//	if (l.empty())
//	{
//		cout << "�յ�list" << endl;
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
	//int& a = l2.front();   ��Ϊl2��const���͵�list���������front()Ϊconst ��������
	const int& a = l2.front();
	cout << l2.front() << endl;
	system("pause");
	return 0;
}

