//同步

#pragma once
#include "ThreadCache.h"
#include "PageCache.h"

void* ConcurrentMalloc(size_t size)
{
	if (size <= MAX_SIZE) // [1byte, 64kb]
	{
		if (pThreaCache == nullptr)
		{
			pThreaCache = new ThreadCache;
			cout << std::this_thread::get_id() << "->" << pThreaCache << endl;
		}

		return pThreaCache->Allocte(size);
	}
	else if (size <= ((MAX_PAGES - 1) << PAGE_SHIFT)) // (64kb, 128*4k]128页
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);//对齐
		size_t pagenum = (align_size >> PAGE_SHIFT);//多少页
		Span* span = pageCacheInst.NewSpan(pagenum);//
		span->_objSize = align_size;
		void* ptr = (void*)(span->_pageid << PAGE_SHIFT);
		return ptr;
	}
	else // [128*4kb,-]128到系统极限
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);
		size_t pagenum = (align_size >> PAGE_SHIFT);
		return SystemAlloc(pagenum);
	}
}

void ConcurrentFree(void* ptr)
{
	size_t pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	Span* span = pageCacheInst.GetIdToSpan(pageid);//页号对span的映射
	if (span == nullptr)// [128*4kb,-]
	{
		SystemFree(ptr);
		return;
	}

	size_t size = span->_objSize;
	if (size <= MAX_SIZE) // [1byte, 64kb]
	{
		pThreaCache->Deallocte(ptr, size);
	}
	else if (size <= ((MAX_PAGES - 1) << PAGE_SHIFT)) // (64kb, 128*4kb]
	{
		pageCacheInst.ReleaseSpanToPageCache(span);
	}
}
