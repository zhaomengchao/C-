#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>

#include<assert.h>
#include<map>
#include<thread>
#include<mutex>

#ifdef _WIN32
#include<Windows.h>
#endif

//using namespace std;
using std::cout;
using std::endl;

//new  delete

const size_t MAX_SIZE = 64 * 1024;//64k之内找内存池，之外的直接找系统
const size_t NFREE_LIST = MAX_SIZE / 8; //先八字节对齐（？），链表的长度
const size_t MAX_PAGES = 129;//超过128就向系统要
const size_t PAGE_SHIFT = 12;//4K为页移位




inline void*& NextObj(void* obj)//减少消耗
{
	return *((void**)obj);//解引用后是一个指针（去前4/8个字节，存取下一个的对象的地址），在32位系统下是一个四字节，在64位系统下是一个八字节
}

class FreeList
{
public:
	void Push(void *obj)//插入对象，还东西给内存池  头插
	{
		NextObj(obj) = _freelist;//存储的是下一个对象的地址
		_freelist = obj;
		++_num;
	}
	void* Pop()//取对象
	{
		void* obj = _freelist;
		_freelist = NextObj(obj);
		--_num;
		return obj;
	}


	void PushRange(void* head, void* tail,size_t num)//插入一段范围,将从返回后剩余的一段地址空间挂在freelist上
	{
		NextObj(tail) = _freelist;
		_freelist = head;
		_num += num;
	}
	//相当于单链表的操作
	size_t PopRange(void*& start, void*& end, size_t num)//去除span中freelist中的一段内存
	{
		size_t actualNum = 0;
		void* prev = nullptr;//最终指向的是需要内存长度的尾
		void* cur = _freelist;
		for (; actualNum < num; ++actualNum)
		{
			prev = cur;
			cur = NextObj(cur);
		}

		start = _freelist;
		end = prev;

		_freelist = cur;

		num -= actualNum;
		return actualNum;
	}
	size_t Num()
	{
		return _num;
	}

	
	bool Empty()
	{
		return _freelist == nullptr;
	}

	void Clear()
	{
		_freelist = nullptr;
		_num = 0;
	}

private:
	void* _freelist = nullptr;//
	size_t _num = 0;
};

class SizeClass//算数据的大小
{
public:
	//static size_t ListIndex(size_t size)
	//{
	//	if(size % 8 == 0)
	//	{
	//		return size / 8 - 1;//对应freelist8 16 24的下标的位置
	//	}
	//	else
	//	{
	//		return size / 8;
	//	}
	//}

	//static size_t roundup(size_t size)
	//{
	//	if (size % 8 != 0)
	//	{
	//		return (size / 8 - 1) * 8;
	//	}
	//	else
	//	{
	//		return size;
	//	}
	//}

	


	//[9-16] + 7 = [16 + 23]-> 16 8 4 2 1
	//[17-32] + 15 = [32 + 47]->32 16 8 4 2 1
	static size_t _RoundUp(size_t size, int alignment)//alignment向上对齐，alignment对齐数，以8对齐或者16对齐，等等
	{
		return (size + alignment - 1)&(~(alignment - 1));
	}

	static inline size_t RoundUp(size_t size)//向上对齐
	{
		assert(size <= MAX_SIZE);

		if (size <= 128)
		{
			return _RoundUp(size, 8);//小于八个字节的
		}
		else if (size <= 1024)
		{
			return _RoundUp(size, 16);
		}
		else if (size <= 8192)
		{
			return _RoundUp(size, 128);
		}
		else if (size <= 65536)
		{
			return _RoundUp(size, 1024);
		}
		return -1;
	}

	static size_t _ListIndex(size_t size, int alignment_shift)//链表位置
	{
		return ((size + (1 << alignment_shift) - 1) >> alignment_shift) - 1;
	}
	// 映射的自由链表的位置
	static inline size_t ListIndex(size_t size)
	{
		assert(size <= MAX_SIZE);
		// 每个区间有多少个链
		static int group_array[4] = { 16, 56, 56, 112 };
		if (size <= 128){
			return _ListIndex(size, 3);
		}
		else if (size <= 1024){
			return _ListIndex(size - 128, 4) + group_array[0];
		}
		else if (size <= 8192){
			return _ListIndex(size - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (size <= 65536){
			return _ListIndex(size - 8192, 9) + group_array[2] + group_array[1] +
				group_array[0];
		}
		assert(false);
		return -1;
	}


	//针对每一个对象，到底要挪动多少个对象给下一层或者上一层
	//[2,512]个之间，申请的小变得大，申请的小，变得大
	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)//防止崩溃
			return 0;

		int num = MAX_SIZE / size;//最少一次给两个
		if (num < 2)
			num = 2;
		if (num > 512)//最少一次给一个页
			num = 512;
		return num;
	}


	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;
		npage >>= 12;

		if (npage == 0)
			npage = 1;

		return npage;
	}


};




//span 跨度  管理页为单位的内存对象，本质是方便做合并，解决内存碎片
//针对windows
#ifdef _WIN32
typedef unsigned int PAGE_ID;
#else
typedef unsigned long long PAGE_ID;
#endif

struct Span
{
	PAGE_ID _pageid = 0;//页号
	PAGE_ID _pagesize = 0;//页的数量

	FreeList _freelist;//对象自由链表
	size_t _objSize = 0;//自由链表对象的大小
	int _usecount = 0;//内存块对象实用计数

	//size_t objsize;//对象大小
	Span* _next;
	Span* _prev;
};

//SpanList上面存储的是Span这个对象的地址，
class SpanList
{
public:
	SpanList()//构造双向循环带头链表
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()//构建原生指针（相当于迭代器）
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;
	}

	void PushFront(Span* newspan)//头插
	{
		Insert(_head->_next, newspan);
	}

	void PopFront()//头删
	{
		Erase(_head->_next);
	}

	void PushBack(Span* newspan)//尾插
	{
		Insert(_head->_prev, newspan);
	}
	void PopBack()//尾删
	{
		Erase(_head->_prev);
	}

	void Insert(Span* pos, Span* newspan)///插入
	{
		Span* prev = pos->_prev;
		//prev  newspan  pos
		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan->_prev = prev;
	}
	void Erase(Span* pos)//删除
	{
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;
	}
	bool Empty()//判空
	{
		return Begin() == End();
	}
	void Lock()
	{
		_mtx.lock();
	}
	void Unlock()
	{
		_mtx.unlock();
	}

private:
	Span* _head;
	std::mutex _mtx;
};

inline static void* SystemAlloc(size_t numpage)//想系统申请
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, numpage*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap等
#endif
	if (ptr == nullptr)
		throw std::bad_alloc();//申请失败抛异常
	return ptr;
}

inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
#endif
}