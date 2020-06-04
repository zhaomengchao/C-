/*
���������ݽṹTreeNode��������ʾ������������left�ÿգ�rightΪ��һ������ڵ㣩��
ʵ��һ���������Ѷ���������ת��Ϊ��������Ҫ��ֵ��˳�򱣳ֲ��䣬ת������Ӧ��ԭַ�ģ�Ҳ������ԭʼ�Ķ�����������ֱ���޸ġ�

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