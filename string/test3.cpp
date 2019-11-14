//判断括号的合法性
//例：合法括号只包括括号字符，并且一一对应
//（（））a（）
//不合法

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == '(')
            {
                count++;
            }
            else if(A[i] == ')')
            {
                count--;
            }
            else
            {
                return false;
            }
            if(count < 0)
            {
                return false;
            }
        }
        return true;
    }
};
