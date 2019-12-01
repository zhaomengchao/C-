#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K> *_left;
	BSTreeNode<K> *_right;
	K _value;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _value(key)
	{

	}
};
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{

	}
	~BSTree()
	{

	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			//如果出现转化不通，则由于上面没有定义拷贝构造函数
			_root = new Node(key);//new失败了会抛异常
			return true;
		}
		Node *cur = _root;//保存根节点
		Node *parent = nullptr;
		while (cur)
		{
			if (cur->_value < key)
			{
				parent = cur;//用于保留前一个节点，为了保证叶子节点可以连接下一个结点，
				cur = cur->_right;
			}
			else if (cur->_value > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);//开辟一个节点
		if (parent->_value > key)//访问到叶子节点，在判断叶子结点的值与key的值的大小
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_value > key)
			{
				cur = cur->_left;
			}
			else if (cur->_value < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	//中序遍历
	void Inorder()//根节点是this隐含传参，在C++中递归子函数，必须函数重写，this是私有的，拿不出来
	{
		_Inorder(_root);
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_value << " ";
		_Inorder(root->_right);
	}
	//删除,不能用find会出现野指针，必须找到要删除的父亲节点
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_value > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_value < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//删除
				//左为空
				//有为空
				//左右都不为空
				Node* del = cur;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else
				{
					Node* lessParent = cur;
					Node* lessRight = cur->_right;
					while (lessRight->_left)
					{
						lessParent = lessRight;
						lessRight = lessRight->_left;
					}
					cur->_value = lessRight->_value;
					del = lessRight;
					if (lessParent->_left == lessRight)
					{
						lessParent->_left = lessRight->_right;
					}
					else
					{
						lessParent->_right = lessRight->_right;
					}
				}
				delete del;
				return true;
			}
		}
		return false;
	}


private:
	Node* _root;
};

void BSTreetest()
{
	int a[] = { 1, 4, 6, 2, 9, 10 };
	BSTree<int> T;
	for (auto e : a)
	{
		T.Insert(e);
	}
	T.Inorder();
	cout << T.Find(2)->_value << endl<<endl;
	T.Erase(4);
	T.Inorder();
}