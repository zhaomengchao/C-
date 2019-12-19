//���������������ĸ���� root������ L �� R������֮������н���ֵ�ĺ͡�
//������������֤����Ψһ��ֵ��
//ʾ�� 1��
//���룺root = [10,5,15,3,7,null,18], L = 7, R = 15
//�����32
//ʾ��?2��
//���룺root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
/�����23


//���������������Ľڵ㶼�ȸ��ڵ��С
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
        {
            return 0;
        }
        if(root->val < L)
        {
            return rangeSumBST(root->right,L,R);
        }
        if(root->val > R)
        {
            return rangeSumBST(root->left,L,R);
        }

        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R); 
        
        
        
    }
};