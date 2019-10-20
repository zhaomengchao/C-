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
	

	// 将原生态指针进行封装，因迭代器的使用形式与指针完全相同，因此，在自定义的类中必须实现以下方 法：        
             
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

		Ref operator*()//内置类型 指针可以解引用，迭代器的类中必须重载operator*()
		{
			return _node->_data;//是取一个指针所指向的单元的值
		}

		Ptr operator->()//自定义类型 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
		{
			return &_node->_data;
		}

		//指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int) 
		Self& operator++()//前置 
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)//后置
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// 至于operator--()/operator--(int)释放需要重载
		Self& operator--()//前置
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)//后置
		{
			_list_iterator<T>tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		// 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=() 
		//有struct 类型，必须用.
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
		typedef _list_node<T> node;//双向循环带头链表
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

		list<T>& operator =(const list<T> l)//重载赋值运算符
		{
			this->clear();
			auto it = l.begin();//可以避免是一般迭代器和const迭代器的不同

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
		void erase(iterator pos)//删除一个节点
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
			node* cur = pos._node;//存储这个节点
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