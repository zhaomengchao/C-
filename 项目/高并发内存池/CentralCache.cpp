#include"CentralCache.h"
#include"PageCache.h"

Span* CentralCache::GetOneSpan(size_t size)
{
	//��ȡһ���ж����Span
	size_t index = SizeClass::ListIndex(size);//span���ڵ�freelist�Ƿ�Ϊ��
	SpanList& spanlist = _spanlists[index];//��һ�ֿ����Ǵ�centralcache�л�ȡ��span

	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())
		{
			return it;//����span
		}
		else
		{
			it = it->_next;
		}
	}
	//�ڶ��ִ�pagecache��ȡһ��span
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = pageCacheInst.NewSpan(numpage);
	//��span�����гɶ�Ӧ��С�ҵ�span ��freelist��
	char* start = (char*)(span->_pageid << 12);//����ʮ��λ������һҳ
	char* end = start + (span->_pagesize << 12);
	while (start < end)
	{
		char* obj = start;
		start += size;//�г�����span

		span->_freelist.Push(obj);
	}
	span->_objSize = size;
	spanlist.PushFront(span);//����������
	

	//Span* span;
	return span;

}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)//��ȡһ�ζ���
{

	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanlists[index];
	spanlist.Lock();

	Span* span = GetOneSpan(size);//���յ���span������й���
	FreeList& freelist = span->_freelist;
	
	size_t actualNum = freelist.PopRange(start, end, num);//��span�е�list�л�ȡʵ�ʳ��ȵ��ڴ�
	span->_usecount += actualNum;//���˶��ٸ�
	//�Ż�
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
		//��ʾ��ǰspan�г�ȥ�Ķ���ȫ�����أ����Խ�span����pagecache���кϲ��������ڴ���Ƭ
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
