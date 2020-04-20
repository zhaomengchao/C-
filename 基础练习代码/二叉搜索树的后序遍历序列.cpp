/*二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。
假设输入的数组的任意两个数字都互不相同。
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        bool res = true;
        if (postorder.empty())
            return res;
        res = helper(postorder,0,postorder.size()-1);
        return res;
    }
    bool helper(vector<int>& postorder, int start, int end)
    {
        if (postorder.empty() || start > end)
            return true;
        //根结点
        int root = postorder[end];

        //在二叉搜索树中左子树的结点小于根结点
        int i = start;
        for(;i<end;i++)
        {
            if (postorder[i] > root)
                break;
        }

        //在二叉搜索书中右子树的结点大于根结点
        for(int j = i;j<end;j++)
        {
            if (postorder[j] < root)
                return false;
        }

        //判断左子树是不是二叉搜索树
        bool left = true;
        if (i>start)
        {
            left = helper(postorder,start,i-1);
        }
        //判断右子树是不是二叉搜索树
        bool right = true;
        if (i<end-1)
        {
            right = helper(postorder, i,end-1);
        }
        return left &&  right;
    }
};

