//给定一个二叉搜索树，同时给定最小边界L?和最大边界?R。
//通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。
//你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root ) return nullptr;
        //剪枝分三种情况 0 [1,2, 3,] 2 [1,2,3] 4 [1,2,3]
        // 0 [1,2,3] ,左枝都不要了 root不要了，root=右枝
        if ( root->val < L) {
            root->left = nullptr;
            root = trimBST(root->right,L,R);
            return root;
        }
        // 2 [1,2,3];
        if ( root->val >= L && root->val <= R) {
            root->left = trimBST(root->left,L,R);
            root->right = trimBST(root->right,L,R);
            return root;
        }
        // 4 [1,2,3];
        if ( root->val > R) {
            root->right  = nullptr;
            root = trimBST(root->left,L,R);
            return root;
        }
        
        return root;      
        
    }
};
