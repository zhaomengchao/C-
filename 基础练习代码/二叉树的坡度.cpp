/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//给定一个二叉树，计算整个树的坡度。
//一个树的节点的坡度定义即为，该节点左子树的结点之和
//和右子树结点之和的差的绝对值。空结点的的坡度是0。
//整个树的坡度就是其所有节点的坡度之和。
 
 class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int res = 0;
        FindTiltCore(root, res);
        return res;
    }
    int FindTiltCore(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        int left = FindTiltCore(root->left, res);
        int right = FindTiltCore(root->right, res);
        res += abs(left - right);
        return left + right + root->val;
    }
};