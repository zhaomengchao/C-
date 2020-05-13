//给定一棵二叉搜索树，请找出其中第k大的节点。

//思路：二叉查找树中序遍历输出就是从小到大的有序序列
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
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        dfs(res,root);
        return res[k-1];
    }
    private:
    void dfs(vector<int>& tmp,TreeNode* r)
    {
        if(r == NULL)
        {
            return ;
        }
        dfs(tmp,r->right);
        tmp.push_back(r->val);
        dfs(tmp,r->left);

    }
};