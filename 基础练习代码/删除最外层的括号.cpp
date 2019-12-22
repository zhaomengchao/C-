//���룺"(()())(())"
//�����"()()()"
//���ͣ�
//�����ַ���Ϊ "(()())(())"��ԭ�ﻯ�ֽ�õ� "(()())" + "(())"��
//ɾ��ÿ�������е���������ź�õ� "()()" + "()" = "()()()"��

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