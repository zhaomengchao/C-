#include"CentralCache.h"
#include"PageCache.h"

Span* CentralCache::GetOneSpan(size_t size)
{
	//获取一个有对象的Span
	size_t index = SizeClass::ListIndex(size);//span所在的freelist是否为空
	SpanList& spanlist = _spanlists[index];//第一种可能是从centralcache中获取的span

	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())
		{
			return it;//返回span
		}
		else
		{
			it = it->_next;
		}
	}
	//第二种从pagecache获取一个span
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = pageCacheInst.NewSpan(numpage);
	//把span对象切成对应大小挂到span 的freelist中
	char* start = (char*)(span->_pageid << 12);//左移十二位，就是一页
	char* end = start + (span->_pagesize << 12);
	while (start < end)
	{
		char* obj = start;
		start += size;//切出来的span

		span->_freelist.Push(obj);
	}
	span->_objSize = size;
	spanlist.PushFront(span);//挂入链表中
	

	//Span* span;
	return span;

}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)//获取一段对象
{

	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanlists[index];
	spanlist.Lock();

	Span* span = GetOneSpan(size);//接收到的span最好是切过的
	FreeList& freelist = span->_freelist;
	
	size_t actualNum = freelist.PopRange(start, end, num);//从span中的list中获取实际长度的内存
	span->_usecount += actualNum;//用了多少个
	//优化
	spanlist.Unlock();
	return actualNum;
}


void CentralCache::ReleaseListToSpans(void* start,size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanlists[index];
	spanlist.Lock();
	while (start)
	{
		void* next = NextObj(start);
		PAGE_ID id = (PAGE_ID)start >> PAGE_SHIFT;
		Span* span = pageCacheInst.GetIdToSpan(id);
		span->_freelist.Push(start);
		span->_usecount--;
		//表示当前span切出去的对象全部返回，可以将span还给pagecache进行合并，减少内存碎片
		if (span->_usecount == 0)
		{
			size_t index = SizeClass::ListIndex(span->_objSize);
			_spanlists[index].Erase(span);
			span->_freelist.Clear();
			pageCacheInst.ReleaseSpanToPageCache(span);
		}

		start = next;
	}
	spanlist.Unlock();
}
