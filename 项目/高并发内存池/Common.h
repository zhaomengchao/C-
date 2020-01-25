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

const size_t MAX_SIZE = 64 * 1024;//64k֮�����ڴ�أ�֮���ֱ����ϵͳ
const size_t NFREE_LIST = MAX_SIZE / 8; //�Ȱ��ֽڶ��루����������ĳ���
const size_t MAX_PAGES = 129;//����128����ϵͳҪ
const size_t PAGE_SHIFT = 12;//4KΪҳ��λ




inline void*& NextObj(void* obj)//��������
{
	return *((void**)obj);//�����ú���һ��ָ�루ȥǰ4/8���ֽڣ���ȡ��һ���Ķ���ĵ�ַ������32λϵͳ����һ�����ֽڣ���64λϵͳ����һ�����ֽ�
}

class FreeList
{
public:
	void Push(void *obj)//������󣬻��������ڴ��  ͷ��
	{
		NextObj(obj) = _freelist;//�洢������һ������ĵ�ַ
		_freelist = obj;
		++_num;
	}
	void* Pop()//ȡ����
	{
		void* obj = _freelist;
		_freelist = NextObj(obj);
		--_num;
		return obj;
	}


	void PushRange(void* head, void* tail,size_t num)//����һ�η�Χ,���ӷ��غ�ʣ���һ�ε�ַ�ռ����freelist��
	{
		NextObj(tail) = _freelist;
		_freelist = head;
		_num += num;
	}
	//�൱�ڵ�����Ĳ���
	size_t PopRange(void*& start, void*& end, size_t num)//ȥ��span��freelist�е�һ���ڴ�
	{
		size_t actualNum = 0;
		void* prev = nullptr;//����ָ�������Ҫ�ڴ泤�ȵ�β
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

class SizeClass//�����ݵĴ�С
{
public:
	//static size_t ListIndex(size_t size)
	//{
	//	if(size % 8 == 0)
	//	{
	//		return size / 8 - 1;//��Ӧfreelist8 16 24���±��λ��
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
	static size_t _RoundUp(size_t size, int alignment)//alignment���϶��룬alignment����������8�������16���룬�ȵ�
	{
		return (size + alignment - 1)&(~(alignment - 1));
	}

	static inline size_t RoundUp(size_t size)//���϶���
	{
		assert(size <= MAX_SIZE);

		if (size <= 128)
		{
			return _RoundUp(size, 8);//С�ڰ˸��ֽڵ�
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

	static size_t _ListIndex(size_t size, int alignment_shift)//����λ��
	{
		return ((size + (1 << alignment_shift) - 1) >> alignment_shift) - 1;
	}
	// ӳ������������λ��
	static inline size_t ListIndex(size_t size)
	{
		assert(size <= MAX_SIZE);
		// ÿ�������ж��ٸ���
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


	//���ÿһ�����󣬵���ҪŲ�����ٸ��������һ�������һ��
	//[2,512]��֮�䣬�����С��ô������С����ô�
	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)//��ֹ����
			return 0;

		int num = MAX_SIZE / size;//����һ�θ�����
		if (num < 2)
			num = 2;
		if (num > 512)//����һ�θ�һ��ҳ
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




//span ���  ����ҳΪ��λ���ڴ���󣬱����Ƿ������ϲ�������ڴ���Ƭ
//���windows
#ifdef _WIN32
typedef unsigned int PAGE_ID;
#else
typedef unsigned long long PAGE_ID;
#endif

struct Span
{
	PAGE_ID _pageid = 0;//ҳ��
	PAGE_ID _pagesize = 0;//ҳ������

	FreeList _freelist;//������������
	size_t _objSize = 0;//�����������Ĵ�С
	int _usecount = 0;//�ڴ�����ʵ�ü���

	//size_t objsize;//�����С
	Span* _next;
	Span* _prev;
};

//SpanList����洢����Span�������ĵ�ַ��
class SpanList
{
public:
	SpanList()//����˫��ѭ����ͷ����
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()//����ԭ��ָ�루�൱�ڵ�������
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;
	}

	void PushFront(Span* newspan)//ͷ��
	{
		Insert(_head->_next, newspan);
	}

	void PopFront()//ͷɾ
	{
		Erase(_head->_next);
	}

	void PushBack(Span* newspan)//β��
	{
		Insert(_head->_prev, newspan);
	}
	void PopBack()//βɾ
	{
		Erase(_head->_prev);
	}

	void Insert(Span* pos, Span* newspan)///����
	{
		Span* prev = pos->_prev;
		//prev  newspan  pos
		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan->_prev = prev;
	}
	void Erase(Span* pos)//ɾ��
	{
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;
	}
	bool Empty()//�п�
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

inline static void* SystemAlloc(size_t numpage)//��ϵͳ����
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, numpage*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap��
#endif
	if (ptr == nullptr)
		throw std::bad_alloc();//����ʧ�����쳣
	return ptr;
}

inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
#endif
}