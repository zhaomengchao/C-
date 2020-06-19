/*
��������Ŷ�������Ҷֵ��������ͬ����ô���Ǿ���Ϊ������?Ҷ����?�ġ�

�������������ͷ���ֱ�Ϊ?root1 ��?root2?������Ҷ���Ƶģ��򷵻�?true�����򷵻� false 

���ӣ�https://leetcode-cn.com/problems/leaf-similar-trees

*/
class Solution {
public:
    void preorder(TreeNode* node, vector<int>& v)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            v.push_back(node->val);
        }

        preorder(node->left, v);
        preorder(node->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> v1;
        preorder(root1, v1);

        vector<int> v2;
        preorder(root2, v2);

        return v1 == v2;
    }
};
