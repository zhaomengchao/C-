/*
如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是?叶相似?的。

如果给定的两个头结点分别为?root1 和?root2?的树是叶相似的，则返回?true；否则返回 false 

链接：https://leetcode-cn.com/problems/leaf-similar-trees

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
