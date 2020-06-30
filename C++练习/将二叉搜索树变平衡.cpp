/*
给你一棵二叉搜索树，请你返回一棵?平衡后?的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是?平衡的 。

*/
class Solution {
public:
    vector<int> inorderSeq;

    void getInorder(TreeNode* o) {
        if (o->left) getInorder(o->left);
        inorderSeq.push_back(o->val);
        if (o->right) getInorder(o->right);
    }

    TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode* o = new TreeNode(inorderSeq[mid]);
        if (l <= mid - 1) o->left = build(l, mid - 1);
        if (mid + 1 <= r) o->right = build(mid + 1, r);
        return o;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
};