/*
����һ����ȫ����������������Ľڵ������

˵����

��ȫ�������Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~?2h?���ڵ㡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-complete-tree-nodes
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
