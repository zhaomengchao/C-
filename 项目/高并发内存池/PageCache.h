#pragma once
#include"Common.h"

class PageCache
{
public:
	Span* NewSpan(size_t num);

	//向系统申请numpage页内存挂到自由链表中
	void SystemAllocPage(size_t numpage);
	//还给pagecache的逻辑
	void ReleaseSpanToPageCache(Span* span);
	//相应的id找对应的span
	Span* GetIdToSpan(PAGE_ID id);

private:
	SpanList _spanlists[MAX_PAGES];
	std::map<PAGE_ID, Span*> _idSpanMap;
};

static PageCache pageCacheInst;