//单值二叉树--所有结点值相等
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return _isUnivalTree(root, root->val);
    }
    bool _isUnivalTree(TreeNode* root, int val)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val != val)
        {
            return false;
        }
        return _isUnivalTree(root->left,root->val)&&_isUnivalTree(root->right,root->val);
    }
       
};