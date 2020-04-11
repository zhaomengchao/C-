/*
����һ�ö��������������ҳ����е�k��Ľڵ㡣
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

