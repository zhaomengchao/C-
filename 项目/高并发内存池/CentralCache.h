#pragma once
#include"Common.h"

class CentralCache
{
public:
	//�����Ļ����ȡһ�������Ķ����threadcache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);//Ҫ���ٶ���size----�����С��num��ʾ����
	
	//��һ�������Ķ����ͷŵ�span���
	//threadcache�ͷź���ڴ棬�����󻹸��Ǹ���ҳ��󻹸���Ӧ��ҳ
	void ReleaseListToSpans(void* start,size_t size);
	
	//��spanlist ���� pagecache��ȡһ��span
	Span* GetOneSpan(size_t size);
private:
	SpanList _spanlists[NFREE_LIST];
}; 

static CentralCache centralCacheInst;