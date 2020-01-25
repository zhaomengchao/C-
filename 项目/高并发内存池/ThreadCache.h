#pragma once
#include"Common.h"

class ThreadCache
{
	//申请内存和释放内存
public:
	void *Allocte(size_t size);//new 申请的空间
	void Deallocte(void* ptr, size_t size);//free  释放的空间 size？

	//从中心缓存获取对象
	void* FetchFromCentralCache(size_t size);
	//如果自由链表中对象超过一定长度就要释放给中心缓存
	void ListTooLong(FreeList& freelist, size_t num,size_t size);

private:
	FreeList _freelist[NFREE_LIST];
};

_declspec (thread) static ThreadCache* pThreaCache = nullptr ;