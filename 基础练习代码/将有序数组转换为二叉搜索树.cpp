//��һ�������������е��������飬
//ת��Ϊһ�ø߶�ƽ�������������

//�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� 
//���������������ĸ߶Ȳ�ľ���ֵ������ 1��

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
        {
            return nullptr;
        }
        return binary_tree(nums,0,nums.size()-1);
    }
    TreeNode * binary_tree(vector<int>& nums,int left,int right)
    {
        if(left > right)
            return nullptr;
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = binary_tree(nums, left,mid -1);
        root->right = binary_tree(nums,mid+1, right);
        return root;
    }

};