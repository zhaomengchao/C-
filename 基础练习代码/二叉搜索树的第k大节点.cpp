/*
给定一棵二叉搜索树，请找出其中第k大的节点。
*/
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> result;
        dfs(result, root);
        return result[k-1];
    }
    
private:
    void dfs(vector<int> &result, TreeNode *node) {
        if (node == nullptr) return;
        dfs(result, node->right);
        result.push_back(node->val);
        dfs(result, node->left);
    }
};

