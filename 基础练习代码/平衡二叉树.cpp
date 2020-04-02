/*����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ���������
���ĳ������������ڵ���������������������1����ô������һ��ƽ���������
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