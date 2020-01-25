#include"PageCache.h"

Span* PageCache::NewSpan(size_t numpage)//numpage�ǵڼ�ҳ���ʹ��Ǹ�ҳ��λ����
{
	//�����ҪҲ�Ĵ�С���ڣ�ֱ��ȡ�������뵽centralcache��
	if (!_spanlists[numpage].Empty())
	{
		Span* span = _spanlists[numpage].Begin();
		_spanlists[numpage].PopFront();
		return span;
	}
	//������ҳ
	for (size_t i = numpage + 1; i < MAX_PAGES; ++i)
	{
		if (!_spanlists[i].Empty())
		{
			Span* span = _spanlists[i].Begin();
			_spanlists[i].PopFront();

			//�г�����Span�����磬�ڶ�ҳû�У��Ͱѵ���ҳ��Ϊһ���ڶ�ҳ��һ����һҳ
			Span* splistspan = new Span;//

			//////��spanǰ����
			//splistspan->_pageid = span->_pageid + numpage;//�µ�ҳ�ţ�����ԭʼҳ�ż���Ҫ�����ҳ�Ĵ�С
			//splistspan->_pagesize = span->_pagesize - numpage;//�µ�ҳ�Ĵ�С����ԭʼҳ�Ĵ�С-��Ҫ��ҳ�Ĵ�С

			//span->_pagesize = numpage;//Ҫ���Ǵ���ҳ��������ͷ��
			////���и�������span���뵽spanlists��
			//_spanlists[splistspan->_pagesize].PushFront(splistspan);

			////��span������
			splistspan->_pageid = span->_pageid + span->_pagesize - numpage;//�µ�ҳ��= ԭʼҳ�� + ҳ���С - ��ȥ����ҳ
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
	//��ϵͳ��������
	void* ptr = SystemAlloc(MAX_PAGES - 1);

	Span* bigspan = new Span;
	bigspan->_pageid =(PAGE_ID) ptr >> PAGE_SHIFT;//֪��ID�Ż�֪���ڴ�
	bigspan->_pagesize = MAX_PAGES - 1;//�����128��MAX_PAGES������129�����Լ�һ

	for (PAGE_ID i = 0; i < bigspan->_pagesize; ++i)
	{
		//ҳ��ӳ��spanһ��span�����ж��ҳ��
		//_idSpanMap.insert(make_pair(bigspan->_pageid + i, bigspan));
		_idSpanMap[bigspan->_pageid + i] = bigspan;
	}
	_spanlists[bigspan->_pagesize].PushFront(bigspan);
	return NewSpan(numpage);
}

Span* PageCache::GetIdToSpan(PAGE_ID id)//��Ӧ��id�Ҷ�Ӧ��span
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
	//��ǰ�ϲ�
	//��ҳ��span�ҵ��ڼ�ҳ�ϣ�ҳ�ĺϲ���
	while (1)
	{
		PAGE_ID prevPageId = span->_pageid - 1;
		auto pit = _idSpanMap.find(prevPageId);
		//ǰ���ҳ�����ڣ��������Լ�)
		if (pit == _idSpanMap.end())
		{
			break;
		}
		//count������0˵��ǰһ��ҳ����ʹ���У����ܺϲ�
		Span* prevSpan = pit->second;
		if (prevSpan->_usecount != 0)
		{
			break;
		}

		//�ϲ�
		span->_pageid = prevSpan->_pageid;
		prevSpan->_pagesize += span->_pagesize;
		//����map��ӳ���ϵ
		for (PAGE_ID i = 0; i < prevSpan->_pagesize; ++i)
		{
			_idSpanMap[prevSpan->_pageid + i] = span;
		}
		_spanlists[prevSpan->_pagesize].Erase(prevSpan);
		delete prevSpan;
		
	}

	//���ϲ�
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