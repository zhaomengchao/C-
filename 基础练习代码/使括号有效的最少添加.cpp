/*
����һ���� '(' �� ')' ������ɵ��ַ��� S��������Ҫ������ٵ����ţ� '(' ���� ')'���������κ�λ�ã�����ʹ�õ��������ַ�����Ч��
https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/
*/
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> temp;
        for(int i=0;i<S.size();i++)
        {
            if(temp.empty())
            {
                temp.push(S[i]);
            }
            else{
                if(S[i]==')'&&temp.top()=='(')
                {
                    temp.pop();
                }
                else{
                    temp.push(S[i]);
                }
            }
        }
        return temp.size();
    }
};
