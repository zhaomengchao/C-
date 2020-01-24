//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        TreeNode* p,*last=root;
        double sum=0;
        int count=0;
        que.push(root);
        while(!que.empty())
        {
            p=que.front();
            sum+=(double)p->val;
            count++;
            que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
            if(p==last)
            {
                res.push_back(sum/(double)count);
                sum=count=0;
                last=que.back();
            }
        }
        return res;
    }
};
