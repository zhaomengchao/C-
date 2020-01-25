#include<vector>
#include"ThreadCache.h"

//void UnitThreadCacheTest()
//{
//	ThreadCache tc;
//	vector<void*> v;
//	for (size_t i = 0; i < 21; i++)
//	{
//		v.push_back(tc.Allocte(7));
//	}
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		printf("[%d]->%p\n", i, v[i]);
//	}
//	for (auto ptr : v)
//	{
//		tc.Deallocte(ptr, 7);
//	}
//
//}



void UnitTestSizeClass()
{
	cout << SizeClass::RoundUp(1) << endl;
	cout << SizeClass::RoundUp(127) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(129) << endl;
	cout << SizeClass::RoundUp(1023) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(1025) << endl;
	cout << SizeClass::RoundUp(8*1024) << endl;
	cout << endl;

}
//void UnitTest()
//{
//	void* ptr = SystemAlloc(MAX_PAGES - 1);
//	PAGE_ID id = (PAGE_ID)ptr >> PAGE_SHIFT;
//	void* ptrshift = (void*)(id << PAGE_SHIFT);
//}
//
//
//void UnitThreadCacheTest()
//{
//	ThreadCache tc;
//	std::vector<void*> v;
//	size_t size = 7;
//	for (size_t i = 0; i < SizeClass::NumMoveSize(size); i++)
//	{
//		v.push_back(tc.Allocte(size));
//	}
//	v.push_back(tc.Allocte(size));
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		printf("[%d]->%p\n", i, v[i]);
//	}
//	for (auto ptr : v)
//	{
//		tc.Deallocte(ptr, 7);
//	}
//
//}





#include "Concurrent.h"

void func1(size_t n)
{
	std::vector<void*> v;
	size_t size = 7;
	for (size_t i = 0; i < SizeClass::NumMoveSize(size) + 1; ++i)
	{
		v.push_back(ConcurrentMalloc(size));
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		//printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		ConcurrentFree(ptr);
	}

	v.clear();
}

void func2(size_t n)
{
	std::vector<void*> v;
	size_t size = 7;
	for (size_t i = 0; i < SizeClass::NumMoveSize(size) + 1; ++i)
	{
		v.push_back(ConcurrentMalloc(size));
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		//	printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		ConcurrentFree(ptr);
	}

	v.clear();
}


//void func1(size_t n)
//{
//	static int j = 0;
//	for (size_t i = 0; i < n; ++i)
//	{
//		//cout << i << endl;
//		++j;
//	}
//	cout << "j=" << j << endl;
//}

int main()
{
	//UnitThreadCacheTest();
	//UnitTestSizeClass();
	//UnitTest();
	//UnitThreadCacheTest();
	/*std::thread t1(func1, 100);
	std::thread t2(func1, 100);*/
	//cout << "主线程等待" << endl;
	/*t1.join();
	t2.join();*/

	void* ptr1 = ConcurrentMalloc(1 << PAGE_SHIFT);
	void* ptr2 = ConcurrentMalloc(65 << PAGE_SHIFT);
	void* ptr3 = ConcurrentMalloc(129 << PAGE_SHIFT);

	ConcurrentFree(ptr1);
	ConcurrentFree(ptr2);
	ConcurrentFree(ptr3);

	system("pause");
	return 0;
}