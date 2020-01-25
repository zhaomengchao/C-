#include"ThreadCache.h"
#include"CentralCache.h"

//内存池解决的问题：性能、内存碎片（外碎片，有内存，但是申请不出大内存）
void *ThreadCache::Allocte(size_t size)//向内存池申请空间malloc
{
	size_t index = SizeClass::ListIndex(size);//对齐数8 16 24
	FreeList& freelist = _freelist[index];
	if (!freelist.Empty())//内存池不为空
	{
		return freelist.Pop();
	}
	else
	{
		//从中心缓存去取（资源均衡，不断调alloc，资源回收，挂在同一个index下，其他资源不可用）
		//size_t num = 20;//暂时处理（小对象）第一次需要的东西
		//return FetchFromCentralCache(size);//最早设计是以8对齐
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}
void ThreadCache::Deallocte(void* ptr, size_t size)
{
	size_t index = SizeClass::ListIndex(size);//
	FreeList& freelist = _freelist[index];
	freelist.Push(ptr);//插入到自由链表中

	//对象个数满足一定的条件|内存大小
	size_t num = SizeClass::NumMoveSize(size);
	if (freelist.Num() >= num)
	{
		ListTooLong(freelist, num,size);//另外一个中心缓冲
	}
}
//如果自由链表中对象超过一定长度就要释放给中心缓存
void ThreadCache::ListTooLong(FreeList& freelist, size_t num,size_t size)
{
	void* start = nullptr, *end = nullptr;
	freelist.PopRange(start, end, num);
	NextObj(end) = nullptr;
	centralCacheInst.ReleaseListToSpans(start,size);
}


////从中心缓存获取对象（模块化测试）
//void* threadcache::fetchfromcentralcache(size_t index)
//{
//	//模拟取内存对象的代码
//	size_t num = 20;
//	size_t size = (index + 1) * 8;
//	char* start = (char*)malloc(size*num);//找centralcache要内存
//	char* cur = start;
//	for (size_t i = 0; i < num; ++i)
//	{
//		char* next = cur + size;//下一对象距离
//		nextobj(cur) = next;//连接下一个对象
//
//		cur = next;
//	}
//	nextobj(cur) = nullptr;
//	void* head = nextobj(start);
//	void* tail = cur;
//
//	_freelist[index].pushrange(head, tail);//将一段链表挂入到freelist当中
//	return start;
//}


//从中心缓存获取对象
void* ThreadCache::FetchFromCentralCache(size_t size)
{
	size_t num = SizeClass::NumMoveSize(size);
	void * start = nullptr, *end = nullptr;	
	//从centralCacheInst中获取内存
	size_t actualNum= centralCacheInst.FetchRangeObj(start,end,num,size);

	if (actualNum == 1)//如果只有一个，直接返回给线程池
	{
		return start;
	}
	else//有多个的话
	{
		size_t index = SizeClass::ListIndex(size);//找到要返回自由链表的的位置
		FreeList& list = _freelist[index];
		list.PushRange(NextObj(start), end, actualNum-1);//将从中心缓存中取出的内存，返回需要的内存部分，其余挂在中心缓存中的freelist上
		return start;
	}
}