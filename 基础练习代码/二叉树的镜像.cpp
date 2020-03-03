//¶þ²æÊ÷µÄ¾µÏñ
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
    template<typename T>
	void Swap(T& l, T& r){
		T tmp = l;
		l = r;
		r = tmp;
	}
    TreeNode* mirrorTree(TreeNode* root) {
    	if(!root) return NULL;
    	Swap(root->left, root->right);
    	root->left = mirrorTree(root->left);
    	root->right = mirrorTree(root->right);

    	return root;
    }
    
};