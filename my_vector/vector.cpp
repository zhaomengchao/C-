#include<iostream>
#include<string>
#include<assert.h>

using namespace std;


namespace zmc
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		
		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}
		vector(const vector<T>& v)//拷贝构造函数
		{
			_start = new T[v.size()];//size()获取数据个数
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
		}


		vector<T>& operator ==(vector<T>& v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		void swap(vector<T> &v)//交换两个vector 的数据空间
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		void resize(size_t n, const T& val = T())//改变vector size
		{
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}

		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T *tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*size());
					//delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)//尾插
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;

			//insert(end(), x);
		}

		void pop_back()
		{
			assert(_finish > _start);
			--finish;
		}

		void erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
		}

		/*void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t n = _finish - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}
			iterator end = _finish - 1;
			while (end >= _finish)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}*/


		iterator Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);

			// 空间不够先进行增容 
			if (_finish == _end_of_storage)
			{               
				size_t size = _finish - _start;
				size_t newCapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newCapacity); 
				


				// 如果发生了增容，需要重置pos                
				pos = _start + size;           
			}

				iterator end = _finish - 1;
				while (end >= pos)            
				{ 
					*(end + 1) = *end;
					--end; 
				}

			*pos = x;
			++_finish;
			return pos;
		}

		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}


	private:
		iterator _start;//指向数据块的开始
		iterator _finish;//指向有效数据块的结尾
		iterator _end_of_storage;//指向存储容量的尾
	};

}


void test1()
{
	zmc::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	auto it = v.begin();
	v.Insert(it, 0);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//利用迭代器打印vector中的数据
	 it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//使用迭代器进行修改
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

}


//迭代器失效问题讨论
void test()
{
	zmc::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	//找到3这个位置
	zmc::vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	v.erase(pos);//删除pos位置，会导致迭代器失效，产生非法访问

	cout << *pos << endl; // 此处会导致非法访问

	//在pos位置前插入数据可能会导致pos位置迭代器失效
	//使用insert插入可能也会导致迭代器失效，因为insert可能会引起增容问题，导致pos位置迭代器失效
	//增容后pos还指向原来空间，而原来空间已被释放，所以会出现迭代器失效

	 pos = find(v.begin(), v.end(), 3);

	v.Insert(pos, 30);

	cout << *pos << endl;


	////实现删除v中的所有偶数，如果是erase会导致迭代器失效
	////对失效的it++会使得程序崩溃

	zmc::vector<int> ::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);
	//	}
	//	++it;
	//}


	//这样会返回it位置的下一个，不会导致程序崩溃
	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		else
		{
			++it;
		}

	}


}



int main()
{
	//test1();
	test();
	system("pause");
	return 0;
}