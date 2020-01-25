#pragma once
#include"Common.h"

class PageCache
{
public:
	Span* NewSpan(size_t num);

	//��ϵͳ����numpageҳ�ڴ�ҵ�����������
	void SystemAllocPage(size_t numpage);
	//����pagecache���߼�
	void ReleaseSpanToPageCache(Span* span);
	//��Ӧ��id�Ҷ�Ӧ��span
	Span* GetIdToSpan(PAGE_ID id);

private:
	SpanList _spanlists[MAX_PAGES];
	std::map<PAGE_ID, Span*> _idSpanMap;
};

static PageCache pageCacheInst;