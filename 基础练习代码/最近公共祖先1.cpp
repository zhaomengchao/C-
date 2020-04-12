/*
最近公共祖先
*/

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
    bool find(TreeNode* root, TreeNode* node)
    {
        if(root == nullptr)
            return false;
        
        if(root == node)
            return true;
        
        return find(root->left, node) || find(root->right, node);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        
        bool ispInLeft = find(root->left, p);
        bool ispInRight = !ispInLeft;

        bool isqInLeft = find(root->left, q);
        bool isqInRight = !isqInLeft;

        // 一个在左，一个在右，root就是公共祖先
        if((ispInLeft && isqInRight) || (isqInLeft && ispInRight))
            return root;

        // 都在左，就去左边找
        if(ispInLeft && isqInLeft)
            return lowestCommonAncestor(root->left, p, q);
        
        // 都在右，就去右边找
        if(ispInRight && isqInRight)
            return lowestCommonAncestor(root->right, p, q);

        return nullptr;
    }
};