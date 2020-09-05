/*
题目描述
分别按照二叉树先序，中序和后序打印所有的节点。
示例1
输入

{1,2,3}
输出

[[1,2,3],[2,1,3],[2,3,1]]
*/
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
     void MLR(TreeNode* _root,vector<int> &a)
     {
         if(_root == NULL)
         {
             return;
         }
         a.push_back(_root->val);
         MLR(_root->left, a);
         MLR(_root->right,a);
     }
    void LMR(TreeNode* _root,vector<int>& a)
    {
        if(_root == NULL)
        {
            return;
        }
        LMR(_root->left,a);
         a.push_back(_root->val);
        LMR(_root->right, a);
    }
    void LRM(TreeNode* _root,vector<int> &a)
    {
        if(_root == NULL)
        {
            return ;
        }
        LRM(_root->left, a);
        LRM(_root->right, a);
         a.push_back(_root->val);
    }
    
    
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> vv;
        vector<int> v;
        TreeNode* tmp = root;
        
        v.clear();
        MLR(tmp,v);
        vv.push_back(v);
        v.clear();
        LMR(tmp, v);
        vv.push_back(v);
        v.clear();
        LRM(tmp, v);
        vv.push_back(v);
        v.clear();
        
         
        
        return vv;
        
    }
};