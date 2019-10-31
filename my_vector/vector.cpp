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
	//���õ�������ӡvector�е�����
	 it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//ʹ�õ����������޸�
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

}


//������ʧЧ��������
void test()
{
	zmc::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	//�ҵ�3���λ��
	zmc::vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	v.erase(pos);//ɾ��posλ�ã��ᵼ�µ�����ʧЧ�������Ƿ�����

	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

	//��posλ��ǰ�������ݿ��ܻᵼ��posλ�õ�����ʧЧ
	//ʹ��insert�������Ҳ�ᵼ�µ�����ʧЧ����Ϊinsert���ܻ������������⣬����posλ�õ�����ʧЧ
	//���ݺ�pos��ָ��ԭ���ռ䣬��ԭ���ռ��ѱ��ͷţ����Ի���ֵ�����ʧЧ

	 pos = find(v.begin(), v.end(), 3);

	v.Insert(pos, 30);

	cout << *pos << endl;


	////ʵ��ɾ��v�е�����ż���������erase�ᵼ�µ�����ʧЧ
	////��ʧЧ��it++��ʹ�ó������

	zmc::vector<int> ::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);
	//	}
	//	++it;
	//}


	//�����᷵��itλ�õ���һ�������ᵼ�³������
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