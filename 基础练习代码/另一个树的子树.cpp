//树的子结构
/*给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
        {
            return false;
        }
        if(s->val == t->val)
        {
            if(isSameTree(s,t))
                return true;
        }
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool isSameTree(struct TreeNode* s, struct TreeNode* t)
    {
        if(s == NULL && t == NULL)
        {
            return true;
        }
        if(s == NULL || t == NULL)
        {
            return false;
        }
        if(s->val != t->val)
        {
            return false;
        }
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};