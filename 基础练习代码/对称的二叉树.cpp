/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�
 ���һ�ö����������ľ���һ������ô���ǶԳƵġ�*/
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
        // �������֮һΪ�գ�Ҳ���ǶԳƵ�
        if (A==NULL || B==NULL)
            return false;
        // �ߵ��������һ����Ϊ��
        if (A->val != B->val)
            return false;
        // ǰ�����
        return helper(A->left,B->right) && helper(A->right,B->left);
    }
};