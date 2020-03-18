#pragma once
#include<vector>
namespace CLOSE_HASH//闭散列
{

	enum State
	{
		EXITS,//存在
		EMPTY,//为空
		DELETE,//删除
	};

	template<class T>
	struct  HashData
	{
		T _data;
		State _state;//状态，
	};

	template<class K, class V>

	class HashTable
	{
		typedef HashData<pair<K, V>> HashData;

	public:
		//pair<HashData*, bool> Insert(const pair<K, V>& kv)
		//{
		//	//考虑容量的问题
		//	if (dataNum == _tables.size())
		//	{ 
		//		size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
		//		vector<HashData> newtables;
		//		newtables.resize(newSize);
		//		for (size_t i = 0; i < _tables.size(); i++)//遍历原表数据
		//		{
		//			if (_tables[i]._state == EXITS)
		//			{
		//				//存入新表
		//				size_t index = _tables[i]._data.first % newtables.size();
		//				while (newtables[index]._state == EXITS)
		//				{
		//					++index;
		//					if (index == _tables.size())
		//					{
		//						index = 0;
		//					}
		//				}
		//				newtables[index]._data = _tables[i]._data;
		//				newtables[index]._state = EXITS;
		//			
		//			}
		//		}

		//		_tables.swap(newtables);//新表旧表交换

		//	}
		//	size_t index = kv.first % _tables.size();
		//	//线性探测，找出存放的位置
		//	while (_tables[index]._state == EXITS)
		//	{
		//		++index;
		//		if (index == _tables.size())
		//		{
		//			index = 0;
		//		}
		//	}
		//	_tables[index]._data = kv;
		//	_tables[index]._state = EXITS;
		//	++dataNum;
		//	return make_pair(&_tables[index], true);
		//}

		//插入方法二
		pair<HashData*, bool> Insert(const pair<K, V>& kv)
		{
			// 考虑容量的问题
			if (dataNum == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newSize);
				// 将旧表的数据重新计算位置，映射到新表
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._state == EXITS)
					{
						newht.Insert(_tables[i]._data);
					}
				}

				_tables.swap(newht._tables);
			}

			size_t index = kv.first % _tables.size();
			// 线性探测
			while (_tables[index]._state == EXITS)
			{
				if (_tables[index]._data.first == kv.first)
				{
					return make_pair(&_tables[index], false);
				}

				++index;
				if (index == _tables.size())
				{
					index = 0;
				}
			}

			_tables[index]._data = kv;
			_tables[index]._state = EXITS;
			++dataNum;

			return make_pair(&_tables[index], true);
		}


		HashData* Find(const K& key)
		{
			size_t index = key % _tables.size();
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXITS
					&& _tables[index]._data.first == key)
				{
					return _tables[index];
				}
				else
				{
					++index;
					if (index == _tables.size())
					{
						index = 0;

					}

				}
			}
			return nullptr;
		}

		void Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
			}
		}
		V& operator[](const K& key)
		{
			pair<HashData*, bool> ret = Insert(make_pair(key, V()));
			return ret.first->_data.second;
		}

	private:
		/*HashDate<>* _tables;
		size_t _size; 
		size_t _capacity;*/

		vector<HashData> _tables;
		size_t dataNum = 0;//有效数据个数
	};


	void test()
	{
		HashTable<int, int> ht;
		ht.Insert(make_pair(1, 1));
		ht.Insert(make_pair(3, 1));
		ht.Insert(make_pair(5, 1));
		ht.Insert(make_pair(7, 1));
		ht.Insert(make_pair(9, 1));
		ht.Insert(make_pair(11, 1));
		ht.Insert(make_pair(13, 1));
		ht.Insert(make_pair(15, 1));
		ht.Insert(make_pair(17, 1));
		ht.Insert(make_pair(21, 1));

		ht[27];
		ht[27] = 27;//修改
		ht[23] = 23;//插入+修改
		
	}
}