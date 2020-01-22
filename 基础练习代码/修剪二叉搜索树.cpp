//����һ��������������ͬʱ������С�߽�L?�����߽�?R��
//ͨ���޼�������������ʹ�����нڵ��ֵ��[L, R]�� (R>=L) ��
//�������Ҫ�ı����ĸ��ڵ㣬���Խ��Ӧ�������޼��õĶ������������µĸ��ڵ㡣

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
        //��֦��������� 0 [1,2, 3,] 2 [1,2,3] 4 [1,2,3]
        // 0 [1,2,3] ,��֦����Ҫ�� root��Ҫ�ˣ�root=��֦
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
