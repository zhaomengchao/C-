#include<iostream>

using namespace std;


namespace zmc
{
	template<class T>

	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;


		_list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{

		}
	};
	

	// ��ԭ��ָ̬����з�װ�����������ʹ����ʽ��ָ����ȫ��ͬ����ˣ����Զ�������б���ʵ�����·� ����        
             
	template<class T,class Ref,class Ptr>

	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator <T,Ref,Ptr> Self;

		node* _node;
		_list_iterator(node* node)
			:_node(node)
		{

		}

		Ref operator*()//�������� ָ����Խ����ã������������б�������operator*()
		{
			return _node->_data;//��ȡһ��ָ����ָ��ĵ�Ԫ��ֵ
		}

		Ptr operator->()//�Զ������� ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
		{
			return &_node->_data;
		}

		//ָ�����++����ƶ������������б�������operator++()��operator++(int) 
		Self& operator++()//ǰ�� 
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)//����
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// ����operator--()/operator--(int)�ͷ���Ҫ����
		Self& operator--()//ǰ��
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)//����
		{
			_list_iterator<T>tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		// ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=() 
		//��struct ���ͣ�������.
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}

	};


	template<class T>
	class list
	{
		typedef _list_node<T> node;//˫��ѭ����ͷ����
	private:
		node* _head;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&,const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		
		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			auto it = l.begin();
			for (it != l.end())
			{
				push_back(*it);
				it++;
			}
		}

		~list()
		{
			//clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		list<T>& operator =(const list<T> l)//���ظ�ֵ�����
		{
			this->clear();
			auto it = l.begin();//���Ա�����һ���������const�������Ĳ�ͬ

			for (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		/*list<T>& operator =(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}*/



		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;

			_head->_prev = newnode;

		}
		void erase(iterator pos)//ɾ��һ���ڵ�
		{
			node* cur = pos._node;

			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			//return iterator(next);
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;//�洢����ڵ�
			node* prev = cur->_prev;
			
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}
		void print_list(const list<int>& l)
		{
			list<int>::const_iterator it = l.begin();

			while (it != l.end())
			{
				cout << *it << endl;
				it++;
			}
			cout << endl;
		}

	};

	


	void test1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.print_list(l);

		l.pop_back();
		l.print_list(l);

		l.push_front(0);
		l.print_list(l);

		l.pop_front();
		l.print_list(l);
	}
}

int main()
{
	zmc::test1();
	system("pause");
	return 0;
}