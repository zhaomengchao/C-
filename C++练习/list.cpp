#include<iostream>
#include<list>
using namespace std;

//list 构造函数接口的使用
//int main()
//{
//	std::list<int> l1;//构造空的list
//	std::list<int> l2(5, 10);//l2中放入五个10
//	std::list<int> l3(l2.begin(), l2.end());// 用l2的[begin(), end()）左闭右开的区间构造l3
//
//	std::list<int> l4(l3);                    // 用l3拷贝构造l4
//
//	// 以数组为迭代器区间构造l5
//	int array[] = {1,2,7,9};
//	std::list<int> l5 (array, array + sizeof(array) / sizeof(int) );
//
//
//	// 用迭代器方式打印l5中的元素
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


	// 用正向迭代器方式打印l中的元素
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;


	for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	system("pause");
	return 0;
}