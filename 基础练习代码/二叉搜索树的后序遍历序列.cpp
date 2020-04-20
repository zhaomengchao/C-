/*�����������ĺ����������

����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
������򷵻� true�����򷵻� false��
�������������������������ֶ�������ͬ��
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
        //�����
        int root = postorder[end];

        //�ڶ������������������Ľ��С�ڸ����
        int i = start;
        for(;i<end;i++)
        {
            if (postorder[i] > root)
                break;
        }

        //�ڶ������������������Ľ����ڸ����
        for(int j = i;j<end;j++)
        {
            if (postorder[j] < root)
                return false;
        }

        //�ж��������ǲ��Ƕ���������
        bool left = true;
        if (i>start)
        {
            left = helper(postorder,start,i-1);
        }
        //�ж��������ǲ��Ƕ���������
        bool right = true;
        if (i<end-1)
        {
            right = helper(postorder, i,end-1);
        }
        return left &&  right;
    }
};

