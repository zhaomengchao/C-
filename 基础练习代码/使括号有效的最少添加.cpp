/*
给定一个由 '(' 和 ')' 括号组成的字符串 S，我们需要添加最少的括号（ '(' 或是 ')'，可以在任何位置），以使得到的括号字符串有效。
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
