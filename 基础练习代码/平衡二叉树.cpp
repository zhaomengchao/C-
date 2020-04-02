/*输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        if(abs(GetHight(root->left) - GetHight(root->right)) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int GetHight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftheight = GetHight(root->left);
        int rightheight = GetHight(root->right);

        return leftheight > rightheight ? leftheight+1 : rightheight+1;
    }

};