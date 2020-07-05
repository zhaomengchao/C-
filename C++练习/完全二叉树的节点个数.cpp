/*
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~?2h?个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left==right){
            return pow(2,left)+countNodes(root->right);
        }
        else{
            return  pow(2,right)+countNodes(root->left);
        }
    }

    int depth(TreeNode* root){
        int ans = 0;
        while(root){
            ans++;
            root = root->left;
        }
        return ans;
    }
};
