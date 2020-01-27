//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";//存放结果
        string temp="";//存放子串
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                string tem=temp;//tem存放子串反转结果
                std::reverse(tem.begin(),tem.end());//反转
                if(temp==tem)
                    res=res.length()>temp.length()?res:temp;
            }
            temp="";
        }
        return res;
    }
};