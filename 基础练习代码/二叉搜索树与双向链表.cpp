/*
��ָ Offer 36. ������������˫������

����һ�ö��������������ö���������ת����һ�������ѭ��˫������Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    vector<Node*> arr;
    void help(Node* root)
    {
        if(root==NULL)return;
        help(root->left);
        arr.push_back(root);
        help(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root==NULL)return NULL;
        help(root);
        for(int i=0;i<arr.size()-1;i++)
        {
            arr[i]->right=arr[i+1];
            arr[i+1]->left=arr[i];
        }
        arr[arr.size()-1]->right=arr[0];
        arr[0]->left=arr[arr.size()-1];
        return arr[0];
    }
};
