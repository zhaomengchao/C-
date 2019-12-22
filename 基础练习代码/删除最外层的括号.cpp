//输入："(()())(())"
//输出："()()()"
//解释：
//输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
//删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。

class Solution {
public:
    string removeOuterParentheses(string S) {
        string s1;
        int lcount = 1;
        int rcount = 0; 
        for(int i = 1; i < S.size(); i++)
        {
            if(S[i] == '(')
            {
                lcount++;
            }
            else
                rcount++;
            if(lcount != rcount)
            {
                s1.push_back(S[i]);
            }
            else
            {
                i++;
                lcount = 1;
                rcount = 0;
            }
        }
        return s1;    
    }
};