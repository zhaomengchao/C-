#include"PageCache.h"

Span* PageCache::NewSpan(size_t numpage)//numpage是第几页，就从那个页的位置切
{
	//如果需要也的大小存在，直接取出，进入到centralcache中
	if (!_spanlists[numpage].Empty())
	{
		Span* span = _spanlists[numpage].Begin();
		_spanlists[numpage].PopFront();
		return span;
	}
	//分裂新页
	for (size_t i = numpage + 1; i < MAX_PAGES; ++i)
	{
		if (!_spanlists[i].Empty())
		{
			Span* span = _spanlists[i].Begin();
			_spanlists[i].PopFront();

			//切成两个Span，例如，第二页没有，就把第三页分为一个第二页，一个第一页
			Span* splistspan = new Span;//

			//////从span前面切
			//splistspan->_pageid = span->_pageid + numpage;//新的页号，等于原始页号加上要申请的页的大小
			//splistspan->_pagesize = span->_pagesize - numpage;//新的页的大小等于原始页的大小-需要的页的大小

			//span->_pagesize = numpage;//要的是从新页切下来的头部
			////将切割下来的span插入到spanlists中
			//_spanlists[splistspan->_pagesize].PushFront(splistspan);

			////从span后面切
			splistspan->_pageid = span->_pageid + span->_pagesize - numpage;//新的页号= 原始页号 + 页面大小 - 切去多少页
			splistspan->_pagesize = numpage;
			for (PAGE_ID i = 0; i < numpage; ++i)
			{
				_idSpanMap[splistspan->_pageid + i] = splistspan;
			}
			span->_pagesize -= numpage;
			_spanlists[span->_pagesize].PushFront(span);

			return splistspan;
		}
	}
	//向系统进行申请
	void* ptr = SystemAlloc(MAX_PAGES - 1);

	Span* bigspan = new Span;
	bigspan->_pageid =(PAGE_ID) ptr >> PAGE_SHIFT;//知道ID才会知道内存
	bigspan->_pagesize = MAX_PAGES - 1;//最大是128，MAX_PAGES给的是129，所以减一

	for (PAGE_ID i = 0; i < bigspan->_pagesize; ++i)
	{
		//页号映射span一个span可以有多个页号
		//_idSpanMap.insert(make_pair(bigspan->_pageid + i, bigspan));
		_idSpanMap[bigspan->_pageid + i] = bigspan;
	}
	_spanlists[bigspan->_pagesize].PushFront(bigspan);
	return NewSpan(numpage);
}

Span* PageCache::GetIdToSpan(PAGE_ID id)//相应的id找对应的span
{
	//std::map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(id);
	auto it = _idSpanMap.find(id);
	if (it != _idSpanMap.find(id))
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}

void PageCache::ReleaseSpanToPageCache(Span* span)
{
	//向前合并
	//几页的span挂到第几页上（页的合并）
	while (1)
	{
		PAGE_ID prevPageId = span->_pageid - 1;
		auto pit = _idSpanMap.find(prevPageId);
		//前面的页不存在（不属于自己)
		if (pit == _idSpanMap.end())
		{
			break;
		}
		//count不等于0说明前一个页还在使用中，不能合并
		Span* prevSpan = pit->second;
		if (prevSpan->_usecount != 0)
		{
			break;
		}

		//合并
		span->_pageid = prevSpan->_pageid;
		prevSpan->_pagesize += span->_pagesize;
		//更新map的映射关系
		for (PAGE_ID i = 0; i < prevSpan->_pagesize; ++i)
		{
			_idSpanMap[prevSpan->_pageid + i] = span;
		}
		_spanlists[prevSpan->_pagesize].Erase(prevSpan);
		delete prevSpan;
		
	}

	//向后合并
	while (1)
	{
		PAGE_ID nextPageId = span->_pageid + span->_pagesize;
		auto nextIt = _idSpanMap.find(nextPageId);
		if (nextIt == _idSpanMap.end())
		{
			break;
		}

		Span* nextSpan = nextIt->second;
		if (nextSpan->_usecount != 0)
		{
			break;
		}

		span->_pagesize += nextSpan->_pagesize;
		for (PAGE_ID i = 0; i < nextSpan->_pagesize; ++i)
		{
			_idSpanMap[nextSpan->_pageid + i] = span;
		}
		_spanlists[nextSpan->_pagesize].Erase(nextSpan);
		delete nextSpan;
	}
	_spanlists[span->_pagesize].PushFront(span);
}