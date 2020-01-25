#pragma once
#include"Common.h"

class CentralCache
{
public:
	//从中心缓存获取一定数量的对象给threadcache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);//要多少对象size----对象大小，num表示个数
	
	//将一定数量的对象释放到span跨度
	//threadcache释放后的内存，对象多大还给那个，页多大还给对应的页
	void ReleaseListToSpans(void* start,size_t size);
	
	//从spanlist 或者 pagecache获取一个span
	Span* GetOneSpan(size_t size);
private:
	SpanList _spanlists[NFREE_LIST];
}; 

static CentralCache centralCacheInst;