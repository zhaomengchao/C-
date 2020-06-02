/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
https://leetcode-cn.com/problems/valid-palindrome/
*/
class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.empty())
        {
            return true;
        }

        vector<char> a;
        //�޳�
        for(int i=0;i<s.length();i++){
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')){
                a.push_back(s[i]);
            }
            if(s[i]>='A'&&s[i]<='Z'){
                a.push_back(s[i]-'A'+'a');
            }
        }
        int sta = 0;
        int end = a.size()-1;
        while(sta <= end)
        {
            
            if(a[sta] == a[end])
            {
                sta++;
                end--;
            }
            else
            {
                 return false;
            }
        }
        return true;
    }
};