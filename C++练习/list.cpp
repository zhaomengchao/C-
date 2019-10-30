#include<iostream>
#include<list>
using namespace std;

//list ���캯���ӿڵ�ʹ��
//int main()
//{
//	std::list<int> l1;//����յ�list
//	std::list<int> l2(5, 10);//l2�з������10
//	std::list<int> l3(l2.begin(), l2.end());// ��l2��[begin(), end()������ҿ������乹��l3
//
//	std::list<int> l4(l3);                    // ��l3��������l4
//
//	// ������Ϊ���������乹��l5
//	int array[] = {1,2,7,9};
//	std::list<int> l5 (array, array + sizeof(array) / sizeof(int) );
//
//
//	// �õ�������ʽ��ӡl5�е�Ԫ��
//	for(std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//		std::cout << *it << " ";
//	std::cout<<endl;
//
//	for(auto& e : l5)
//		std::cout<< e << " ";
//	system("pause");
//	return 0;
//}

int main()
{
	int array[] = { 1, 2, 7, 9, 3, 4, 5, 6  };
	std::list<int> l(array, array + sizeof(array) / sizeof(int));


	// �������������ʽ��ӡl�е�Ԫ��
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;


	for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	system("pause");
	return 0;
}