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
		
		//���캯��
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}
		vector(const vector<T>& v)//�������캯��
		{
			_start = new T[v.size()];//size()��ȡ���ݸ���
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

		void swap(vector<T> &v)//��������vector �����ݿռ�
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

		void resize(size_t n, const T& val = T())//�ı�vector size
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

		void push_back(const T& x)//β��
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

		void erase(iterator pos)const
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

			// �ռ䲻���Ƚ������� 
			if (_finish == _end_of_storage)
			{               
				size_t size = _finish - _start;
				size_t newCapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newCapacity); 
				


				// ������������ݣ���Ҫ����pos                
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
		iterator _start;//ָ�����ݿ�Ŀ�ʼ
		iterator _finish;//ָ����Ч���ݿ�Ľ�β
		iterator _end_of_storage;//ָ��洢������β
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
}

int main()
{
	test1();
	system("pause");
	return 0;
}