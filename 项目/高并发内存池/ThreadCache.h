#pragma once
#include"Common.h"

class ThreadCache
{
	//�����ڴ���ͷ��ڴ�
public:
	void *Allocte(size_t size);//new ����Ŀռ�
	void Deallocte(void* ptr, size_t size);//free  �ͷŵĿռ� size��

	//�����Ļ����ȡ����
	void* FetchFromCentralCache(size_t size);
	//������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���
	void ListTooLong(FreeList& freelist, size_t num,size_t size);

private:
	FreeList _freelist[NFREE_LIST];
};

_declspec (thread) static ThreadCache* pThreaCache = nullptr ;