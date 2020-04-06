/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*请实现一个函数，用来判断一棵二叉树是不是对称的。
 如果一棵二叉树和它的镜像一样，那么它是对称的。*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool flag = true;
        if (root!=NULL)
        {
            flag = helper(root->left,root->right);
        }
        return flag;
       
    }
     bool helper(TreeNode*A, TreeNode* B)
    {
        if (A==NULL && B==NULL)
            return true;
        // 如果其中之一为空，也不是对称的
        if (A==NULL || B==NULL)
            return false;
        // 走到这里二者一定不为空
        if (A->val != B->val)
            return false;
        // 前序遍历
        return helper(A->left,B->right) && helper(A->right,B->left);
    }
};