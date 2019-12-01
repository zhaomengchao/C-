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
			//�������ת����ͨ������������û�ж��忽�����캯��
			_root = new Node(key);//newʧ���˻����쳣
			return true;
		}
		Node *cur = _root;//������ڵ�
		Node *parent = nullptr;
		while (cur)
		{
			if (cur->_value < key)
			{
				parent = cur;//���ڱ���ǰһ���ڵ㣬Ϊ�˱�֤Ҷ�ӽڵ����������һ����㣬
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
		cur = new Node(key);//����һ���ڵ�
		if (parent->_value > key)//���ʵ�Ҷ�ӽڵ㣬���ж�Ҷ�ӽ���ֵ��key��ֵ�Ĵ�С
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
	//�������
	void Inorder()//���ڵ���this�������Σ���C++�еݹ��Ӻ��������뺯����д��this��˽�еģ��ò�����
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
	//ɾ��,������find�����Ұָ�룬�����ҵ�Ҫɾ���ĸ��׽ڵ�
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
				//ɾ��
				//��Ϊ��
				//��Ϊ��
				//���Ҷ���Ϊ��
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