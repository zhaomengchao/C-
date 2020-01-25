#include"ThreadCache.h"
#include"CentralCache.h"

//�ڴ�ؽ�������⣺���ܡ��ڴ���Ƭ������Ƭ�����ڴ棬�������벻�����ڴ棩
void *ThreadCache::Allocte(size_t size)//���ڴ������ռ�malloc
{
	size_t index = SizeClass::ListIndex(size);//������8 16 24
	FreeList& freelist = _freelist[index];
	if (!freelist.Empty())//�ڴ�ز�Ϊ��
	{
		return freelist.Pop();
	}
	else
	{
		//�����Ļ���ȥȡ����Դ���⣬���ϵ�alloc����Դ���գ�����ͬһ��index�£�������Դ�����ã�
		//size_t num = 20;//��ʱ����С���󣩵�һ����Ҫ�Ķ���
		//return FetchFromCentralCache(size);//�����������8����
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}
void ThreadCache::Deallocte(void* ptr, size_t size)
{
	size_t index = SizeClass::ListIndex(size);//
	FreeList& freelist = _freelist[index];
	freelist.Push(ptr);//���뵽����������

	//�����������һ��������|�ڴ��С
	size_t num = SizeClass::NumMoveSize(size);
	if (freelist.Num() >= num)
	{
		ListTooLong(freelist, num,size);//����һ�����Ļ���
	}
}
//������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���
void ThreadCache::ListTooLong(FreeList& freelist, size_t num,size_t size)
{
	void* start = nullptr, *end = nullptr;
	freelist.PopRange(start, end, num);
	NextObj(end) = nullptr;
	centralCacheInst.ReleaseListToSpans(start,size);
}


////�����Ļ����ȡ����ģ�黯���ԣ�
//void* threadcache::fetchfromcentralcache(size_t index)
//{
//	//ģ��ȡ�ڴ����Ĵ���
//	size_t num = 20;
//	size_t size = (index + 1) * 8;
//	char* start = (char*)malloc(size*num);//��centralcacheҪ�ڴ�
//	char* cur = start;
//	for (size_t i = 0; i < num; ++i)
//	{
//		char* next = cur + size;//��һ�������
//		nextobj(cur) = next;//������һ������
//
//		cur = next;
//	}
//	nextobj(cur) = nullptr;
//	void* head = nextobj(start);
//	void* tail = cur;
//
//	_freelist[index].pushrange(head, tail);//��һ��������뵽freelist����
//	return start;
//}


//�����Ļ����ȡ����
void* ThreadCache::FetchFromCentralCache(size_t size)
{
	size_t num = SizeClass::NumMoveSize(size);
	void * start = nullptr, *end = nullptr;	
	//��centralCacheInst�л�ȡ�ڴ�
	size_t actualNum= centralCacheInst.FetchRangeObj(start,end,num,size);

	if (actualNum == 1)//���ֻ��һ����ֱ�ӷ��ظ��̳߳�
	{
		return start;
	}
	else//�ж���Ļ�
	{
		size_t index = SizeClass::ListIndex(size);//�ҵ�Ҫ������������ĵ�λ��
		FreeList& list = _freelist[index];
		list.PushRange(NextObj(start), end, actualNum-1);//�������Ļ�����ȡ�����ڴ棬������Ҫ���ڴ沿�֣�����������Ļ����е�freelist��
		return start;
	}
}