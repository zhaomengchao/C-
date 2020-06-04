/*
二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。
实现一个方法，把二叉搜索树转换为单向链表，要求值的顺序保持不变，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

https://leetcode-cn.com/problems/binode-lcci/

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
    TreeNode *ans = new TreeNode(0),*cur=ans;
    void inOrder(TreeNode* node)
    {
        if(node == NULL)
        {
            return ;
        }
        inOrder(node->left);
        node->left = NULL;
        cur->right = node;
        cur = node;
        inOrder(node->right);
    }

    TreeNode* convertBiNode(TreeNode* root) {
        inOrder(root);
        return ans->right;
    }
};